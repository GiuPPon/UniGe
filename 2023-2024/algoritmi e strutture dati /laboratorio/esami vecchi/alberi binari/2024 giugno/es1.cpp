#include "trinary-tree.h"

unsigned int nbOccurrence(Elem el,const triTree& tr){
  
  unsigned int index = 0;

  if (tr == nullptr) {
    return 0; // Se il nodo è nullo, ritorna 0
  }

  if (tr -> el == el) {
    ++index;
  }

  index += nbOccurrence(el,tr -> child1);
  index += nbOccurrence(el,tr -> child2);
  index += nbOccurrence(el,tr -> child3);

  return index;

}
