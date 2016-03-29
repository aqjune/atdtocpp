%{
#include "datastructure.h"
#include "main.tab.h"
#include <string>
extern "C" int yylex();
using namespace std;

void print_token(char *c){
  //printf("token %s\n", c);
}
%}

%option noyywrap

%x COMMENT
%x TAG

%%
[ \t\n]+        ;
"type"          return TOK_TYPE;
"{"             return TOK_RECORDBEG;
"}"             return TOK_RECORDEND;
"<"             { BEGIN(TAG); }
<TAG>">"        { BEGIN(INITIAL); }
<TAG>.          ; // ignore
"(*"             { BEGIN(COMMENT); }
<COMMENT>"*)"   { BEGIN(INITIAL); }
<COMMENT>.      ; // ignore
"["             return TOK_LISTBEGIN;
"]"             return TOK_LISTEND;
"of"            return TOK_OF;
":"             return TOK_COLON;
";"             return TOK_SEMICOLON;
"|"             return TOK_OR;
"*"             return TOK_PRODUCT;
"("             return TOK_PTBEGIN;
")"             return TOK_PTEND;
"="             return TOK_EQUAL;
[a-zA-Z_0-9']+     { int len = strlen(yytext);
                  char *c = new char[len + 1];
                  c[len] = 0;
                  strcpy(c, yytext);
                  yylval.str_ty = c; 
                  print_token(c);
                  return TOK_WORD; }

%%
