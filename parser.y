%{
#include "datastructure.h"
#include "convert.h"
#include <stdio.h>
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
void yyerror(const char *s);
#define MERGE_YYLLOC(TGT, FROM, TO) { (TGT).first_column = (FROM).first_column; \
                        (TGT).first_line = (FROM).first_line; \
                        (TGT).last_column = (TO).last_column; \
                        (TGT).last_line = (TO).last_line; }
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
        program typedec         { $1->addNewType($2); 
                                  $$ = $1;
                                  MERGE_YYLLOC(@$, @1, @2);
                                }
        |                       { $$ = root = new Scheme(); }
        ;

typedec:
        TOK_TYPE TOK_WORD TOK_EQUAL typedec_remain
                                { TypeDec *td = dynamic_cast<TypeDec *>($4);
                                  td->name = string($2);
                                  MERGE_YYLLOC(@$, @1, @4);
                                  td->srcBegin = make_pair(@$.first_line, @$.first_column);
                                  td->srcEnd = make_pair(@$.last_line, @$.last_column);
                                  $$ = td; 
                                }

typedec_remain: 
        TOK_LISTBEGIN conslist TOK_LISTEND
                                { InductiveTypeDec *td = new InductiveTypeDec();
                                  td->addAll($2);
                                  MERGE_YYLLOC(@$, @1, @3);
                                  $$ = td; 
                                }
        | TOK_RECORDBEG fieldlist TOK_RECORDEND
                                { RecordTypeDec *td = new RecordTypeDec();
                                  td->addAll($2); 
                                  MERGE_YYLLOC(@$, @1, @3);
                                  $$ = td; 
                                }
        ;

conslist:
        TOK_OR TOK_WORD TOK_OF atdtype conslist2
                                { vector<Constructor *> *v = $5;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = $4;
                                  v->insert(v->begin(), c);
                                  MERGE_YYLLOC(@$, @1, @5);
                                  $$ = v; 
                                }
        | TOK_WORD TOK_OF atdtype conslist2
                                { vector<Constructor *> *v = $4;
                                  Constructor *c = new Constructor();
                                  c->name = string($1);
                                  c->argtype = $3;
                                  v->insert(v->begin(), c);
                                  MERGE_YYLLOC(@$, @1, @4);
                                  $$ = v; 
                                }
        | TOK_OR TOK_WORD conslist2
                                { vector<Constructor *> *v = $3;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = nullptr;
                                  v->insert(v->begin(), c);
                                  MERGE_YYLLOC(@$, @1, @3);
                                  $$ = v; 
                                }
        | TOK_WORD conslist2
                                { vector<Constructor *> *v = $2;
                                  Constructor *c = new Constructor();
                                  c->name = string($1);
                                  c->argtype = nullptr;
                                  v->insert(v->begin(), c);
                                  MERGE_YYLLOC(@$, @1, @2);
                                  $$ = v; 
                                }

        ;

conslist2:        
        TOK_OR TOK_WORD TOK_OF atdtype conslist2
                                { vector<Constructor *> *v = $5;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = $4;
                                  if(v->empty()){
                                    MERGE_YYLLOC(@$, @1, @4)
                                  }else{
                                    MERGE_YYLLOC(@$, @1, @5)
                                  }
                                  v->insert(v->begin(), c);
                                  $$ = v; 
                                }
        | TOK_OR TOK_WORD conslist2
                                { vector<Constructor *> *v = $3;
                                  Constructor *c = new Constructor();
                                  c->name = string($2);
                                  c->argtype = nullptr;
                                  if(v->empty()){
                                    MERGE_YYLLOC(@$, @1, @2)
                                  }else{
                                    MERGE_YYLLOC(@$, @1, @3)
                                  }
                                  v->insert(v->begin(), c);
                                  $$ = v; 
                                }
        |                       { vector<Constructor *> *v = new vector<Constructor *>();
                                  $$ = v; 
                                }
        ;
        

fieldlist:
        TOK_WORD TOK_COLON atdtype TOK_SEMICOLON fieldlist
                                { vector<Field *> *v = $5;
                                  Field *f = new Field();
                                  f->name = string($1);
                                  f->type = $3;
                                  if(v->empty()){
                                    MERGE_YYLLOC(@$, @1, @4)
                                  }else{
                                    MERGE_YYLLOC(@$, @1, @5)
                                  }
                                  v->insert(v->begin(), f);
                                  $$ = v; }
        |                       { vector<Field *> *v = new vector<Field *>();
                                  $$ = v; }
        ;

atdtype:
        TOK_WORD                { Type *td = new NamedType(string($1));
                                  $$ = td; 
                                }
        | TOK_PTBEGIN atdtype TOK_PTEND
                                { MERGE_YYLLOC(@$, @1, @3); 
                                  $$ = $2; 
                                }
        | atdtype TOK_WORD
                                { ParameterizedType *td = new ParameterizedType();
                                  td->ty = new NamedType($2);
                                  td->arg = $1;
                                  MERGE_YYLLOC(@$, @1, @2);
                                  $$ = td; 
                                }
        | atdtype TOK_PRODUCT atdtype
                                { ProdType *td = new ProdType();
                                  td->addChild($1);
                                  td->addChild($3);
                                  MERGE_YYLLOC(@$, @1, @3);
                                  $$ = td; 
                                }
%%


int doParse(char* fname) {
  FILE *myfile = fopen(fname, "r");
  if (!myfile) {
    cout << "I can't open " << fname << endl;
    return -1;
  }
  yyin = myfile;
  
  do{
    yyparse();
  }while(!feof(yyin));
}
void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  exit(-1);
}
