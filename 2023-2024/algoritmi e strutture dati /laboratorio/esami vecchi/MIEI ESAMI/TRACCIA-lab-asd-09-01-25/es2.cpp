#include "set-dll.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 2
//Aggiunge una coppia (v1,v2) all'insieme
//Se la coppia e' gia' presente, non fa nulla
void addPair(set_list& li,int v1,int v2){
  int somma = v1 + v2;

  pair_node *aux = new pair_node;
  aux -> v1 = v1;
  aux -> v2 = v2;
  aux -> next_pair = nullptr;
  aux -> prev_pair = nullptr;

  if (li == empty_set_list) {
    set_node *nuovo = new set_node;
    nuovo -> sum = somma;
    nuovo -> pairs = aux;
    nuovo -> next = nullptr;
    nuovo -> prev = nullptr;
    li = nuovo;
    return;
  }

  set_node *cur = li;

  while (cur != nullptr) {

    if (cur -> sum == somma) {

      pair_node *curpairs = cur -> pairs;

      while (curpairs != nullptr) {
        if ((curpairs -> v1 == v1) && (curpairs -> v2 == v2)) {
          return;                   // coppia esiste già, non facciamo nulla
        }
        curpairs = curpairs -> next_pair;
      }

      if (cur -> pairs != nullptr) {
        cur -> pairs -> prev_pair = aux;
        aux -> next_pair = cur -> pairs;
      }
      cur -> pairs = aux;
      return;

    }
    cur = cur -> next;
  }

  // somma non è stata trovata
  set_node *nuovo = new set_node;
  nuovo -> sum = somma;
  nuovo -> pairs = aux;
  nuovo -> next = li;           // inseriamo in testa alla lista principale
  nuovo -> prev = nullptr;

  if (li != nullptr) {
    li -> prev = nuovo;
  }
  li = nuovo;
}