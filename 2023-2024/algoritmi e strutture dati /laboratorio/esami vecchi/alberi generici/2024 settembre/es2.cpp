#include "dict-tree.h"

using namespace std;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 2
//Verifica se una parola è nell'dizionario
//Ritorna true se è presente e false altrimenti
bool isPresent(string st, const dictTree& dt){
  if (dt == emptyDictTree) {
    return false;
  }

  dictNode *cur = dt;

  for (unsigned int i = 0; i < st.size(); ++i) {
    while (cur != nullptr && cur -> val != st[i]) {   // scorro i fratelli fino a quando non trovo la lettera
      cur = cur -> brother;
    }
    if (cur == nullptr) {
      return false;
    }
    cur = cur -> son;   // se viene trovata vado nel figlio (per trovare le altre lettere che compongono la frase)
  }

  while (cur != nullptr) {
    if (cur -> val == '8') {
      return true; // parola presente e finita
    }
    cur = cur -> brother;
  }

  return false;
}
