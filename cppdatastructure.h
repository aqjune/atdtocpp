#ifndef CPPDATASTRUCTURE_H
#define CPPDATASTRUCTURE_H

#include<string>
#include<vector>
#include<iostream>
#include"printer.h"
using namespace std;

enum CppAccessModifier{
  PUBLIC, PROTECTED, PRIVATE
};

class CppVariable{
public:
  string name;
  string type;

  CppVariable(string type, string name);
  void print(ostream &out);
};

class CppClass;

class CppType{
public:
  static bool IsVectorTy(CppType *ct);
  static bool IsSharedPtrTy(CppType *ct);
  string name;
  vector<CppType *> templateArgs;

  CppType(string name);
  CppType(string name, vector<CppType *> &args);
  
  string toString();
};

class CppMember{
public:
  CppAccessModifier accmod;
public:
  virtual void printDec(ostream &out, int indentation, PrintConfig *config, bool printAccMod) = 0;
};

class CppField : public CppMember{
public:
  bool isstatic;
  CppType *type;
  string name;
 
  CppField();

  void printDec(ostream &out, int indentation, PrintConfig *config, bool printAccMod);
};

class CppConstructor : public CppMember{
public:
  CppClass *parentClass;
  vector<CppVariable*> args;
  vector<pair<CppField *, string> > initializers;
  vector<string> instructions;

  CppConstructor();

  void printDec(ostream &hppout, int indentation, PrintConfig *config, bool printAccMod);
  void printDef(ostream &cppout, int indentation, PrintConfig *config);
};

class CppMethod : public CppMember{
public:
  bool isstatic;
  bool isconst;
  bool ispurevirtual;
  CppClass *parentClass;
  string returnType;
  string name;
  vector<CppVariable *> args;
  vector<string> instructions;
  
  CppMethod();

  void printDec(ostream &out, int indentation, PrintConfig *config, bool printAccMod);
  bool printDef(ostream &out, int indentation, PrintConfig *config);
};


class CppClass{
public:
  string name;
  string parentname;
  vector<CppConstructor *> constructors;
  vector<CppMethod *> methods;
  vector<CppField *> fields;

  void printDec(ostream &out, int indentation, PrintConfig *config);
  int printDef(ostream &out, int indentation, PrintConfig *config);
};

#endif
