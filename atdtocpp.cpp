#include "datastructure.h"
#include "convert.h"
#include "parser.h"
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv) {
  if(argc != 4 && argc != 5){
    cout << "atdtocpp <.atd input file> <.cpp output file> <.h output file>" << endl;
    cout << "atdtocpp <.atd input file> <.cpp output file> <.h output file> <.txt class-output-list>" << endl;
    return 0;
  }
  if(doParse(argv[1]) < 0)
    return -1;
  
  vector<string> *printlist = nullptr; 
  if(argc == 5){
    printlist = new vector<string>();
    
    ifstream fin(argv[4]);
    string str;
    while(fin >> str){
      printlist->push_back(str);
    }
    fin.close();
  }

  convert(root, argv[2], argv[3], printlist);
  return 0;
}
