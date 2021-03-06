#include "convert.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

#define CONVERT_TYPENAME(n) (string("Ty") + convertToCamelCase(n.c_str()))

class ClassDecs {
public:
  map<string, CppClass *> classes_from_type; // ATD type definition -> C++ class
  map<string, CppClass *> classes_from_cons; // ATD constructor -> C++ class
  map<string, InductiveTypeDec *> inductive_decs;
  map<string, RecordTypeDec *> record_decs;

  InductiveTypeDec *getIndTyDecFromCppClass(string cppclassname){
    bool found = false;
    std::string indtyname = "";
    for(auto itr = classes_from_type.begin(); itr != classes_from_type.end(); itr++){
      if(itr->second->name == cppclassname){
        indtyname = itr->first;
        found = true;
        break;
      }
    }
    if(!found)
      return nullptr;
    if(inductive_decs.find(indtyname) == inductive_decs.end())
      return nullptr;
    return inductive_decs[indtyname];
  }
};

static string convertPrime(const char *c){
  vector<char> ss;
  const char *p = c;
  while(*p){
    if(*p == '\''){
      ss.push_back('p');
      ss.push_back('r');
      ss.push_back('i');
      ss.push_back('m');
      ss.push_back('e');
    }else
      ss.push_back(*p);
    p++;
  }
  return string(ss.begin(), ss.end());
}
static string convertToCamelCase(const char *c){
  vector<char> ss;
  const char *p = c;
  while(*p){
    bool doCapitalize = false;
    if(!ss.empty() && ss.back() == '_'){
      doCapitalize = true;
      ss[ss.size() - 1] = *p;
    }else{
      if(ss.empty()) doCapitalize = true;
      ss.push_back(*p);
    }
    if(*p == '\''){
      ss[ss.size() - 1] = 'p';
    }
    if(doCapitalize){
      if('a' <= *p && *p <= 'z'){
        ss[ss.size() - 1] -= 'a';
        ss[ss.size() - 1] += 'A';
      }
    }
    if(*p == '\''){
      ss.push_back('r');
      ss.push_back('i');
      ss.push_back('m');
      ss.push_back('e');
    }

    p++;
  }
  return string(ss.begin(), ss.end());
}

static CppMethod *newVirtualSerializeMethod(CppClass *parent){
  CppMethod *m = new CppMethod();
  m->accmod = PUBLIC;
  m->parentClass = parent;
  m->isstatic = false;
  m->isconst = true;
  m->returnType = "void";
  m->name = "serialize";
  m->ispurevirtual = true;
  m->args.push_back(new CppVariable("cereal::JSONOutputArchive&", "archive"));
  return m;
}

static CppMethod *newInductiveConsSerializeMethod(CppClass *parent, string cons_name, ClassDecs &cdecs){
  CppMethod *m = new CppMethod();
  m->accmod = PUBLIC;
  m->parentClass = parent;
  m->isstatic = false;
  m->isconst = true;
  m->returnType = "void";
  m->name = "serialize";
  m->ispurevirtual = false;

#define ADDINST(str) m->instructions.push_back(str)
  m->args.push_back(new CppVariable("cereal::JSONOutputArchive&", "archive"));
  ADDINST("archive.makeArray();");
  ADDINST("archive.writeName();");
  ADDINST(string("archive.saveValue(\"") + cons_name + "\");");
  
  if(parent->fields.size() == 0){
    // do nothing!
  }else{ 
    if(parent->fields.size() > 1){
      ADDINST("archive.startNode();");
      ADDINST("archive.makeArray();");
    }
    for(int i = 0; i < parent->fields.size(); i++){
      string fieldname = parent->fields[i]->name;
      CppType *fty = parent->fields[i]->type;
      string ftyname = fty->name;
      InductiveTypeDec *itdec;
      if(CppType::IsSharedPtrTy(fty) &&
          (itdec = cdecs.getIndTyDecFromCppClass(fty->templateArgs[0]->name))){
        vector<Constructor *> consWithNoArg;
        for(auto itr = itdec->cons.begin(); itr != itdec->cons.end(); itr++){
          if((*itr)->argtype == nullptr){
            consWithNoArg.push_back(*itr);
          }
        }
        if(consWithNoArg.empty())
          ADDINST(string("archive(CEREAL_NVP(") + fieldname + "));");
        else{
          bool first = true;
          for(auto itr = consWithNoArg.begin(); itr != consWithNoArg.end(); itr++){
            string consname = (*itr)->name;
            string cppclassname = cdecs.classes_from_cons[consname]->name;

            string castingexpr = string("auto p = std::dynamic_pointer_cast<") + cppclassname + ">(" + fieldname + ")";
            if(first){
              ADDINST(string("if (" + castingexpr + ") {"));
            }else{
              ADDINST(string("} else if (" + castingexpr + ") {"));
            }
            ADDINST("  archive.writeName();");
            ADDINST(string("  archive.saveValue(\"") + consname + "\");");
            first = false;
          }
          ADDINST("} else {");
          ADDINST(string("  archive(CEREAL_NVP(") + fieldname + "));");
          ADDINST("}");
        }
      }else if(CppType::IsVectorTy(parent->fields[i]->type)){
        ADDINST(string("archive.startNode();"));
        ADDINST(string("archive.makeArray();"));
        ADDINST(string("archive(CEREAL_NVP(") + fieldname + "));");
        ADDINST(string("archive.finishNode();"));
      }else{
        ADDINST(string("archive(CEREAL_NVP(") + fieldname + "));");
      }
    }
    if(parent->fields.size() > 1){
      ADDINST("archive.finishNode();");
    }
  }
#undef ADDINST
  return m;
}

