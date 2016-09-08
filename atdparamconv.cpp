#include "datastructure.h"
#include "convert.h"
#include "parser.h"
#include "assert.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  if(argc != 3){
    cout << "atdparamconv <.atd input file> <.ml output file>" << endl;
    return 0;
  }
  if(doParse(argv[1]) < 0)
    return -1;
  
  if(root->decs.find("infrule") == root->decs.end()){
    cerr << "Your atd file must have infrule data type" << endl;
    return -1;
  }
  
  ofstream fout(argv[2]);
  InductiveTypeDec *infruledec = dynamic_cast<InductiveTypeDec*>(root->decs["infrule"]);
  assert(infruledec);
  for(auto itr = infruledec->cons.begin(); itr != infruledec->cons.end(); itr++){
    Constructor *cons = *itr;
    NamedType *argty = dynamic_cast<NamedType *>(cons->argtype);
    assert(argty);

    RecordTypeDec *itemdec = dynamic_cast<RecordTypeDec*>(root->decs[argty->name]);
    if(itemdec == nullptr){
      cerr << argty->name << " does not exst" << endl;
      assert(itemdec);
    }
    fout << "  | CoreHint_t." << cons->name << " (args:CoreHint_t." << argty->name << ") -> " << endl;

    string args = "(";
    for(auto fitr = itemdec->fields.begin(); fitr != itemdec->fields.end(); fitr++){
      Field *f = *fitr;
      NamedType *ftype = dynamic_cast<NamedType*>(f->type);
      assert(ftype);
      if (ftype->name == "expr") {
        fout << "     let " << f->name << " = Convert." << ftype->name << 
            " args." << f->name << " src_fdef tgt_fdef in" << endl;
      } else {
        fout << "     let " << f->name << " = Convert." << ftype->name << 
            " args." << f->name << " in" << endl;
      }

      if(fitr != itemdec->fields.begin())
        args += ", ";
      args += f->name;
    }
    args += ")";
    fout << "     Infrule.Coq_" << argty->name << " " << args << endl;
  }

  return 0;
}
