#include <iostream>
#include <string>

#include "ll.h"

using namespace std;

void inverti(string str)
{
  ll t=nullptr;
  char c;

  for(int i=0; i<str.size(); i++)  addhead(t,str[i]);
  std::cout<<"Size = "<<size(t)<<"\n";
  while (removehead(t, c)) std::cout << c;
}

int main()
{
  string test1( "Hello, world!" );
  string test2( "SATOR AREPO TENET OPERA ROTAS" );
  string test3( "Call me Ismael." );
   
  cout << "-----Test1: " << test1 << "\n";
  inverti(test1);
  cout << "\n\n";

  cout << "-----Test2: " << test2 << "\n";
  inverti(test2);
  cout << "\n\n";

  cout << "-----Test3: " << test3 << "\n";
  inverti(test3);
  cout << "\n\n";

}