static CppMethod *newRecordTySerializeMethod(CppClass *parent){
  CppMethod *m = new CppMethod();
  m->accmod = PUBLIC;
  m->parentClass = parent;
  m->isstatic = false;
  m->isconst = true;
  m->returnType = "void";
  m->name = "serialize";
  m->ispurevirtual = false;
  
  m->args.push_back(new CppVariable("cereal::JSONOutputArchive&", "archive"));
  string archivecmd = "archive(";

  for(int i = 0; i < parent->fields.size(); i++){
    if(i != 0)
      archivecmd = archivecmd + ", ";
    archivecmd = archivecmd + "CEREAL_NVP(" + parent->fields[i]->name + ")";
  }
  archivecmd = archivecmd + ");";
  m->instructions.push_back(archivecmd);
  return m;
}




static CppType *toSharedPtrType(const string &ty){
  CppType *ct = new CppType("std::shared_ptr");
  ct->templateArgs.push_back(new CppType(ty));
  return ct;
}
static CppType *toVector(const string &ty){
  CppType *ct = new CppType("std::vector");
  ct->templateArgs.push_back(new CppType(ty));
  return ct;
}
static CppType *toCppType(map<string, CppClass *> &classes_from_type, const string &atdtype){
  if(atdtype == "string"){
    return new CppType("std::string");
  }else if(atdtype == "int"){
    return new CppType("int");
  }else if(atdtype == "float"){
    return new CppType("double");
  }else if(atdtype == "bool"){
    return new CppType("bool");
  }
  assert(classes_from_type.find(atdtype) != classes_from_type.end());
  return toSharedPtrType(classes_from_type[atdtype]->name);
}
 
static void emitError(Type *t){
  cerr << "ERROR : we do not support conversion of this type : ";
  t->print(cerr, &PrintConfig::DEFAULT_PRINT_CONFIG);
  cerr << endl;
  assert(false);
}

