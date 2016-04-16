#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include<vector>
#include<map>
#include<string>
#include<iostream>
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
  virtual void print() = 0;
};

class NamedType : public Type{
public:
  string name;
  NamedType(){}
  NamedType(string _name):name(_name){}
  
  bool isReservedKeyword(){
    return name == "string" || name == "list" || name == "int" || name == "float" || name == "bool";
  }

  virtual void print(){
    cout << name;
  }
};

class ProdType : public Type{
public:
  vector<Type *> children;
  void addChild(Type *t){
    children.push_back(t);
  }
  virtual void print(){
    cout << "(";
    children[0]->print();
    for(int i = 1; i < children.size(); i++){
      cout << ",";
      children[i]->print();
    }
    cout << ")";
  }
};

class ParameterizedType : public Type{
public:
  Type *arg;
  Type *ty;
  virtual void print(){
    arg->print();
    cout << " ";
    ty->print();
  }
};

class Constructor{
public:
  string name;
  Type *argtype;
  Constructor(){
    argtype = nullptr;
  }

  void print(){
    cout << name;
    if(argtype){
      cout << " : ";
      argtype->print();
    }
  }
};

class Field{
public:
  string name;
  Type *type;

  void print(){
    cout << name << " : ";
    type->print();
  }
};

class TypeDec{
public:
  string name;

  virtual void print() = 0;
};

class RecordTypeDec: public TypeDec{
public:
  vector<Field *> fields;
  void addAll(vector<Field *> *fp){
    fields = *fp;
  }

  virtual void print(){
    cout << "recordtype " << this->name << " = {" << endl;
    for(int i = 0; i < fields.size(); i++){
      fields[i]->print();
      cout << ";" << endl;
    }
    cout << "}";
  }
};

class InductiveTypeDec: public TypeDec{
public:
  vector<Constructor *> cons;
  void addAll(vector<Constructor *> *vp){
    cons = *vp;
  }

  virtual void print(){
    cout << "inductivetype " << this->name << " = [" << endl;
    for(int i = 0; i < cons.size(); i++){
      cout << "| ";
      cons[i]->print();
      cout << endl;
    }
    cout << "]";
  }
};

class Scheme{
public:
  map<string, TypeDec*> decs;
  void addNewType(TypeDec *td){
    decs[td->name] = td;
  }

  void print(){
    for(auto itr = decs.begin(); itr != decs.end(); itr++){
      itr->second->print();
      cout << endl;
    }
  }
};

#endif
