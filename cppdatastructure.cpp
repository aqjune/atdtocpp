#include "cppdatastructure.h"

static void printIndentation(ostream &out, int ac, PrintConfig *config){
  for(int i = 0; i < ac; i++)
    for(int j = 0; j < config->indentsize; j++)
      out << " ";
}
static void printAccessModifier(ostream &out, CppAccessModifier mod){
  switch(mod){
  case PUBLIC:
    out << "public";
    break;
  case PROTECTED:
    out << "protected";
    break;
  case PRIVATE:
    out << "private";
    break;
  }
}

CppVariable::CppVariable(string type, string name){
  this->name = name;
  this->type = type;
}

void CppVariable::print(ostream &fout){
  fout << this->type << " " << this->name;
}

CppConstructor::CppConstructor(){
  this->accmod = PUBLIC;
}

void CppConstructor::printDec(ostream &out, int indentation, PrintConfig *config, bool printAccMod){
  if(printAccMod){
    printIndentation(out, indentation - 1, config);
    printAccessModifier(out, this->accmod);
    out << ":" << endl;
  }
  printIndentation(out, indentation, config);
  out << parentClass->name;
  
  out << "(";
  for(int i = 0; i < this->args.size(); i++){
    if(i != 0)
      out << ", ";
    this->args[i]->print(out);
  }
  out << ")";

  out << ";";
}

void CppConstructor::printDef(ostream &out, int indentation, PrintConfig *config){
  printIndentation(out, indentation, config);
  out << this->parentClass->name << "::" << this->parentClass->name;

  out << "(";
  for(int i = 0; i < this->args.size(); i++){
    if(i != 0)
      out << ", ";
    this->args[i]->print(out);
  }
  out << ")";

  if(this->initializers.size() != 0){
    out << " : ";
    for(int i = 0; i < this->initializers.size(); i++){
      if(i != 0)
        out << ", ";
      out << this->initializers[i].first->name << "("
          << this->initializers[i].second << ")";
    }
  }

  out << "{";
  out << endl;

  for(int i = 0; i < this->instructions.size(); i++){
    printIndentation(out, indentation + 1, config);
    out << this->instructions[i] << ";";
    out << endl;
  }

  printIndentation(out, indentation, config);
  out << "}";
}


CppMethod::CppMethod(){
  this->isstatic = false;
  this->accmod = PUBLIC;
  this->isconst = false;
  this->ispurevirtual = false;
  this->parentClass = nullptr;
}

void CppMethod::printDec(ostream &out, int indentation, PrintConfig *config, bool printAccMod){
  if(printAccMod){
    printIndentation(out, indentation - 1, config);
    printAccessModifier(out, this->accmod);
    out << ":" << endl;
  }
  printIndentation(out, indentation, config);
  if(this->isstatic)
    out << "static ";
  if(this->ispurevirtual)
    out << "virtual ";
  out << this->returnType << " ";
  out << name;
  
  out << "(";
  for(int i = 0; i < this->args.size(); i++){
    if(i != 0)
      out << ", ";
    this->args[i]->print(out);
  }
  out << ")";

  if(this->isconst)
    out << " const";

  if(this->ispurevirtual)
    out << " = 0";

  out << ";";
}

bool CppMethod::printDef(ostream &out, int indentation, PrintConfig *config){
  if(this->ispurevirtual)
    return false;
  printIndentation(out, indentation, config);
  out << this->returnType << " " << this->parentClass->name << "::" << this->name;

  out << "(";
  for(int i = 0; i < this->args.size(); i++){
    if(i != 0)
      out << ", ";
    this->args[i]->print(out);
  }
  out << ")";
  if(this->isconst){
    out << " const";
  }
  out << "{";
  out << endl;

  for(int i = 0; i < this->instructions.size(); i++){
    printIndentation(out, indentation + 1, config);
    out << this->instructions[i] << ";";
    out << endl;
  }

  printIndentation(out, indentation, config);
  out << "}";
  return true;
}


CppField::CppField(){
  this->isstatic = false;
  this->accmod = PRIVATE;
}

void CppField::printDec(ostream &out, int indentation, PrintConfig *config, bool printAccMod){
  if(printAccMod){
    printIndentation(out, indentation - 1, config);
    printAccessModifier(out, this->accmod);
    out << ":" << endl;
  }
  printIndentation(out, indentation, config);
  if(this->isstatic)
    out << "static ";
  out << this->type << " ";
  out << name;
  
  out << ";";
}

static void classify(CppMember *m, vector<CppMember *> &publics, vector<CppMember *> &protecteds, 
                      vector<CppMember *> &privates){
  if(m->accmod == PUBLIC)
    publics.push_back(m);
  else if(m->accmod == PROTECTED)
    protecteds.push_back(m);
  else if(m->accmod == PRIVATE)
    privates.push_back(m);
}

void CppClass::printDec(ostream &out, int indentation, PrintConfig *config){
  vector<CppMember *> publics;
  vector<CppMember *> protecteds;
  vector<CppMember *> privates;

  for(int i = 0; i < constructors.size(); i++)
    classify(constructors[i],   publics, protecteds, privates);
  for(int i = 0; i < methods.size(); i++)
    classify(methods[i],        publics, protecteds, privates);
  for(int i = 0; i < fields.size(); i++)
    classify(fields[i],         publics, protecteds, privates);

  printIndentation(out, indentation, config);
  out << "struct " << this->name;
  if(this->parentname.length() > 0)
    out << " : public " << parentname;
  out << "{" << endl;

  bool printed = false;
  if(publics.size() > 0){
    printIndentation(out, indentation, config);
    out << "public : " << endl;
    for(int i = 0; i < publics.size(); i++){
      publics[i]->printDec(out, indentation + 1, config, false);
      printed = true;
      out << endl;
    }
  }

  if(protecteds.size() > 0){
    if(printed) out << endl;

    printIndentation(out, indentation, config);
    out << "protected : " << endl;
    for(int i = 0; i < protecteds.size(); i++){
      protecteds[i]->printDec(out, indentation + 1, config, false);
      printed = true;
      out << endl;
    }
  }

  if(privates.size() > 0){
    if(printed) out << endl;

    printIndentation(out, indentation, config);
    out << "private : " << endl;
    for(int i = 0; i < privates.size(); i++){
      privates[i]->printDec(out, indentation + 1, config, false);
      printed = true;
      out << endl;
    }
  }
  printIndentation(out, indentation, config);
  out << "};";
}

int CppClass::printDef(ostream &out, int indentation, PrintConfig *config){
  int printedelems = 0;
  for(int i = 0; i < this->constructors.size(); i++){
    this->constructors[i]->printDef(out, indentation, config);
    out << endl;
  }
  for(int i = 0; i < this->methods.size(); i++){
    bool printed = this->methods[i]->printDef(out, indentation, config);
    if(printed){
      printedelems++;
      out << endl;
    }
  }
  return printedelems;
}