vector<CppField *> newConsClassFields(Type *t, vector<CppField *> &fieldsForConstructor, map<string, CppClass *> &classes_from_type){
  vector<CppField *> v;
  
  if(NamedType *nd = dynamic_cast<NamedType *>(t)){
    CppField *cf = new CppField();
    cf->type = toCppType(classes_from_type, nd->name);
    cf->accmod = PRIVATE;
    cf->isstatic = false;

    if(nd->isReservedKeyword()){
      cf->name = std::string("a");
      cf->name[0] = cf->type->toString()[0];
    }else{
      cf->name = nd->name;
    }
    v.push_back(cf);
  }else if(ProdType *pt = dynamic_cast<ProdType *>(t)){
    for(int i = 0; i < pt->children.size(); i++){
      if(!dynamic_cast<NamedType *>(pt->children[i]) && !dynamic_cast<ParameterizedType *>(pt->children[i])){
        emitError(t);
      }
      v.push_back(newConsClassFields(pt->children[i], fieldsForConstructor, classes_from_type)[0]);
    }
  }else if(ParameterizedType *pt = dynamic_cast<ParameterizedType *>(t)){
    NamedType *pnd = dynamic_cast<NamedType *>(pt->ty);
    if(!pnd){
      emitError(t);
    }else if(pnd->name != "list"){
      emitError(t);
    }
    v = newConsClassFields(pt->arg, fieldsForConstructor, classes_from_type);
    if(v.size() == 1){
      v[0]->type = toVector(v[0]->type->toString());
      v[0]->name = "vec_" + v[0]->name;
    }else{
      emitError(t);
    }
  }
  fieldsForConstructor.clear();
  fieldsForConstructor.insert(fieldsForConstructor.begin(), v.begin(), v.end());
  return v;
}
CppConstructor *newInductiveConsConstructor(CppClass *cclass, vector<CppField *> &fieldsForConstructor){
  CppConstructor *cc = new CppConstructor();
  cc->parentClass = cclass;
  for(int i = 0; i < fieldsForConstructor.size(); i++){
    CppVariable *vv = new CppVariable(fieldsForConstructor[i]->type->toString(), string("_") + fieldsForConstructor[i]->name);
    cc->args.push_back(vv);
    cc->initializers.push_back(make_pair(fieldsForConstructor[i], vv->name));
  }
  return cc;
}
CppConstructor *newRecordTyConstructor(CppClass *cclass, vector<CppField *> &fieldsForConstructor){
  CppConstructor *cc = new CppConstructor();
  cc->parentClass = cclass;
  for(int i = 0; i < fieldsForConstructor.size(); i++){
    CppVariable *vv = new CppVariable(fieldsForConstructor[i]->type->toString(), string("_") + fieldsForConstructor[i]->name);
    cc->args.push_back(vv);
    cc->initializers.push_back(make_pair(fieldsForConstructor[i], vv->name));
  }
  return cc;
}

vector<CppField *> newRecordTyClassFields(const vector<Field *> &vec, vector<CppField *> &fieldsForConstructor, map<string, CppClass *> &classes_from_type){
  for(int i = 0; i < vec.size(); i++){
    CppField *cf = new CppField();
    cf->accmod = PRIVATE;
    cf->name = convertPrime(vec[i]->name.c_str());

    Type *t = vec[i]->type;
    if(NamedType *nt = dynamic_cast<NamedType *>(t)){
      cf->type = toCppType(classes_from_type, nt->name); 
    }else if(ProdType *pt = dynamic_cast<ProdType *>(t)){
      if(pt->children.size() > 2){
        emitError(t);
      }
      vector<CppType *> templateargs;
      for(int i = 0; i < pt->children.size(); i++){
        NamedType *nt = dynamic_cast<NamedType *>(pt->children[i]);
        if(!nt){
          emitError(t);
        }
        templateargs.push_back(toCppType(classes_from_type, nt->name));
      }
      cf->type = new CppType("std::pair", templateargs);
    }else if(ParameterizedType *pt = dynamic_cast<ParameterizedType *>(t)){
      NamedType *pnt = dynamic_cast<NamedType *>(pt->ty);
      if(!pnt || pnt->name != "list"){
        emitError(t);
      }
      
      ProdType *argpt = dynamic_cast<ProdType *>(pt->arg);
      NamedType *argpt_typ1 = nullptr, *argpt_typ2 = nullptr;
      NamedType *argnt = dynamic_cast<NamedType *>(pt->arg);
      if(!argpt && !argnt){
        emitError(t);
      }else if(argpt){
        if(argpt->children.size() != 2){
          emitError(t);
        }
        argpt_typ1 = dynamic_cast<NamedType *>(argpt->children[0]);
        argpt_typ2 = dynamic_cast<NamedType *>(argpt->children[1]);
        if(!argpt_typ1 || !argpt_typ2){
          emitError(t);
        }
      }
      vector<CppType *> templateargs;
      if(argnt){
        templateargs.push_back(toCppType(classes_from_type, argnt->name));
      }else if(argpt){
        vector<CppType *> pairtemplateargs;
        pairtemplateargs.push_back(toCppType(classes_from_type, argpt_typ1->name));
        pairtemplateargs.push_back(toCppType(classes_from_type, argpt_typ2->name));
        templateargs.push_back(new CppType("std::pair", pairtemplateargs));
      }else{
        assert(argnt != nullptr || argpt != nullptr);
      }
      cf->type = new CppType("std::vector", templateargs);
    }
    fieldsForConstructor.push_back(cf);
  }
  return fieldsForConstructor;
}

