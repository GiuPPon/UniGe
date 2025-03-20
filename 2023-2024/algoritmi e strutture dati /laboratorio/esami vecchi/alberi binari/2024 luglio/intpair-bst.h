#include <string>
#include <cstddef>

typedef int Elem;

struct intpair{
  Elem v1;
  Elem v2;
};

const intpair noPair={-1000000,-1000000};

struct pairBstNode2{
  Elem el;
  pairBstNode2 *left2;
  pairBstNode2 *right2;
};

struct pairBstNode{
  Elem el;
  pairBstNode2 *bst2;
  pairBstNode *left1;
  pairBstNode *right1;
};

typedef pairBstNode *pairBstTree;

typedef pairBstNode2 *pairBstTree2;

const pairBstTree emptyPairBstTree=nullptr;

const pairBstTree2 emptyPairBstTree2=nullptr;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di coppie nell'albero
unsigned int nbPairs(const pairBstTree&);

//Es 2
//Inserisce una nuova coppia di interi nell'albero
//Ritorna false, se la coppia e' gia' presente e in questo caso non la inserisce
//Altrimenti ritorna true
bool insertPair(intpair, pairBstTree&);

//Es 3
//Ritorna la coppia piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna noPair
intpair minPair(const pairBstTree&);
