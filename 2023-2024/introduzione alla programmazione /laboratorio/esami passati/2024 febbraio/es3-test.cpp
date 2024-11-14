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

std::string printArray2(unsigned int* arrayInteri, unsigned int size) {
	std::string out = "[";
	for (unsigned int i = 0; i < size; i++) {
	if (i > 0) out = out + ",";
	out = out + std::to_string(arrayInteri[i]);
  }
  out += "]";
  return out;
}
//////////////////////////////////////////////////////////////////////////// 
// funzione utilizzata per test **non modificare**
/* confronta due array della stessa size
*/

bool compareArray(unsigned int* nums1, unsigned int* nums2, unsigned int size)
{
	bool res = true;
	if (size > 0)
		for(unsigned int i = 0 ; i <= size-1 ; i++)
		{
		   res = res & (nums1[i] == nums2[i]);
		}
	return res;
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
  cout << std::boolalpha;
  cout << "\n";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
  cout << "\n***** TEST indexOfInArray(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 10 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[]={};
    unsigned int s=0;
    int v=0;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[0];
    unsigned int dcorr=0;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={1};
    unsigned int s=1;
    int v=2;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[0];
    unsigned int dcorr=0;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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
    int v=2;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
    acorr[0]=0;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={1,2,3,2,6};
    unsigned int s=5;
    int v=6;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
    acorr[0]=4;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={10,20,-3,15,65,42,34,67};
    unsigned int s=8;
    int v=10;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
    acorr[0]=0;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={1,5,0,5,10,42,34,-5};
    unsigned int s=8;
    int v=5;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[2];
    unsigned int dcorr=2;
    acorr[0]=1;
    acorr[1]=3;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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
    int a[]={1,2,1,3,1,4,1};
    unsigned int s=7;
    int v=1;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[4];
    acorr[0]=0;
    acorr[1]=2;
    acorr[2]=4;
    acorr[3]=6;
    unsigned int dcorr=4;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={-3,-3,-3,-3,-3,-3,-3,-3,-3,-3};
    unsigned int s=10;
    int v=-3;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[10];
    unsigned int dcorr=10;
    acorr[0]=0;
    acorr[1]=1;
    acorr[2]=2;
    acorr[3]=3;
    acorr[4]=4;
    acorr[5]=5;
    acorr[6]=6;
    acorr[7]=7;
    acorr[8]=8;
    acorr[9]=9;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={-3,-3,-3,-3,-3,-3,-3,-3,-3,3};
    unsigned int s=10;
    int v=-3;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[9];
    unsigned int dcorr=9;
    acorr[0]=0;
    acorr[1]=1;
    acorr[2]=2;
    acorr[3]=3;
    acorr[4]=4;
    acorr[5]=5;
    acorr[6]=6;
    acorr[7]=7;
    acorr[8]=8;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
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

    int a[]={3,-3,-3,-3,-3,-3,-3,-3,-3,-3};
    unsigned int s=10;
    int v=-3;
    dyn_array res=indexOfInArray(v,a,s);
    unsigned int *acorr=new unsigned int[9];
    unsigned int dcorr=9;
    acorr[0]=1;
    acorr[1]=2;
    acorr[2]=3;
    acorr[3]=4;
    acorr[4]=5;
    acorr[5]=6;
    acorr[6]=7;
    acorr[7]=8;
    acorr[8]=9;
    cout << "\nSi cerca "<<v<<" nel array " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<< printArray2(acorr,dcorr);
    cout << "\nLa funzione ritorna "<<printArray2(res.A,res.D);
    bool ans=(res.D==dcorr) && compareArray(acorr,res.A,dcorr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }   
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
