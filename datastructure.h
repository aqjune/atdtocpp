#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include<vector>
#include<map>
#include<string>
#include<iostream>
#include"printer.h"
using namespace std;


class Type{
public:

/*
  vector<string> *linearize(){
    vector<string> *t = new vector<string>();
    if(children.size() == 0){
      t->push_back(name);
    }else{
      for(Type *ty : children){
        vector<string> *tyv = ty->linearize();
        t->insert(t->end(), tyv->begin(), tyv->end());
        delete tyv;
      }
    }
    return t;
  }*/
  virtual void print(ostream &out, PrintConfig *cfg) = 0;
};

class NamedType : public Type{
public:
  string name;
  NamedType(){}
  NamedType(string _name):name(_name){}
  
  bool isReservedKeyword(){
    return name == "string" || name == "list" || name == "int" || name == "float" || name == "bool";
  }

  virtual void print(ostream &out, PrintConfig *cfg){
    out << name;
  }
};

class ProdType : public Type{
public:
  vector<Type *> children;
  void addChild(Type *t){
    children.push_back(t);
  }
  virtual void print(ostream &out, PrintConfig *cfg){
    out << "(";
    children[0]->print(out, cfg);
    for(int i = 1; i < children.size(); i++){
      out << " * ";
      children[i]->print(out, cfg);
    }
    out << ")";
  }
};

class ParameterizedType : public Type{
public:
  Type *arg;
  Type *ty;
  virtual void print(ostream &out, PrintConfig *cfg){
    arg->print(out, cfg);
    out << " ";
    ty->print(out, cfg);
  }
};

class Constructor{
public:
  string name;
  Type *argtype;
  Constructor(){
    argtype = nullptr;
  }

  void print(ostream &out, PrintConfig *cfg){
    out << name;
    if(argtype){
      out << " of ";
      argtype->print(out, cfg);
    }
  }
};

class Field{
public:
  string name;
  Type *type;

  void print(ostream &out, PrintConfig *cfg){
    printIndentation(out, 1, cfg);
    out << name << " : ";
    type->print(out, cfg);
  }
};

class TypeDec{
public:
  string name;
  pair<int, int> srcBegin;
  pair<int, int> srcEnd;

  virtual void print(ostream &out, PrintConfig *cfg) = 0;
};

class RecordTypeDec: public TypeDec{
public:
  vector<Field *> fields;
  void add(Field *f){
    fields.push_back(f);
  }
  void addAll(vector<Field *> *fp){
    fields = *fp;
  }

  virtual void print(ostream &out, PrintConfig *cfg){
    out << "type " << this->name << " = {" << endl;
    for(int i = 0; i < fields.size(); i++){
      printIndentation(out, 1, cfg);
      fields[i]->print(out, cfg);
      out << ";" << endl;
    }
    out << "}";
  }
};

class InductiveTypeDec: public TypeDec{
public:
  vector<Constructor *> cons;
  void addAll(vector<Constructor *> *vp){
    cons = *vp;
  }

  virtual void print(ostream &out, PrintConfig *cfg){
    out << "type " << this->name << " = [" << endl;
    for(int i = 0; i < cons.size(); i++){
      printIndentation(out, 1, cfg);
      out << "| ";
      cons[i]->print(out, cfg);
      out << endl;
    }
    printIndentation(out, 1, cfg);
    out << "] <ocaml repr=\"classic\">";
  }
};

class Scheme{
public:
  map<string, TypeDec*> decs;
  void addNewType(TypeDec *td){
    decs[td->name] = td;
  }

  void print(ostream &out, PrintConfig *cfg){
    for(auto itr = decs.begin(); itr != decs.end(); itr++){
      itr->second->print(out, cfg);
      cout << endl;
    }
  }
};

#endif