bool makeMethod_doRedirect(Scheme *scheme, Constructor *atd_cons){
  NamedType *nt = dynamic_cast<NamedType *>(atd_cons->argtype);
  if(!nt) return false;
  else if(nt->isReservedKeyword()) return false;
  
  assert(scheme->decs.find(nt->name) != scheme->decs.end());
  TypeDec *td = scheme->decs[nt->name];
  if(RecordTypeDec *rtd = dynamic_cast<RecordTypeDec *>(td))
    return true;
  return false;
}

CppMethod *newConsMakeMethod(CppClass *consclass, CppClass *tyclass, Constructor *atd_cons,
                Scheme *scheme,
                vector<CppField *> &fieldsForConstructor,
                map<string, CppClass *> &classes_from_type){
  assert(consclass->parentname == tyclass->name);

  CppMethod *m = new CppMethod();
  m->accmod = PUBLIC;
  m->parentClass = consclass;
  m->isstatic = true;
  m->isconst = false;
  m->returnType = toSharedPtrType(tyclass->name)->toString();
  m->name = "make";
  m->ispurevirtual = false;
  
  if(makeMethod_doRedirect(scheme, atd_cons)){
    string the_type = dynamic_cast<NamedType *>(atd_cons->argtype)->name;
    assert(classes_from_type.find(the_type) != classes_from_type.end());

    CppClass *argclass = classes_from_type[the_type];
    
    CppConstructor *cppcons = argclass->constructors[0];
    m->args = cppcons->args;

    string instr = toSharedPtrType(argclass->name)->toString() + " _val(new " + argclass->name
                        + "(";
    for(int i = 0; i < m->args.size(); i++){
      if(i != 0)
        instr = instr + ", ";
      instr = instr + /*applyMoveFunction(*/m->args[i]->name/*)*/;
    }
    instr = instr + "));";

    string retinstr = string("return std::shared_ptr<") + consclass->parentname + ">(new "
        + consclass->name + "(" + /*applyMoveFunction(*/"_val"/*)*/ + ")" + ");";
    
    m->instructions.push_back(instr);
    m->instructions.push_back(retinstr);
  }else{
    delete m;
    return nullptr;
  }
  return m;
}


void convertTypeDec(Scheme *scheme, TypeDec *td, ClassDecs &cdecs);



void convertTypesRecursively(Scheme *scheme, Type *t, ClassDecs &cdecs){
  if(NamedType *nt = dynamic_cast<NamedType *>(t)){
    if(nt->isReservedKeyword()) return;
    assert(scheme->decs.find(nt->name) != scheme->decs.end());
    //cout << "convertTypesRecursively : calling convertTypeDec(" << nt->name << ").." << endl;
    convertTypeDec(scheme, scheme->decs[nt->name], cdecs);
  }else if(ProdType *pt = dynamic_cast<ProdType *>(t)){
    for(int i = 0; i < pt->children.size(); i++){
      convertTypesRecursively(scheme, pt->children[i], cdecs);
    }
  }else if(ParameterizedType *pt = dynamic_cast<ParameterizedType *>(t)){
    convertTypesRecursively(scheme, pt->arg, cdecs);
  }
}

