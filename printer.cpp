#include"printer.h"
using namespace std;

PrintConfig PrintConfig::DEFAULT_PRINT_CONFIG;
void printIndentation(ostream &out, int ac, PrintConfig *config){
  for(int i = 0; i < ac; i++)
    for(int j = 0; j < config->indentsize; j++)
      out << " ";
}


