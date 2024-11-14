#include <iostream>
#include "funz.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}
////////////////////////////////////////////////////////////////////////////

int main(){
  int ret=0;
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n**** TEST  numIterSequenzaSiracusa(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 9 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=0     ";
    cout << "\n-----------------------------------------";

    unsigned int v=0;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 0";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==0);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=1     ";
    cout << "\n-----------------------------------------";

    unsigned int v=1;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 0";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==0);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=2     ";
    cout << "\n-----------------------------------------";

    unsigned int v=2;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 1";
     cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==1);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=3     ";
    cout << "\n-----------------------------------------";

    unsigned int v=3;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 7";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==7);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=4     ";
    cout << "\n-----------------------------------------";

    unsigned int v=4;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 2";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==2);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=5     ";
    cout << "\n-----------------------------------------";

    unsigned int v=5;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 5";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==5);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=11     ";
    cout << "\n-----------------------------------------";

    unsigned int v=11;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 14";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==14);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=64     ";
    cout << "\n-----------------------------------------";

    unsigned int v=64;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 6";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==6);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " vinit=999     ";
    cout << "\n-----------------------------------------";

    unsigned int v=999;
        
    unsigned int res =  numIterSequenzaSiracusa(v);
    cout << "\nIl valore iniziale e': " << v;
    cout << "\nLa funzione deve ritornare 49";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==49);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
