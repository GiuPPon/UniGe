#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 3
//Ritorna la coppia piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna noPair
intpair minPair(const pairBstTree& pbst){
  if (pbst == nullptr) {
    return noPair;
  }

  intpair ret;
  
  if (pbst -> right1 -> el > pbst -> left1 -> el) {
    ret.v1 = pbst -> left1 -> el;
  } else {
    ret.v1 = pbst -> right1 -> el;
  }

  if (pbst -> bst2 -> right2 -> el > pbst -> bst2 -> left2 -> el) {
    ret.v2 = pbst -> bst2 -> left2 -> el;
  } else {
    ret.v2 = pbst -> bst2 -> right2 -> el;
  }
  ret = minPair(pbst -> left1);
  return ret;
}

