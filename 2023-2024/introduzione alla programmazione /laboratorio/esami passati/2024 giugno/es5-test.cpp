#include <iostream>
#include "list.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}

////////////////////////////////////////////////////////////////////////////
// funzione utilizzata per test **non modificare**

void headInsert(List &list, Elem newElem)
{
   // creo una nuova Cell
   Cell* newCell = new Cell;
   
   // inserisco il dato nella Cell
   newCell->elem = newElem;
   
   // collego la Cell alla testa della List
   newCell->next = list;
   
   // lista diventa la nuova prima Cell
   list = newCell;
}

////////////////////////////////////////////////////////////////////////////
// funzione utilizzata per test **non modificare**

std::string stampaLista(List list)
{
    std::string out = "";
    int i = 0;

    while (list != NULL) {
        
       if (i>0) out = out + ",";
       out = out + list->elem;
       
       list = list->next;
       i++;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////
// funzione utilizzata per test **non modificare**
bool testResult(std::string s1, std::string s2)
{
    return s1 == s2;
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
  cout << std::boolalpha;
  cout << "\n";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
  cout << "\n***** TEST elementIstancesCount(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 16 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    List list = NULL;
	string elem = "";
	elem = "Giallo";
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==0);
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

    List list = NULL;
	string elem = "";
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	elem = "Giallo"; 
	headInsert(list,elem);
	elem = "Rosso"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Rosso"; 
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==2);
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

    List list = NULL;
	string elem = "";
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Rosso"; 
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==2);
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

    List list = NULL;
	string elem = "";
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Rosso"; 
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==2);
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

    List list = NULL;
	string elem = "";
	elem = "Verde"; 
	headInsert(list,elem);
	elem = "Verde"; 
	headInsert(list,elem);
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Rosso"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==2);
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

    List list = NULL;
	string elem = "";
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
	elem = "Verde"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==11);
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

    List list = NULL;
	string elem = "";
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
	elem = "Giallo"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==11);
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

    List list = NULL;
	string elem = "";
	elem = "Blu"; 
	headInsert(list,elem);
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Blu";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
	elem = "Blu"; 
	headInsert(list,elem);
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Blu";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	for (int i = 0; i<15; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
	elem = "Blu"; 
	headInsert(list,elem);
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Blu";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==1);
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

    List list = NULL;
	string elem = "";
	for (int i = 0; i<15; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
	elem = "Blu"; 
	headInsert(list,elem);
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Verde"; ;
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==25);
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

    List list = NULL;
	string elem = "";
	for (int i = 0; i<15; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
	elem = "Blu"; 
	headInsert(list,elem);
	for (int i = 0; i<10; i++){
		elem = "Verde"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Rosso"; 
		headInsert(list,elem);
		elem = "Giallo"; 
		headInsert(list,elem);
	}
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	elem = "Rosso";
	unsigned int numIstanze = elementIstancesCount(list,elem);
	cout<<"\nIl numero di istanze dell'elemento " << elem << " e' " << numIstanze;
    bool ans = (numIstanze==50);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
