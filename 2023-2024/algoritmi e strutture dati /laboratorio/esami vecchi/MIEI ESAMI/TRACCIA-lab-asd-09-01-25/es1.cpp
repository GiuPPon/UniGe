#include "set-dll.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di coppie nell'insieme
unsigned int nbPairs(const set_list& li){
  if (li == empty_set_list) {
    return 0;
  }

  unsigned int count = 0;
  pair_node *cur = li -> pairs;

  while (cur != nullptr) {
    ++count;
    cur = cur -> next_pair;
  }

  count += nbPairs(li -> next);

  return count;
}