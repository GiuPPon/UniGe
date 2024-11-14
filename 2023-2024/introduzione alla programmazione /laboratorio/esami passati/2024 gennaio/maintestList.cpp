#include <iostream>

#include "list.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
// funzione utilizzata per test **non modificare**
void inserimentoInTesta(List &list, Elem newElem)
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

    while (list != nullptr) {
        
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
// main utilizzato per test **non modificare**
int main() {

  int scelta;
  cout << endl
       << " Quale funzione vuoi testare. Digita un numero:\n\n"
       << " 1 per testare computeListSize(...)\n"
       << " 2 per testare insertElemInListAtIndex(...);\n"
       << " 3 per testare deleteLastInstanceOfElemInList(...)\n\n"
       << " Inserisci un numero e premi invio: ";
  cin >> scelta;

  switch (scelta) {
  case 1: {

   	cout << std::boolalpha;

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n*****   TEST computeListSize(...)  ******";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    cout << "\n";
    cout << "\n!!!! ATTENZIONE: 4 TEST DA SUPERARE !!!!";
	int nTest = 1;
	
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;
		//inserimentoInTesta(list,"A");
		unsigned int lenght = 0;
		cout<<"\nIl contenuto della lista e': (" << stampaLista(list)<<")";
		unsigned int res = computeListSize(list);
		cout<<"\nLa lunghezza della lista ritornata e' = " << res;
		cout << "\nIl test  e' superato? ==========================> " << (lenght == res);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;
		inserimentoInTesta(list,"A");
		unsigned int lenght = 1;
		cout<<"\nIl contenuto della lista e': (" << stampaLista(list)<<")";
		unsigned int res = computeListSize(list);
		cout<<"\nLa lunghezza della lista ritornata e' = " << res;
		cout << "\nIl test  e' superato? ==========================> " << (lenght == res);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");
		unsigned int lenght = 2;
		cout<<"\nIl contenuto della lista e': (" << stampaLista(list)<<")";
		unsigned int res = computeListSize(list);
		cout<<"\nLa lunghezza della lista ritornata e' = " << res;
		cout << "\nIl test  e' superato? ==========================> " << (lenght == res);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;
		inserimentoInTesta(list,"G");
		inserimentoInTesta(list,"F");
		inserimentoInTesta(list,"E");
		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"C");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");
		unsigned int lenght = 7;
		cout<<"\nIl contenuto della lista e': (" << stampaLista(list)<<")";
		unsigned int res = computeListSize(list);
		cout<<"\nLa lunghezza della lista ritornata e' = " << res;
		cout << "\nIl test  e' superato? ==========================> " << (lenght == res);
	}

    cout << "\n";
    cout << "\n*****   TEST della FUNZIONE CONCLUSI  ******";
    cout << "\n";
    
    break;
  }
  
  case 2: {

   	cout << std::boolalpha;

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n*****   TEST insertElemInListAtIndex(...)  ******";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    cout << "\n";
    cout << "\n!!!! ATTENZIONE: 11 TEST DA SUPERARE !!!!";
	int nTest = 1;
	
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		elem = "A";
		unsigned int pos = 0;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		elem = "A";
		unsigned int pos = 1;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == false);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista UN Elemento   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"A");

		elem = "B";
		unsigned int pos = 0;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"B,A");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista UN Elemento   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"A");

		elem = "B";
		unsigned int pos = 1;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista UN Elemento   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"A");

		elem = "B";
		unsigned int pos = 2;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == false);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista DUE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		elem = "C";
		unsigned int pos = 0;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"C,A,B");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista DUE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		elem = "C";
		unsigned int pos = 1;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,C,B");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista DUE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		elem = "C";
		unsigned int pos = 2;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,C");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista DUE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		elem = "C";
		unsigned int pos = 3;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == false);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista N Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"G");
		inserimentoInTesta(list,"F");
		inserimentoInTesta(list,"E");
		inserimentoInTesta(list,"C");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		elem = "D";
		unsigned int pos = 3;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,C,D,E,F,G");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == true);
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista N Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "";
		List list = nullptr;

		inserimentoInTesta(list,"G");
		inserimentoInTesta(list,"F");
		inserimentoInTesta(list,"E");
		inserimentoInTesta(list,"C");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		elem = "D";
		unsigned int pos = 32;
		cout<<"\nIl contenuto della lista *prima* dell'inserimento e': (" << stampaLista(list)<<")";
		cout<<"\nInserisco l'elemento = " << elem << " in pos index = " << pos;
		bool res = insertElemInListAtIndex(list,elem,pos);
		cout<<"\nIl contenuto della lista *dopo* l'inserimento e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,C,E,F,G");
		cout << "\nIl test (sul valore di ritorno) e' superato? ==========================> " << (res == false);
	}

    cout << "\n";
    cout << "\n*****   TEST della FUNZIONE CONCLUSI  ******";
    cout << "\n";
    
    break;
  }


 case 3: {

   	cout << std::boolalpha;

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n*****   TEST deleteLastInstanceOfElemInList(...)  ******";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    cout << "\n";
    cout << "\n!!!! ATTENZIONE: 9 TEST DA SUPERARE !!!!";
	int nTest = 1;
	
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con Lista Vuota   ******";
		cout << "\n------------------------------------";
		string elem = "Z";
		List list = nullptr;

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con UN Elemento   ******";
		cout << "\n------------------------------------";
		string elem = "Z";
		List list = nullptr;

		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con UN Elemento   ******";
		cout << "\n------------------------------------";
		string elem = "A";
		List list = nullptr;

		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con TRE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "A";
		List list = nullptr;

		inserimentoInTesta(list,"A");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con TRE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "B";
		List list = nullptr;

		inserimentoInTesta(list,"A");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,A");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con TRE Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "Z";
		List list = nullptr;

		inserimentoInTesta(list,"A");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,A");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con N Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "D";
		List list = nullptr;

		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"C");
		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"A");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,A,D,C");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con N Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "A";
		List list = nullptr;

		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"C");
		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"A");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,D,C,D");
	}
	nTest++;
	{
		
		cout << "\n";
		cout << "\n-------------------------------------";
		cout << "\n*****  TEST " << nTest << " con N Elementi   ******";
		cout << "\n------------------------------------";
		string elem = "C";
		List list = nullptr;

		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"C");
		inserimentoInTesta(list,"D");
		inserimentoInTesta(list,"A");
		inserimentoInTesta(list,"B");
		inserimentoInTesta(list,"A");

		cout<<"\nIl contenuto della lista e':                         (" << stampaLista(list)<<")";
		cout<<"\nElimino ultima istanza l'elemento = " << elem;
		deleteLastInstanceOfElemInList(list,elem);
		cout<<"\nIl contenuto della lista dopo l'eliminazione e':     (" << stampaLista(list)<<")";
		cout << "\nIl test (sulla lista) e' superato?           ==========================> " << testResult(stampaLista(list),"A,B,A,D,D");
	}

    cout << "\n";
    cout << "\n*****   TEST della FUNZIONE CONCLUSI  ******";
    cout << "\n";
    
    break;
  }

  default: {
    cout << "Scelta NON valida \n";
    break;
  }
  }

  return 0;
}
