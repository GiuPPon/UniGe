// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include <string>

#include "ASD-queue-list.h"

using namespace queue;
using namespace std;

//implementazione di una doubly linked list
struct queue::cell{
   Elem el;
   cell *next;
   cell *prev;
};

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

/* restituisce la coda vuota */
Queue queue::createEmpty(){
   Queue qret;
   qret.li = nullptr;
   qret.end = nullptr;
   return qret;
} 

/* restituisce true se la queue e' vuota */
bool queue::isEmpty(const Queue& q){
   return (q.end == nullptr);
}

/* inserisce l'elemento "da una parte" della coda */
void queue::enqueue(Elem e, Queue& q){
   cell *aux = new cell;       // creo una nuova cella
   aux -> el = e;
   aux -> prev = nullptr;
   aux -> next = nullptr;
   if(isEmpty(q)) {        // se la queue è vuota
      q.li = aux;          // li è aux
      q.end = aux;         // l'ultimo elemento è aux
      return; 
   }
   /*                                        // caso in coda
   cell *cur = q.li;                         // creo cur
   while (cur -> next != nullptr) {          // scorro fino alla fine della queue
      cur = cur -> next;
   }
   aux -> prev = cur;                        // il prev del nuovo elemento è cur
   aux = q.end;                              // il nuovo elemento è anche l'ultimo elemento
   
   */                      // caso testa
   aux -> next = q.li;     // il next di aux è li (ossia il vecchio primo elemento)
   q.li -> prev = aux;     // collego il prev di li ad aux
   q.li = aux;             // aux diventa il nuovo li (ossia il nuovo primo elemento)
}


/* cancella l'elemento (se esiste) "dall'altra parte */
/*della coda" e lo restituisce; se la coda è vuota solleva */
/*una eccezione di tipo string*/
Elem queue::dequeue(Queue& q){
   Elem ret;
   if (isEmpty(q)) {
      string err = "errore";
      throw err;
   }
   /*                                // caso testa
   ret = q.li -> el;                 // salvo il primo elemento della queue (elemento di li)
   cell *temp = q.li -> next;        // creo una cella temporanea con valore li -> next
   delete q.li;                      // elimino li (ossia primo elemento lista)
   q.li = temp;                      // li diventa il suo next (temp)
   return ret;
   */                                // caso coda
   if (q.li == q.end) {              // se c'è solo un elemento
      ret = q.end -> el;                   // salvo l'ultimo (e unico) elemento 
   //   delete q.end;
      delete q.li;                         // elimino l'elemento
      q.li = nullptr;                      // quindi li è null
      q.end = nullptr;                     //   --   end   --
      return ret;                          // ritorno l'unico elemento
   }
   ret = q.end -> el;               // salvo l'ultimo elemento 
   cell *temp = q.end -> prev;      // creo una cella con valore penultimo elemento
   temp -> next = nullptr;          // con next nullo
   delete q.end;                    // elimino ultimo elemento
   q.end = temp;                    // l'ultimo elemento è ora temp (penultimo elemento)
   return ret;                      // ritorno l'ultimo elemento
}

/* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo*/ 
/*se la coda è vuota solleva una eccezione di tipo string*/
Elem queue::first(Queue& q){
   if (isEmpty(q)) {
      string err = "errore";
      throw err;
   }
   return q.end -> el;        // ritorno l'elemento di end
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
/* riempie una coda da file */
Queue queue::readFromFile(std::string name_file){
   ifstream infile;
   string read_data;
   infile.open(name_file);
   Queue qret=createEmpty();
   while (getline (infile,read_data)){
      if(read_data.length()>0){
         enqueue(stoi(read_data),qret);
      } 
   }
   return qret;
}

/* legge il contenuto di una coda da standard input */
Queue queue::readFromStdin(){
   cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
   Queue qret=createEmpty();
   string read_data;
   cin>>read_data;
   while(read_data!="END"){
      enqueue(stoi(read_data),qret);
      cin>>read_data;
   }
   return qret;
}

/* stampa la coda*/
void queue::print(const Queue& q){
   cout<<tostring(q)<<endl;
}

/* produce una string contenente la coda*/
std::string queue::tostring(const Queue& q){
   string out="";
   out+="{";
   list l=q.li;
   while(l!=EMPTYLIST){
      out+=to_string(l->el);
      if(l!=q.end){
         out+=",";
      }
      l=l->next;
   }
   out+="}";
   return out;
}

