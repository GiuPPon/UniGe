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
  cout << "\n***** TEST indexOfEvenInArray(...) *****";
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
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[0];
    unsigned int dcorr=0;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={0};
    unsigned int s=1;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
	acorr[0] = 0;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={101};
    unsigned int s=1;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=0;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={100,101};
    unsigned int s=2;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
	acorr[0] = 0;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={100,102};
    unsigned int s=2;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[2];
    unsigned int dcorr=2;
	acorr[0] = 0;
	acorr[1] = 1;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={4,5,1};
    unsigned int s=3;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
	acorr[0] = 0;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={5,4,1};
    unsigned int s=3;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
	acorr[0] = 1;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={5,1,4};
    unsigned int s=3;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[1];
    unsigned int dcorr=1;
	acorr[0] = 2;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={2,6,1};
    unsigned int s=3;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[2];
    unsigned int dcorr=2;
	acorr[0] = 0;
	acorr[1] = 1;
	cout << "\nArray in input  "<< printArray(a,s);
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

    int a[]={2,6,2,1,2,2};
    unsigned int s=6;
    dyn_array res=indexOfEvenInArray(a,s);
    unsigned int *acorr=new unsigned int[5];
    unsigned int dcorr=5;
	acorr[0] = 0;
	acorr[1] = 1;
	acorr[2] = 2;
	acorr[3] = 4;
	acorr[4] = 5;
	cout << "\nArray in input  "<< printArray(a,s);
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
