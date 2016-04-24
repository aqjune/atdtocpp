#!/bin/bash
bison -d parser.y
/home/juneyoung.lee/flex/bin/flex lexer.l
#g++ -l:/home/juneyoung.lee/flex/lib/libfl.a lex.yy.c main.tab.c -std=c++11 -o cppextract
g++ parser.tab.c  lex.yy.c convert.cpp cppdatastructure.cpp atdtocpp.cpp -std=c++11 -g -o atdtocpp
