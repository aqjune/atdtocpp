#ifndef PRINTER_H
#define PRINTER_H
#include<fstream>
#include<iostream>

class PrintConfig{
public:
  static PrintConfig DEFAULT_PRINT_CONFIG;
  int indentsize;
};

void printIndentation(std::ostream &out, int ac, PrintConfig *config);

#endif
