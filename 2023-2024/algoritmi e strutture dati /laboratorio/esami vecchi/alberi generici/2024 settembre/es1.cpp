#include "dict-tree.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di parole nell' albero
unsigned int nbWords(const dictTree& dt){
  if (dt == emptyDictTree) {
    return 0;
  }

  unsigned int count = 0;

  // scorro (chiamando ricorsivamente) fino a quando il figlio non ha 8 come carattere,
  // e poi richiamo nel brother
    
  if (dt -> val == '8') {
    ++count;
  }
  
  count += nbWords(dt -> son);
  count += nbWords(dt -> brother);

  return count;
}

