#ifndef SETDLL
#define SETDLL

#include <iostream>

struct set_cell{
    int data;
    set_cell* next;
    set_cell* prev;
};
typedef set_cell* set_dll; //dll => double linked list

// NB: set_dll DEVE essere implementato tramite una lista con le seguenti caratteristiche:
// - doppiamente linkata
// - circolare
// - ordinata
// - senza ripetizioni

void insert_set_dll(set_dll &s, int v);
// inserisce un nuovo elemento (con data = v) nel set s

void print_set_dll(const set_dll &s);
// stampa il contenuto set s dal primo all'ultimo elemento
// (in linea con elementi separati da "->")

void revprint_set_dll(const set_dll &s);
// stampa il contenuto set s dall'ultimo al primo elemento
// (in linea e con elementi separati da "->")

set_dll union_set_dll(const set_dll &s1, const set_dll &s2);
// ritorna un set che rappresenta l'unione dei set s1 e s2
// NB: ogni elemento del nuovo set deve essere un duplicato di quelli contenuti in s1 e s2
// in questo modo sia s1 che s2 non subiscono alcuna modifica

set_dll intersect_set_dll(const set_dll &s1, const set_dll &s2);
// ritorna un set che rappresenta l'intersezione dei set s1 e s2
// NB: ogni elemento del nuovo set deve essere un duplicato di quelli contenuti in s1 e s2
// in questo modo sia s1 che s2 non subiscono alcuna modifica

#endif