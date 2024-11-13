#include <iostream>
#include <fstream>

#include "bow.h"


void print(const BagOfWords &b)
{
  for (int i=0; i<b.size(); i++) std::cout << b[i].num << '\t' << b[i].word << '\n';
}

int main()
{
  BagOfWords b;

  std::cout << "test di add:\n";
  std::cout << "1) leggo file\n";
  std::ifstream testo("testo.txt");
  while (!testo.eof()) {
	 std::string w;
    testo >> w;
	 if (w.size()>0) add(b, w);
  }
  testo.close();
  std::cout << "2) risultato:\n";
  print(b);
  std::cout << "---------\n";

  std::string w = "non";

  std::cout << "test di count ("<< w <<"):\n";
  std::cout << count(b,w) << '\n';
  std::cout << "---------\n";

  std::cout << "test di del ("<< w <<") quando compare 2 volte:\n";
  del(b,w);
  print(b);
  std::cout << '\n';
  std::cout << "test di del ("<< w <<") quando compare 1 volta:\n";
  del(b,w);
  print(b);
  std::cout << '\n';
  std::cout << "test di del ("<< w <<") quando è assente:\n";
  del(b,w);
  print(b);
  std::cout << "---------\n";
}
