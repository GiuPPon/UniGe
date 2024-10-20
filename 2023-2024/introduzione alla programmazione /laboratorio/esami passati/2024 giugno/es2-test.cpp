#include <iostream>
#include "array.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}
////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */

std::string printArray(int* arrayInteri, unsigned int size) {
	std::string out = "[";
	for (unsigned int i = 0; i < size; i++) {
	if (i > 0) out = out + ",";
	out = out + std::to_string(arrayInteri[i]);
  }
  out += "]";
  return out;
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
  cout << std::boolalpha;
  cout << "\n";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n***** TEST ascendingSequenceEvenOdd(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 22 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={};
    unsigned int s=0;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={2};
    unsigned int s=1;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={2,4};
    unsigned int s=2;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={4,2};
    unsigned int s=2;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,3};
    unsigned int s=2;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={3,1};
    unsigned int s=2;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
   nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={0,1};
    unsigned int s=2;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
   nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,0};
    unsigned int s=2;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,2,3,4};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,3,2,4};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={2,1,4,3};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={3,1,2,4};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
 nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={2,4,3,1};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,3,4,2};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
 nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={4,1,3,2};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,1,1,1};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,2,3,4};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={-10,5,2,33};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={1,-4,3,-2};
    unsigned int s=4;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
 nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={-3,-2,0,2,-1};
    unsigned int s=5;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={-135,124,-101,246,1,3,304,1788,5,1801,1798,1800};
    unsigned int s=12;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={-135,124,-101,246,1,3,304,1788,5,1801,1798,1799};
    unsigned int s=12;
    bool res =  ascendingSequenceEvenOdd(a,s);
    bool corr=false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<corr;
    cout << "\nLa funzione ritorna "<<res;
    bool ans=(res==corr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
