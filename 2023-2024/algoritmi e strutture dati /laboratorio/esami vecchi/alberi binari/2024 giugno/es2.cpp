#include "trinary-tree.h"

void deleteAll(Elem el, triTree& tr){

  if (tr == nullptr) {
    return; // Se il nodo è nullo, ritorna
  }

  if (tr -> el == el) {
    delete tr;
    tr = nullptr;
  }

  deleteAll(el, tr -> child1);
  deleteAll(el, tr -> child2);
  deleteAll(el, tr -> child3);

}

