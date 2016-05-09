CXX = g++
CFLAGS=-std=c++11 -g 

all: atdtocpp atdparamconv
DEPS=cppdatastructure.h convert.h parser.tab.h
OBJ=cppdatastructure.o convert.o lex.yy.o parser.tab.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

atdtocpp: $(OBJ) atdtocpp.cpp
	$(CXX) -o $@ $^ $(CFLAGS)
 
atdparamconv: $(OBJ) atdparamconv.cpp
	$(CXX) -o $@ $^ $(CFLAGS)

lex.yy.c:
	flex lexer.l
parser.tab.c:
	bison -d parser.y

.PHONY: clean
clean:
	rm -f *.o
	rm atdtocpp
	rm atdparamconv
