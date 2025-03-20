#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) {
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  TragittoElem *aux = new TragittoElem;
  aux -> tappa = t;
  aux -> next = nullptr;
  if (isEmpty(tr)) {
    tr = aux;
  }
  TragittoElem *cur = tr;
  while (cur -> next != nullptr) {
    cur = cur -> next;
  }
  cur -> next = aux;
}

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
// e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  if (isEmpty(tr)) {
    return false;
  }
  TragittoElem *cur = tr;
  t = cur -> tappa;
  tr = cur -> next;
  delete cur;
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  tragitto::TragittoElem *cur = tr;
  while (cur != nullptr) {
    cout << cur -> tappa.distanza << " " << cur -> tappa.citta << endl;
    cur = cur -> next;
  }
}
