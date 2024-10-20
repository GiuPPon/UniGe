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
  cout << "\n***** TEST lessFrequentFind(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 12 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    List list = NULL;
	string elem = "";
    cout<<"\nIl contenuto della lista e':     (" << stampaLista(list)<<")";
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="");
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Giallo");
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Rosso");
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Giallo");
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Rosso");
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Giallo");
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Giallo");
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
	for (int i = 0; i<100; i++){
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Giallo");
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
	for (int i = 0; i<100; i++){
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Verde");
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
	for (int i = 0; i<100; i++){
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Blu");
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
	for (int i = 0; i<100; i++){
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Blu");
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
	for (int i = 0; i<50; i++){
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
	for (int i = 0; i<50; i++){
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
	string elemMenoFrequente = lessFrequentFind(list);
	cout<<"\nL'elemento meno frequente e' " << elemMenoFrequente;
    bool ans = (elemMenoFrequente=="Blu");
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
