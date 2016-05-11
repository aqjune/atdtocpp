CXX = g++
CFLAGS=-std=c++11 -g 

all: atdtocpp atdparamconv coqtoatd
DEPS=cppdatastructure.h convert.h parser.tab.h printer.h lexer.l parser.y
OBJ=cppdatastructure.o convert.o lex.yy.o parser.tab.o printer.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

coqtoatd: $(OBJ) coqtoatd.cpp
	$(CXX) -o $@ $^ $(CFLAGS)

atdtocpp: $(OBJ) atdtocpp.cpp
	$(CXX) -o $@ $^ $(CFLAGS)
 
atdparamconv: $(OBJ) atdparamconv.cpp
	$(CXX) -o $@ $^ $(CFLAGS)

lex.yy.c: lexer.l
	flex lexer.l
parser.tab.c: parser.y
	bison -d parser.y

.PHONY: clean
clean:
	rm -f *.o
	rm atdtocpp
	rm atdparamconv
