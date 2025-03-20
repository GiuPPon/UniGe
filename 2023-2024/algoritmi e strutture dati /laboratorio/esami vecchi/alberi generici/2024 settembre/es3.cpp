#include "dict-tree.h"

using namespace std;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 3
//Ritorna la parola piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna la string vuota ""
string minWord(const dictTree& dt){
  if (dt == emptyDictTree) {
    return "";
  }

  string word = "";
  dictNode *cur = dt;

  while (cur != nullptr) {
    if (cur -> val == '8') {
      return word; // Se troviamo '8', ritorna la parola costruita finora
    }

    word += cur -> val; // Aggiungi la lettera corrente
    cur = cur -> son;   // Vai al figlio per continuare la parola
  }

  return word;
}

