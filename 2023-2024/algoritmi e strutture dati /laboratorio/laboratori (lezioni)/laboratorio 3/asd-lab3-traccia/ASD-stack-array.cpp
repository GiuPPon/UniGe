// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include <string>

#include "ASD-stack-array.h"

using namespace stack;
using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/
/* restituisce lo stack vuoto */
Stack stack::createEmpty(){
	Stack sret;                          // creo stack
   sret.size = 0;
   sret.maxsize = BLOCKDIM;
   sret.data = new Elem[sret.maxsize];  // alloco array di elem con dimensione maxsize (dove inserisco gli elementi)
	return sret;
}

/* restituisce true se lo stack e' vuoto */
bool stack::isEmpty(const Stack& st){
	return (st.size == 0);
}

/* aggiunge elem in cima (operazione safe, si può sempre fare) */
void stack::push(const Elem el, Stack& st){
   if (st.size == st.maxsize) {
      unsigned int newsize = st.maxsize + 10;            // aggiungo 10 unità di spazio al maxsize 
      Elem *temp = new Elem[newsize];                    // array temporaneo dove salvo gli elementi 
      for (unsigned int i = 0; i < st.size; ++i) {
         temp[i] = st.data[i];
      }
      delete[] st.data;                     // cancello l'array con dimensione più piccola 
      st.data = temp;                       // l'array temporaneo diventa quello principale
      st.maxsize = newsize;                 // aumento maxsize
   }
   ++st.size;                    // aumento size
   st.data[st.size - 1] = el;    // l'ultimo elemento diventa l'elemento da inserire
}

/* toglie dallo stack l'ultimo elemento e lo restituisce */
/* se lo stack è vuoto solleva una eccezione di tipo string */
Elem stack::pop(Stack& st){
   if (st.size == 0) {
      string err = "errore";
      throw err;
   }
   Elem ret;
   ret = st.data[st.size - 1];     // salvo l'ultimo elemento
   --st.size;                      // diminuisco size (quindi elimino l'ultimo elemento)
   return ret;
}	

/* restituisce l'ultimo elemento dello stack senza toglierlo.*/
/* Se lo stack è vuoto solleva una eccezione di tipo string*/
Elem stack::top(Stack& st){
   if (st.size == 0) {
      string err = "errore";
      throw err;
   }
	Elem ret;
   ret = st.data[st.size - 1];     // salvo l'ultimo elemento 
	return ret;                     // lo ritorno
} 


/**************************************************/
/*      funzioni implementate                    */
/**************************************************/

/* riempie lo stack da file */
Stack stack::readFromFile(std::string name_file){
   ifstream infile;
   string read_data;
   infile.open(name_file);
   Stack sret=createEmpty();
   while (getline (infile,read_data)){
      if(read_data.length()>0){
         push(stoi(read_data),sret);
      } 
   }
   return sret;
}

/* legge il contenuto di uno stack da standard input */
Stack stack::readFromStdin(){
   cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
   Stack sret=createEmpty();
   string read_data;
   cin>>read_data;
   while(read_data!="END"){
      push(stoi(read_data),sret);
      cin>>read_data;
   }
   return sret;
}

/* stampa lo stack*/
void stack::print(const Stack& st){
   cout<<tostring(st)<<endl;
}

/* produce una stringa contenente lo stack*/
std::string stack::tostring(const Stack& st){
   string out="";
   out+="{";
   unsigned int pos=0;
   while(pos<st.size){
      out+=to_string(st.data[pos]);
      if(pos+1!=st.size){
         out+=",";
      }
      ++pos;
   }
   out+="}";
   return out;
}

