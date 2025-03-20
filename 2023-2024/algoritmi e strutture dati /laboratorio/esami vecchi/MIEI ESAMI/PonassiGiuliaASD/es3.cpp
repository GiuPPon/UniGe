#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

// uso la funzione dell'esercizio due come ausiliaria
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

//Es 3
//Inserisce un nuovo elemento
void insert(dhash_table& dht,Elem e){
  int resh1 = h1(e);
  int resh2 = h2(e);

  if (isPresent(dht, e)) {
    return;
  }

  int size1 = 0;
  int size2 = 0;

  cell *cur = dht.T1[h1(e)];

  while (cur != nullptr) {
    ++size1;
    cur = cur -> next;
  }

  cur = dht.T2[h2(e)];

  while (cur != nullptr) {
    ++ size2;
    cur = cur -> next;
  }

  cell *aux = new cell;
  aux -> elem = e;
  aux -> next = nullptr;
  aux -> prev = nullptr;

  if (size1 <= size2) {
    cell *t1 = dht.T1[h1(e)];
    if (t1 == nullptr) {
      t1 = aux;
      return;
    }
    int count = 0;
    while (t1 != nullptr && count < resh1) {
      ++count;
      t1 = t1 -> next;
    }
    
    if (t1 -> prev == nullptr) {
      aux -> next = t1;
      t1 -> prev = aux;
      aux = t1;
      return;
    }
    t1 -> next -> prev = aux;
    aux -> next = t1 -> next;
    t1 -> next = aux;
    aux -> prev = t1;

  } else {
    cell *t2 = dht.T2[h2(e)];
    if (t2 == nullptr) {
      t2 = aux;
      return;
    }
    int count = 0;
    while (t2 != nullptr && count < resh2) {
      ++count;
      t2 = t2 -> next;
    }
    
    if (t2 -> prev == nullptr) {
      aux -> next = t2;
      t2 -> prev = aux;
      aux = t2;
      return;
    }
    t2 -> next -> prev = aux;
    aux -> next = t2 -> next;
    t2 -> next = aux;
    aux -> prev = t2;
  }
}
