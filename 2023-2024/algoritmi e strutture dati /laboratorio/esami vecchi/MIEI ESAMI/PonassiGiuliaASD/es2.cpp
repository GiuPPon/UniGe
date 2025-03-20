#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 2
//Verifica se un elemento e' presente
bool isPresent(const dhash_table& dht,Elem e){
  cell *cur = dht.T1[h1(e)];

  while (cur != nullptr) {
    if (cur -> elem == e) {
      return true;
    }
    cur = cur -> next;
  }

  cur = dht.T2[h2(e)];

  while (cur != nullptr) {
    if (cur -> elem == e) {
      return true;
    }
    cur = cur -> next;
  }

  return false;
}
