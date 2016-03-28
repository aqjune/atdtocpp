#include "convert.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

#define CONVERT_TYPENAME(n) (string("Ty") + convertToCamelCase(n.c_str()))

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
  m->args.push_back(new CppVariable("JSONOutputArchive&", "archive"));
  return m;
}

static CppMethod *newInductiveConsSerializeMethod(CppClass *parent, string cons_name){
  CppMethod *m = new CppMethod();
  m->accmod = PUBLIC;
  m->parentClass = parent;
  m->isstatic = false;
  m->isconst = true;
  m->returnType = "void";
  m->name = "serialize";
  m->ispurevirtual = false;
  
  m->args.push_back(new CppVariable("JSONOutputArchive&", "archive"));
  m->instructions.push_back("archive.makeArray()");
  m->instructions.push_back("archive.writeName()");
  m->instructions.push_back(string("archive.saveValue(\"") + cons_name + "\")");
  
  if(parent->fields.size() == 0){
    // do nothing!
  }else if(parent->fields.size() == 1){
    m->instructions.push_back(string("archive(CEREAL_NVP(") + parent->fields[0]->name + "))");
  }else{
    m->instructions.push_back("archive.startNode()");
    m->instructions.push_back("archive.makeArray()");
    for(int i = 0; i < parent->fields.size(); i++){
      m->instructions.push_back(string("archive(CEREAL_NVP(") + parent->fields[i]->name + "))");
    }
    m->instructions.push_back("archive.finishNode()");
  }
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
  
  m->args.push_back(new CppVariable("JSONOutputArchive&", "archive"));

  for(int i = 0; i < parent->fields.size(); i++){
    m->instructions.push_back(string("archive(CEREAL_NVP(") + parent->fields[i]->name + "))");
  }
  return m;
}




static string toUniquePtrType(const string &ty){
  return string("std::unique_ptr<") + ty + (ty.back() == '>' ? " " : "") + ">";
}
static string toVector(const string &ty){
  return string("std::vector<") + ty + (ty.back() == '>' ? " " : "") + ">";
}
static string toCppTypeName(const string &atdtype){
  if(atdtype == "string"){
    return "std::string";
  }else if(atdtype == "int"){
    return "int";
  }else if(atdtype == "float"){
    return "double";
  }
  return toUniquePtrType(convertToCamelCase(atdtype.c_str()));
}
 
static string applyMoveFunction(const string &val){
  return string("std::move(") + val + ")";
}

static void emitError(Type *t){
  cerr << "we do not support conversion of this type : ";
  t->print();
  assert(false);
}

