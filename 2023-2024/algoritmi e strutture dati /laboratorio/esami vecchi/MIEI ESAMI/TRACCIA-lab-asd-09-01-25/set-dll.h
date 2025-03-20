#ifndef SET_DLL_H
#define SET_DLL_H

struct pair_node{
  int v1;
  int v2;
  pair_node* next_pair;
  pair_node* prev_pair;
};


struct set_node{
  int sum;
  pair_node* pairs;
  set_node* next;
  set_node* prev;
};

typedef set_node* set_list;

typedef pair_node* pair_list;

const set_list empty_set_list=nullptr;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 1
//Ritorna il numero di coppie nell'insieme
unsigned int nbPairs(const set_list&);

//Es 2
//Aggiunge una coppia (v1,v2) all'insieme
//Se la coppia e' gia' presente, non fa nulla
void addPair(set_list&,int v1,int v2);

//Es 3
//Cancella dell'insieme la coppia (v1,v2)
//Se la coppia non e' presente non fa nulla
void deletePair(set_list&,int v1,int v2);
#endif