void convertInductiveTypeDec(Scheme *scheme, InductiveTypeDec *itd, ClassDecs &cdecs){
  string cname = CONVERT_TYPENAME(itd->name);
  CppClass *tycc = new CppClass();
  tycc->name = cname;
  tycc->methods.push_back(newVirtualSerializeMethod(tycc));
  cdecs.classes_from_type[itd->name] = tycc;
  //cout << "Converting " << itd->name << " to " << cname << ".." << endl;
  
  for(auto itr = itd->cons.begin(); itr != itd->cons.end(); itr++){
    Constructor *atd_cons = *itr;
    string ccname = std::string("Cons") + convertToCamelCase(atd_cons->name.c_str());
    
    CppClass *conscc = new CppClass();
    vector<CppField *> fieldsForConstructor;
    conscc->name = ccname;
    conscc->parentname = cname;
    
    convertTypesRecursively(scheme, atd_cons->argtype, cdecs);
    conscc->fields = newConsClassFields(atd_cons->argtype, fieldsForConstructor, cdecs.classes_from_type);
    conscc->constructors.push_back(newInductiveConsConstructor(conscc, fieldsForConstructor));

    if(CppMethod *makeMethod = newConsMakeMethod(conscc, tycc, atd_cons, scheme, 
        fieldsForConstructor, cdecs.classes_from_type)){
      conscc->methods.push_back(makeMethod);
    }
    conscc->methods.push_back(newInductiveConsSerializeMethod(conscc, atd_cons->name, cdecs));
    
    cdecs.classes_from_cons[atd_cons->name] = conscc;
  }
}

void convertRecordTypeDec(Scheme *scheme, RecordTypeDec *rtd, ClassDecs &cdecs){
  string cname = CONVERT_TYPENAME(rtd->name);
  CppClass *tycc = new CppClass();
  tycc->name = cname;
  cdecs.classes_from_type[rtd->name] = tycc;
  //cout << "Converting " << rtd->name << " to " << cname << ".." << endl;
  
  for(int i = 0; i < rtd->fields.size(); i++)
    convertTypesRecursively(scheme, rtd->fields[i]->type, cdecs);
  vector<CppField *> fieldsForConstructor;
  tycc->fields = newRecordTyClassFields(rtd->fields, fieldsForConstructor, 
      cdecs.classes_from_type);

  tycc->constructors.push_back(newRecordTyConstructor(tycc, fieldsForConstructor));
  tycc->methods.push_back(newRecordTySerializeMethod(tycc));
}

void convertTypeDec(Scheme *scheme, TypeDec *td, ClassDecs &cdecs){
  if(cdecs.classes_from_type.find(td->name) != cdecs.classes_from_type.end())
    return;
  if(InductiveTypeDec *itd = dynamic_cast<InductiveTypeDec *>(td)){
    cdecs.inductive_decs[td->name] = itd;
    convertInductiveTypeDec(scheme, itd, cdecs);
  }else if(RecordTypeDec *rtd = dynamic_cast<RecordTypeDec *>(td)){
    cdecs.record_decs[td->name] = rtd;
    convertRecordTypeDec(scheme, rtd, cdecs); 
  }
}

void convert(Scheme *scm, const char *cppout, const char *hppout, vector<string> *printlist){
  ofstream cppfout(cppout);
  ofstream hppfout(hppout);
  
  ClassDecs cdecs;

  for(auto itr = scm->decs.begin(); itr != scm->decs.end(); itr++){
    convertTypeDec(scm, itr->second, cdecs);
  }
  
  PrintConfig pc;
  pc.indentsize = 2;
  for(auto itr = cdecs.classes_from_type.begin(); itr != cdecs.classes_from_type.end(); itr++){
    if(printlist && printlist->end() == std::find(printlist->begin(), printlist->end(), itr->second->name))
      continue;
    (itr->second)->printDec(hppfout, 0, &pc);
    hppfout << endl << endl;
    int printedelems = (itr->second)->printDef(cppfout, 0, &pc);
    if(printedelems) cppfout << endl;
  }
  for(auto itr = cdecs.classes_from_cons.begin(); itr != cdecs.classes_from_cons.end(); itr++){
    if(printlist && printlist->end() == std::find(printlist->begin(), printlist->end(), itr->second->name))
      continue;
    (itr->second)->printDec(hppfout, 0, &pc);
    hppfout << endl << endl;
    int printedelems = (itr->second)->printDef(cppfout, 0, &pc);
    if(printedelems) cppfout << endl;
  }

  cppfout.close();
  hppfout.close();
}


