#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di elementi nella tabella
unsigned int nbElem(const dhash_table& dht){
  unsigned int count = 0;
  for (int i = 0; i < tableDim; ++i) {
    cell *cur = dht.T1[i];
    while (cur != nullptr) {
      ++count;
      cur = cur -> next;
    }
  }
  for (int i = 0; i < tableDim; ++i) {
    cell *cur = dht.T2[i];
    while (cur != nullptr) {
      ++count;
      cur = cur -> next;
    }
  }


  return count;
}


