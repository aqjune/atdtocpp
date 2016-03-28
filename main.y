%{
#include "datastructure.h"
#include "convert.h"
#include <stdio.h>
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
void yyerror(const char *s);
%}

%token TOK_WHITESPACE
%token TOK_TYPE
%token TOK_RECORDBEG
%token TOK_RECORDEND
%token TOK_LISTBEGIN
%token TOK_LISTEND
%token TOK_OF
%token TOK_COLON
%token TOK_SEMICOLON
%token TOK_OR
%token TOK_PRODUCT
%token TOK_PTBEGIN
%token TOK_PTEND
%token TOK_WORD
%token TOK_EQUAL

%union {
        Scheme *program_ty;
        TypeDec *typedec_ty;
        TypeDec *typedec_remain_ty;
        vector<Constructor *> *conslist_ty;
        vector<Field *> *fieldlist_ty;
        Type *atdtype_ty;
        char *str_ty;
}
%type <program_ty> program
%type <typedec_ty> typedec
%type <typedec_remain_ty> typedec_remain
%type <conslist_ty> conslist
%type <conslist_ty> conslist2
%type <fieldlist_ty> fieldlist
%type <atdtype_ty> atdtype
%type <str_ty> TOK_WORD

%{
Scheme *root;
%}

%%

program:
        program typedec         { $1->addNewType($2); $$ = $1; }
        |                       { $$ = root = new Scheme(); }
        ;

typedec:
        TOK_TYPE TOK_WORD TOK_EQUAL typedec_remain
                                { TypeDec *td = dynamic_cast<TypeDec *>($4);
                                  td->name = string($2);
                                  $$ = td; }

typedec_remain: 
        TOK_LISTBEGIN conslist TOK_LISTEND
                                { InductiveTypeDec *td = new InductiveTypeDec();
                                  td->addAll($2);
                                  $$ = td; }
        | TOK_RECORDBEG fieldlist TOK_RECORDEND
                                { RecordTypeDec *td = new RecordTypeDec();
                                  td->addAll($2); 
                                  $$ = td; }
        ;

conslist:
        TOK_OR TOK_WORD TOK_OF atdtype conslist2
                                { vector<Constructor *> *v = $5;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = $4;
                                  v->insert(v->begin(), c);
                                  $$ = v; }
        | TOK_WORD TOK_OF atdtype conslist2
                                { vector<Constructor *> *v = $4;
                                  Constructor *c = new Constructor();
                                  c->name = string($1);
                                  c->argtype = $3;
                                  v->insert(v->begin(), c);
                                  $$ = v; }
        | TOK_OR TOK_WORD conslist2
                                { vector<Constructor *> *v = $3;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = nullptr;
                                  v->insert(v->begin(), c);
                                  $$ = v; }
        | TOK_WORD conslist2
                                { vector<Constructor *> *v = $2;
                                  Constructor *c = new Constructor();
                                  c->name = string($1);
                                  c->argtype = nullptr;
                                  v->insert(v->begin(), c);
                                  $$ = v; }

        ;

conslist2:        
        TOK_OR TOK_WORD TOK_OF atdtype conslist2
                                { vector<Constructor *> *v = $5;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = $4;
                                  v->insert(v->begin(), c);
                                  $$ = v; }
        | TOK_OR TOK_WORD conslist2
                                { vector<Constructor *> *v = $3;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = nullptr;
                                  v->insert(v->begin(), c);
                                  $$ = v; }
        |                       { vector<Constructor *> *v = new vector<Constructor *>();
                                  $$ = v; }
        ;
        

fieldlist:
        TOK_WORD TOK_COLON atdtype TOK_SEMICOLON fieldlist
                                { vector<Field *> *v = $5;
                                  Field *f = new Field();
                                  f->name = string($1);
                                  f->type = $3;
                                  v->insert(v->begin(), f);
                                  $$ = v; }
        |                       { vector<Field *> *v = new vector<Field *>();
                                  $$ = v; }
        ;

atdtype:
        TOK_WORD                { Type *td = new NamedType(string($1));
                                  $$ = td; }
        | TOK_PTBEGIN atdtype TOK_PTEND
                                { $$ = $2; }
        | atdtype TOK_WORD
                                { ParameterizedType *td = new ParameterizedType();
                                  td->ty = new NamedType($2);
                                  td->arg = $1;
                                  $$ = td; }
        | atdtype TOK_PRODUCT atdtype
                                { ProdType *td = new ProdType();
                                  td->addChild($1);
                                  td->addChild($3);
                                  $$ = td; }
%%


int main(int argc, char** argv) {
  if(argc != 4){
    cout << "atdtocpp <.atd input file> <.cpp output file> <.h output file>" << endl;
    return 0;
  }
  FILE *myfile = fopen(argv[1], "r");
  if (!myfile) {
    cout << "I can't open " << argv[1] << endl;
    return -1;
  }
  yyin = myfile;
  
  do{
    yyparse();
  }while(!feof(yyin));
  
  convert(root, argv[2], argv[3]);
}
void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  exit(-1);
}
