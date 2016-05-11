#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>
#include<cassert>
#include"datastructure.h"
using namespace std;


class CoqInfrule{
public:
  string name;
  vector<pair<string, string> > cons;
  void print(){
    cout << name;
    for(size_t i = 0; i < cons.size(); i++)
      cout << " (" << cons[i].first << ":" << cons[i].second << ")";
    cout << endl;
  }
};

class convert_exception: public exception{
public:
  string coqname;
  convert_exception(string coqname):coqname(coqname){}
};

string trim(const std::string &s){
  auto wsfront = std::find_if_not(s.begin(),s.end(),[](int c){return std::isspace(c);});
  auto wsback = std::find_if_not(s.rbegin(),s.rend(),[](int c){return std::isspace(c);}).base();
  return (wsback <= wsfront ? std::string() : std::string(wsfront,wsback));
}
string nextToken(std::string &s){
  s = trim(s);
  auto wsfront = std::find_if(s.begin(),s.end(),[](int c){return std::isspace(c);});
  string token = s.substr(0, wsfront - s.begin());
  s = trim(s.substr(wsfront - s.begin()));
  //cout << "nextToken() : token : " << token << " , s : " << s << endl;
  return token;
}

string replacePrimes(const string &name){
  if(name.back() == '\''){
    return name.substr(0, name.length() - 1) + "prime";
  }
  return name;
}

bool parseType(CoqInfrule *ir, string &s){
  //cout << "parseType() : s : " << s << endl;
  s = trim(s);
  if(s.length() == 0) return false;

  assert(s[0] == '(');
  auto itr = s.begin();
  itr++;
  
  string name = "";
  string type = "";
  while(*itr != ':'){
    name += *itr;
    itr++;
  }
  assert(*itr == ':');
  itr++;
  while(*itr != ')'){
    type += *itr;
    itr++;
  }
  assert(*itr == ')');
  name = trim(name);
  type = trim(type);
  itr++;
  s = s.substr(itr - s.begin());
  
  ir->cons.push_back(make_pair(name, type));
  return true;
}

void readCoqInfrules(string hintsFileName, vector<CoqInfrule *> &ty){
  ifstream fin;
  fin.clear();
  fin.exceptions(std::ifstream::badbit);
  fin.open(hintsFileName);
  std::string line;
  while(std::getline(fin, line)){
    line = trim(line);
    if(line.length() == 0) continue;
    if(line[0] == '|') line = line.substr(1);
    line = trim(line);
    
    CoqInfrule *ir = new CoqInfrule();
    ir->name = nextToken(line);
    while(parseType(ir, line));
    ty.push_back(ir);
    
    cout << "  ";
    ir->print();
  }
  fin.close();
}

void readMap(string mapFileName, map<string, string> &coqtyToAtdty){
  ifstream fin;
  fin.exceptions(ifstream::badbit);
  fin.open(mapFileName);
  string coqty, atdty;
  while(fin >> coqty >> atdty){
    coqtyToAtdty[coqty] = atdty;
  }
  fin.close();
}

RecordTypeDec *createAtdTypeDec(CoqInfrule *itr, map<string, string> &coqtyToAtdty){
  RecordTypeDec *dec = new RecordTypeDec();
  dec->name = itr->name;
  for(auto citr = itr->cons.begin(); citr != itr->cons.end(); citr++){
    pair<string, string> p = *citr;
    if(coqtyToAtdty.find(p.second) == coqtyToAtdty.end()){
      cerr << "ERROR : Cannot find ATD type corresponding to coq type " << p.second << endl;
      cerr << "  Infrule def : ";
      itr->print();
      throw convert_exception(p.second);
    }
    Field *f = new Field();
    f->name = replacePrimes(p.first);
    f->type = new NamedType(coqtyToAtdty[p.second]);
    dec->fields.push_back(f);
  }
  return dec;
}

int main(int argc, char **argv){
  if(argc != 4){
    cerr << "coqtoatd <input(Hints.v)> map.txt <output(.atd)>" << endl;
    return -1;
  }
  
  string hintsFileName(argv[1]);
  string mapFileName(argv[2]);
  string outputAtdFileName(argv[3]);

  vector<CoqInfrule *> infrules;
  try{
    readCoqInfrules(hintsFileName, infrules);
  }catch(ifstream::failure e){
    cout << "I/O error while reading coq file " << hintsFileName << endl;
    cout << "Message : " << e.what() << endl;
    return -1;
  }
  cout << "Parsing inference rules done." << endl;
  
  map<string, string> coqtyToAtdty;
  try{
    readMap(mapFileName, coqtyToAtdty);
  }catch(ifstream::failure e){
    cout << "I/O error while reading coq file " << hintsFileName << endl;
    cout << "Message : " << e.what() << endl;
    return -1;
  }
  cout << endl << "Reading map.txt done." << endl;
  
  vector<RecordTypeDec *> atdtypedecs;
  for(auto itr = infrules.begin(); itr != infrules.end(); itr++){
    try{
      RecordTypeDec *tydec = createAtdTypeDec(*itr, coqtyToAtdty);
      atdtypedecs.push_back(tydec);
    }catch(convert_exception &ce){
    }
  }

  ofstream fout(outputAtdFileName);
  PrintConfig pc;
  pc.indentsize = 2;
  for(auto itr = atdtypedecs.begin(); itr != atdtypedecs.end(); itr++){
    RecordTypeDec *dec = *itr;
    dec->print(fout, &pc);
    fout << endl << endl;
  }
  cout << "Writing to " << outputAtdFileName << " done." << endl;

  return 0;
}
