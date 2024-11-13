#include <iostream>
#include <fstream>
#include <iomanip>

#include "hist.h"


void print(const Hist &h)
{
  for (int i=0; i<h.size(); i++) std::cout << h[i].value << '\t' << h[i].num << '\n';
}

int main()
{
  Hist h;

  std::cout << "test di add:\n";
  std::cout << "1) leggo file\n";
  std::ifstream dati("valori.txt");
  while (!dati.eof()) {
    int  v = -1;
    dati >> v;
	 if (v>=0) add(h, v);
  }
  dati.close();
  std::cout << "2) risultato lettura:\n";
  print(h);
  std::cout << "---------\n";

  std::cout << "3) risultato sort:\n";
  sort(h);
  print(h);
  std::cout << "---------\n";

  std::cout << "4) test di count:\n";
  std::cout << "count 10 (valore presente):\n";
  std::cout << count(h, 10) << '\n';
  std::cout << "---------\n";

  std::cout << "count 100 (valore non presente):\n";
  std::cout << count(h, 100) << '\n';
  std::cout << "---------\n";

  std::cout << "5) istogramma in forma grafica:\n";
  int imax = 0;
  for (int i=0; i<h.size(); i++) if (h[i].value>h[imax].value) imax=i;
  for (int i=0; i<=h[imax].value; i++) {
    std::cout << std::setw(3);
    std::cout << i << " ";
    for (int c=0; c< count(h, i); c++) std::cout<<"="; std::cout<<"\n";
  }
}
