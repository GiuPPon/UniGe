#include <string>
#include <cstddef>

typedef char Elem;

struct dictNode{
  Elem val;
  dictNode *brother;
  dictNode *son;
};

typedef dictNode *dictTree;

const dictTree emptyDictTree=nullptr;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 1
//Ritorna il numero di parole nell'dizionario
unsigned int nbWords(const dictTree&);

//Es 2
//Verifica se una parola e' nell'dizionario
//Ritorna true se e' presente e false altrimenti
bool isPresent(std::string, const dictTree&);

//Es 3
//Ritorna la parola piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna la string vuota ""
std::string minWord(const dictTree&);
