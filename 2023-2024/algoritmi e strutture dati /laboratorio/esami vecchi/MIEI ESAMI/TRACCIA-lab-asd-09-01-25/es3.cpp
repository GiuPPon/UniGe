#include "set-dll.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 3
//Cancella dell'insieme la coppia (v1,v2)
//Se la coppia non e' presente non fa nulla
void deletePair(set_list& li,int v1,int v2) {
  int somma = v1 + v2;

  if (li == empty_set_list) {
    return;
  }

  set_node *cur = li;

  while (cur != nullptr) {
    if (cur -> sum == somma) {
      pair_node* curpairs = cur -> pairs;
      while (curpairs != nullptr) {
        if ((curpairs -> v1 == v1) && (curpairs -> v2 == v2)) {
          if (curpairs -> prev_pair == nullptr) { // caso in testa
            cur -> pairs = curpairs -> next_pair;
            if (cur -> pairs != nullptr) {
              cur -> pairs -> prev_pair = nullptr;
            }
          } else {
            if (curpairs -> next_pair != nullptr) {
              curpairs -> next_pair -> prev_pair = curpairs -> prev_pair;
            }
            curpairs -> prev_pair -> next_pair = curpairs -> next_pair;
          }
          delete curpairs;

          if (cur -> pairs == nullptr) {
            if (cur -> prev == nullptr) {   // se è il primo nodo della lista principale
              li = cur -> next;
              if (li != nullptr) {
                li -> prev = nullptr;
              }
            } else {
              cur -> prev -> next = cur -> next;
              if (cur -> next != nullptr) {
                cur -> next -> prev = cur -> prev;
              }  
            }
            delete cur;
          }
          return;
        }
        curpairs = curpairs -> next_pair;
      }
    }
    cur = cur -> next;
  }
  
}
