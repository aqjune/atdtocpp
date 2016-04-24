#include "datastructure.h"
#include "convert.h"
#include "parser.h"
#include <stdio.h>
int main(int argc, char** argv) {
  if(argc != 4){
    cout << "atdtocpp <.atd input file> <.cpp output file> <.h output file>" << endl;
    return 0;
  }
  if(doParse(argv[1]) < 0)
    return -1;
  
  convert(root, argv[2], argv[3]);
  return 0;
}
