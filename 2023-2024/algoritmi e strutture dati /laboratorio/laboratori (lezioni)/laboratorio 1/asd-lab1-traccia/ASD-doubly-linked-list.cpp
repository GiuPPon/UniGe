// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include "ASD-doubly-linked-list.h"

using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {  
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/
  
/* crea la lista vuota */
void list::createEmpty(List& li){
	// visto che la lista è vuota, creo solo la sentinella
  node* aux = new node;
  aux -> next = aux;
  aux -> prev = aux;
  li = aux;
}

/* "smantella" la lista (tranne la sentinella) */
void list::clear(List& li){
	node* cur = li -> next; // salta la sentinella

  while (cur != li) {
    node* temp = cur -> next;
    delete cur;
    cur = temp;
  }

  li -> next = li;
  li -> prev = li;
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List& li){
  if (li -> next == li) {
    return true;
  }
  return false;
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List& li){
	unsigned int count = 0;
  node* cur = li -> next;
  while (cur != li) {
    ++count;
    cur = cur -> next;
  }
  return count;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List& li){
  if (pos >= size(li)) {
    string exc = "errore";
    throw exc;
  }

	unsigned int count = 0;
  node* cur = li -> next;

  while (cur != li && count < pos) {
    ++count;
    cur = cur -> next;
  }
  return cur -> info;
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List& li){
  if (pos >= size(li)) {
    string exc = "errore";
    throw exc;
  }

  unsigned int count = 0;
  node* cur = li -> next;

  while (cur != li && count < pos) {
    ++count;
    cur = cur -> next;
  }
  cur -> info = el;
}

/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List& li){
  if (pos > size(li)) {
    string exc = "errore";
    throw exc;
  }

  node* aux = new node;
  aux -> info = el;

	unsigned int count = 0;
  node* cur = li -> next;

  while (cur != li && count < pos) {
    ++count;
    cur = cur -> next;
  }
  cur -> prev -> next = aux;
  aux -> prev = cur -> prev;
  aux -> next = cur;
  cur -> prev = aux;
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List& li){
	node* aux = new node;
  aux -> info = el;

  node* cur = li -> prev;

  cur -> next = aux;
  aux -> prev = cur;
  aux -> next = li;
  li -> prev = aux;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List& li) {
	node* aux = new node;
  aux -> info = el;

  node* cur = li -> next;

  aux -> next = cur;
  cur -> prev = aux;
  aux -> prev = li;
  li -> next = aux;
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos,const List& li){
  if (pos >= size(li)) {
    string exc = "errore";
    throw exc;
  }

	unsigned int count = 0;
  node* cur = li -> next;

  while (cur != li && count < pos) {
    ++count;
    cur = cur -> next;
  }

  cur -> prev -> next = cur -> next;
  cur -> next -> prev = cur -> prev;
  delete cur;
}

/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el,const List& li){
	node* cur = li -> next;

  while (cur != li) {
    node* temp = cur -> next;
    if (cur -> info == el) {
      cur -> next -> prev = cur -> prev;
      cur -> prev -> next = cur -> next;
      delete cur; 
    }
    cur = temp;
  }
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
  
/* riempie una lista da file */
void list::readFromFile(string name_file, const List& li){
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline (infile,read_data)){
    if(read_data.length()>0){
      addRear(stoi(read_data),li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List& li){
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  string read_data;
  cin>>read_data;
  while(read_data!="END"){
    addRear(stoi(read_data),li);
    cin>>read_data;
  }
}

/* stampa la lista */
void list::print(const List& li){
  if(li==li->next){
    cout<<"vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    cout << cur->info;
    cur= cur->next;
    if(cur!=li) cout<<" <-> ";
  }
  cout<<endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List& li){
  string out="";
  if(li==li->next){
    out+="vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    out+=to_string(cur->info);
    cur= cur->next;
    if(cur!=li) out+=" <-> ";
  }
  return out;
}
