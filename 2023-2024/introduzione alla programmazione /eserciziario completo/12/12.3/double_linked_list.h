#ifndef double_linked_list
#define double_linked_list

#include<string>
#include <iostream>
using namespace std;

struct cell{ // elemento della lista
    string data;
    cell* next;
    cell* prev;
};
typedef cell* list;

void headInsert(list &l, string s);
// inserisce un elemento contenente s in testa alla lista l
void tailInsert(list &l, string s);
// inserisce un elemento contenente s in coda alla lista l
void read(list &l);
// legge valori da input e li memorizza nella lista l
// l'inserimento termina se l'utente inserisce "STOP!"
void print(const list &l);
// stampa tutti gli elementi della lista l
// in linea separati da "->"
unsigned int size(const list &l);
// ritorna il numero di elementi della lista l
bool isEmpty(const list &l);
// ritorna true se la lista l e vuota, false altrimenti
string getElem(const list &l, unsigned int i);
// ritorna il contenuto dell'i-esimo elemento della lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void insertAt(list &l, string s, unsigned int i);
// inserisce un elemento contenente s in posizione i nella lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteAt(list &l, unsigned int i);
// cancella l'elemento in posizione i dalla lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteOnce(list &l, string s);
// cancella dalla lista l il primo elemento contenente s
// (partendo dall'inizio)
void deleteAll(list &l, string s);
// cancella dalla lista l tutti gli elementi contenenti s
void printReverse(const list &l);
// stampa la lista dall’ultimo elemento al primo seguendo i campi prev

#endif