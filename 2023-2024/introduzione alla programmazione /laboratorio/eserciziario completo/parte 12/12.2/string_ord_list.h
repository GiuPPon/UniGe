#ifndef STRINGORDLIST
#define STRINGORDLIST

#include <string>
#include <iostream>
using namespace std;

struct cell{ // elemento della lista
    string data;
    cell* next;
};
typedef cell* ordList;

void insertElement(ordList &l, string s);
// inserisce un elemento contenente s nella lista ordinata l mantenendo la lista ordinata

void readList(ordList &l);
// legge valori da input e li memorizza (aggiunge) nella lista ordinata l
// al termine dell'esecuzione di readList la lista l deve essere una lista ordinata.
// l'inserimento termina se l'utente inserisce "STOP!"
// NB: differente rispetto alla versione per liste non ordinate

void printList(const ordList &l);
// stampa tutti i valori (data) degli elementi della lista ordinata l in linea separati da "->"
// NB: nessuna variazione rispetto alla versione per liste non ordinate

unsigned int listSize(const ordList &l);
// ritorna il numero di elementi della lista ordinata l
// NB: nessuna variazione rispetto alla versione per liste non ordinate

bool isEmptyList(const ordList &l);
// ritorna true se la lista ordinata l e vuota, false altrimenti
// NB: nessuna variazione rispetto alla versione per liste non ordinate

string getElement(const ordList &l, unsigned int i);
// ritorna il contenuto dell'i-esimo elemento della lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
// NB: nessuna variazione rispetto alla versione per liste non ordinate

void deleteElementAt(ordList &l, unsigned int i);
// cancella l'elemento in posizione i dalla lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
// NB: nessuna variazione rispetto alla versione per liste non ordinate

void deleteElementOnce(ordList &l, string s);
// cancella dalla lista ordinata l il primo elemento contenente s
// NB: nessuna variazione rispetto alla versione per liste non ordinate

void deleteAllElements(ordList &l, string s);
// cancella dalla lista ordinata l tutti gli elementi contenenti s
// NB: deve essere ottimizzata rispetto alla versione per liste non ordinate

bool listAreEqual(const ordList &l1, const ordList &l2);
// restituisce true se le due liste contengono le stesse stringhe (con la stessa molteplicità)
// false altrimenti

ordList concatLists(const ordList &l1, const ordList &l2);
// restituisce una nuova lista ordinata contenente gli elementi delle 2 liste ordinate l1 e l2
// Il numero di occorrenze di un elemento nel risultato
// è la somma del numero delle sue occorrenze nelle due liste l1 e l2
// NB: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
// in questo modo sia l1 che l2 non subiscono alcuna modifica

ordList unionLists(const ordList &l1, const ordList &l2);
// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in almeno una delle due liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
// in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare il fatto che
// le due liste sono ordinate per minimizzare il numero di operazioni necessarie

ordList intersectLists(const ordList &l1, const ordList &l2);
// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in entrambe le liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
// in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare il fatto che
// le due liste sono ordinate per minimizzare il numero di operazioni necessarie

#endif