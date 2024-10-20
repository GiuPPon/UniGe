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
  cout << "\n***** TEST tailInsert(...) *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 4 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    string elem = "";
    List list = NULL;

    
    elem = "Giallo";
    cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
    cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
    bool ans = testResult(stampaLista(list),"Giallo");
  
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

    string elem = "";
    List list = NULL;

    cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
    elem = "Giallo";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    elem = "Verde";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
    bool ans = testResult(stampaLista(list),"Giallo,Verde");
  
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

    string elem = "";
    List list = NULL;

    cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
    elem = "Giallo";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    elem = "Verde";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
	elem = "Rosso";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
    bool ans = testResult(stampaLista(list),"Giallo,Verde,Rosso");
  
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

    string elem = "";
    List list = NULL;

    cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
    elem = "Giallo";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    elem = "Verde";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
	elem = "Rosso";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
	elem = "Rosso";
	cout<<"\nInserisco l'elemento = " << elem;
    tailInsert(list,elem);
    cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
    bool ans = testResult(stampaLista(list),"Giallo,Verde,Rosso,Rosso");
  
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
