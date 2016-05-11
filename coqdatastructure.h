#ifndef COQDATASTRUCTURE_H
#define COQDATASTRUCTURE_H

class CoqSetCommand{
public:
  vector<string> keywords;
};

class CoqRequireCommand{
public:
  bool doImport;
  bool doExport;
  string libname;
};

class CoqImportCommand{
};

class CoqStructure{
  vector<pair<string, CoqType *> > members;
};

class CoqExprApply{
};

class CoqExprLetIn{
};

class CoqExprMatch{
};

class CoqExprId{
};

class CoqExprFun{
};

class CoqInductive{
public:
  string name;
  vector<CoqIndCons*> elems;
};

class CoqDefinition{
public:
  string name;
  vector<pair<string, CoqType*> > args;
  CoqType *type;
  CoqExpr *expr;
};

class CoqModule{

};

#endif
