/*NON MODIFICARE*/
#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

typedef unsigned int Elem;

struct cell{
  Elem elem;
  cell* next;
  cell* prev;
};

typedef cell* dllist;

const dllist emptydllist=nullptr;

const int tableDim=10;

struct dhash_table{
  dllist* T1;
  dllist* T2;
};

unsigned int h1(Elem);

unsigned int h2(Elem);

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 1
//Ritorna il numero di elementi nella tabella
unsigned int nbElem(const dhash_table&);

//Es 2
//Verifica se un elemento e' presente
bool isPresent(const dhash_table&,Elem);

//Es 3
//Inserisce un nuovo elemento
void insert(dhash_table&,Elem);
#endif