vector<CppField *> newConsClassFields(Type *t, vector<CppField *> &fieldsForConstructor){
  vector<CppField *> v;
  
  if(NamedType *nd = dynamic_cast<NamedType *>(t)){
    CppField *cf = new CppField();
    cf->type = toCppTypeName(nd->name);
    cf->accmod = PRIVATE;
    cf->isstatic = false;

    if(nd->isReservedKeyword()){
      cf->name = std::string("a");
      cf->name[0] = cf->type[0];
    }else{
      cf->name = nd->name;
    }
    v.push_back(cf);
  }else if(ProdType *pt = dynamic_cast<ProdType *>(t)){
    for(int i = 0; i < pt->children.size(); i++){
      if(!dynamic_cast<NamedType *>(pt->children[i])){
        emitError(t);
      }
      v.push_back(newConsClassFields(pt->children[i], fieldsForConstructor)[0]);
    }
  }else if(ParameterizedType *pt = dynamic_cast<ParameterizedType *>(t)){
    NamedType *pnd = dynamic_cast<NamedType *>(pt->ty);
    if(!pnd){
      emitError(t);
    }else if(pnd->name != "list"){
      emitError(t);
    }
    v = newConsClassFields(pnd, fieldsForConstructor);
    if(v.size() == 1){
      v[0]->type = toVector(v[0]->type);
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
    CppVariable *vv = new CppVariable(fieldsForConstructor[i]->type, string("_") + fieldsForConstructor[i]->name);
    cc->args.push_back(vv);
    cc->initializers.push_back(make_pair(fieldsForConstructor[i], applyMoveFunction(vv->name)));
  }
  return cc;
}
CppConstructor *newRecordTyConstructor(CppClass *cclass, vector<CppField *> &fieldsForConstructor){
  CppConstructor *cc = new CppConstructor();
  cc->parentClass = cclass;
  for(int i = 0; i < fieldsForConstructor.size(); i++){
    CppVariable *vv = new CppVariable(fieldsForConstructor[i]->type, string("_") + fieldsForConstructor[i]->name);
    cc->args.push_back(vv);
    cc->initializers.push_back(make_pair(fieldsForConstructor[i], applyMoveFunction(vv->name)));
  }
  return cc;
}

vector<CppField *> newRecordTyClassFields(const vector<Field *> &vec, vector<CppField *> &fieldsForConstructor){
  for(int i = 0; i < vec.size(); i++){
    CppField *cf = new CppField();
    cf->accmod = PRIVATE;
    cf->name = vec[i]->name;

    Type *t = vec[i]->type;
    if(NamedType *nt = dynamic_cast<NamedType *>(t)){
      cf->type = toCppTypeName(nt->name); 
    }else if(ProdType *pt = dynamic_cast<ProdType *>(t)){
      if(pt->children.size() > 2){
        emitError(t);
      }
      string tyname = "std::pair<";
      for(int i = 0; i < pt->children.size(); i++){
        NamedType *nt = dynamic_cast<NamedType *>(pt->children[i]);
        if(!nt){
          emitError(t);
        }
        if(i != 0)
          tyname = tyname + ", ";
        tyname = tyname + toCppTypeName(nt->name);
      }
      tyname = tyname + ">";
      cf->type = tyname;
    }else if(ParameterizedType *pt = dynamic_cast<ParameterizedType *>(t)){
      NamedType *pnt = dynamic_cast<NamedType *>(pt->ty);
      NamedType *argnt = dynamic_cast<NamedType *>(pt->arg);
      if(!pnt || !argnt){
        emitError(t);
      }else if(pnt->name != "list"){
        emitError(t);
      }
      string tyname = string("std::vector<") + toCppTypeName(argnt->name) + ">";
      cf->type = tyname;
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
  m->isconst = true;
  m->returnType = toUniquePtrType(tyclass->name);;
  m->name = "make";
  m->ispurevirtual = false;
  
  if(makeMethod_doRedirect(scheme, atd_cons)){
    string the_type = dynamic_cast<NamedType *>(atd_cons->argtype)->name;
    assert(classes_from_type.find(the_type) != classes_from_type.end());

    CppClass *argclass = classes_from_type[the_type];
    
    CppConstructor *cppcons = argclass->constructors[0];
    m->args = cppcons->args;

    string instr = string("std::unique_ptr<") + argclass->name + "> _val(new " + argclass->name
                        + "(";
    for(int i = 0; i < m->args.size(); i++){
      if(i != 0)
        instr = instr + ", ";
      instr = instr + applyMoveFunction(m->args[i]->name);
    }
    instr = instr + "));";

    string retinstr = string("return std::unique_ptr<") + consclass->parentname + ">("
        + consclass->name + "(" + applyMoveFunction("_val") + ")" + ");";
    
    m->instructions.push_back(instr);
    m->instructions.push_back(retinstr);
  }else{
    delete m;
    return nullptr;
  }
  return m;
}


void convertTypeDec(Scheme *scheme, TypeDec *td, 
                map<string, CppClass *> &classes_from_type, 
                vector<CppClass *> &classes_from_cons);



void convertTypesRecursively(Scheme *scheme, Type *t, map<string, CppClass *> &classes_from_type,
                vector<CppClass *> &classes_from_cons){
  if(NamedType *nt = dynamic_cast<NamedType *>(t)){
    if(nt->isReservedKeyword()) return;
    assert(scheme->decs.find(nt->name) != scheme->decs.end());
    cout << "convertTypesRecursively : calling convertTypeDec(" << nt->name << ").." << endl;
    convertTypeDec(scheme, scheme->decs[nt->name], classes_from_type, classes_from_cons);
  }else if(ProdType *pt = dynamic_cast<ProdType *>(t)){
    for(int i = 0; i < pt->children.size(); i++){
      convertTypesRecursively(scheme, pt->children[i], classes_from_type, classes_from_cons);
    }
  }else if(ParameterizedType *pt = dynamic_cast<ParameterizedType *>(t)){
    convertTypesRecursively(scheme, pt->arg, classes_from_type, classes_from_cons);
  }
}

void convertInductiveTypeDec(Scheme *scheme, InductiveTypeDec *itd, 
                map<string, CppClass *> &classes_from_type,
                vector<CppClass *> &classes_from_cons){
  string cname = CONVERT_TYPENAME(itd->name);
  CppClass *tycc = new CppClass();
  tycc->name = cname;
  tycc->methods.push_back(newVirtualSerializeMethod(tycc));
  classes_from_type[itd->name] = tycc;
  cout << "Converting " << itd->name << " to " << cname << ".." << endl;
  
  for(auto itr = itd->cons.begin(); itr != itd->cons.end(); itr++){
    Constructor *atd_cons = *itr;
    string ccname = std::string("Cons") + convertToCamelCase(atd_cons->name.c_str());
    
    CppClass *conscc = new CppClass();
    vector<CppField *> fieldsForConstructor;
    conscc->name = ccname;
    conscc->parentname = cname;
    conscc->fields = newConsClassFields(atd_cons->argtype, fieldsForConstructor);
    conscc->constructors.push_back(newInductiveConsConstructor(conscc, fieldsForConstructor));

    if(makeMethod_doRedirect(scheme, atd_cons)){
      convertTypesRecursively(scheme, atd_cons->argtype, classes_from_type, classes_from_cons);
    }
    if(CppMethod *makeMethod = newConsMakeMethod(conscc, tycc, atd_cons, scheme, fieldsForConstructor, classes_from_type)){
      conscc->methods.push_back(makeMethod);
    }
    conscc->methods.push_back(newInductiveConsSerializeMethod(conscc, atd_cons->name));
    
    classes_from_cons.push_back(conscc);
  }
}

void convertRecordTypeDec(Scheme *scheme, RecordTypeDec *rtd,
                map<string, CppClass *> &classes_from_type,
                vector<CppClass *> &classes_from_cons){
  string cname = CONVERT_TYPENAME(rtd->name);
  CppClass *tycc = new CppClass();
  tycc->name = cname;
  cout << "Converting " << rtd->name << " to " << cname << ".." << endl;
  
  vector<CppField *> fieldsForConstructor;
  tycc->fields = newRecordTyClassFields(rtd->fields, fieldsForConstructor);

  tycc->constructors.push_back(newRecordTyConstructor(tycc, fieldsForConstructor));
  tycc->methods.push_back(newRecordTySerializeMethod(tycc));
  
  classes_from_type[rtd->name] = tycc;
}

void convertTypeDec(Scheme *scheme, TypeDec *td, 
                map<string, CppClass *> &classes_from_type, 
                vector<CppClass *> &classes_from_cons){
  if(classes_from_type.find(td->name) != classes_from_type.end())
    return;
  if(InductiveTypeDec *itd = dynamic_cast<InductiveTypeDec *>(td)){
    convertInductiveTypeDec(scheme, itd, classes_from_type, classes_from_cons);
  }else if(RecordTypeDec *rtd = dynamic_cast<RecordTypeDec *>(td)){
    convertRecordTypeDec(scheme, rtd, classes_from_type, classes_from_cons); 
  }
}

void convert(Scheme *scm, const char *cppout, const char *hppout){
  ofstream cppfout(cppout);
  ofstream hppfout(hppout);

  map<string, CppClass *> classes_from_type;
  vector<CppClass *> classes_from_cons;

  for(auto itr = scm->decs.begin(); itr != scm->decs.end(); itr++){
    convertTypeDec(scm, itr->second, classes_from_type, classes_from_cons);
  }
  
  PrintConfig pc;
  pc.indentsize = 2;
  for(auto itr = classes_from_type.begin(); itr != classes_from_type.end(); itr++){
    (itr->second)->printDec(hppfout, 0, &pc);
    hppfout << endl;
    int printedelems = (itr->second)->printDef(cppfout, 0, &pc);
    if(printedelems) cppfout << endl;
  }
  for(auto itr = classes_from_cons.begin(); itr != classes_from_cons.end(); itr++){
    (*itr)->printDec(hppfout, 0, &pc);
    hppfout << endl;
    int printedelems = (*itr)->printDef(cppfout, 0, &pc);
    if(printedelems) cppfout << endl;
  }

  cppfout.close();
  hppfout.close();
}


