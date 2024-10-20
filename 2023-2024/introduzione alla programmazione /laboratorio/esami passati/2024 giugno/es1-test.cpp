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
  cout << "\n**** TEST  returnLucasNumberInPos(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 10 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=0     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=0;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
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
    cout << "\n    TEST " << nTest << " pos=1     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=1;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
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
    cout << "\n    TEST " << nTest << " pos=2     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=2;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 3";
     cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==3);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=3     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=3;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 4";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==4);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=4     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=4;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
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
    cout << "\n    TEST " << nTest << " pos=5     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=5;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 11";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==11);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=6     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=6;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 18";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==18);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=7     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=7;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 29";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==29);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=15     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=15;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 1364";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==1364);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << " pos=19     ";
    cout << "\n-----------------------------------------";

    unsigned int pos=19;
        
    unsigned int res =  returnLucasNumberInPos(pos);
    cout << "\nLa posizione nella sequenza e': " << pos;
    cout << "\nLa funzione deve ritornare 9349";
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==9349);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
