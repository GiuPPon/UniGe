/* Scrivere una funzione ricorsiva bool recursive_isElementInOrderedList(const list &l, T x) per 
implementare la ricerca di un elemento di tipo T nella list l. Ottimizzare la funzione grazie al fatto
che sappiamo che la lista è ordinata. */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

bool recursive_isElementInOrderedList(const list &l, int x) {
    if (l == nullptr) {
        return false;
    }
    // Se il valore del nodo corrente è uguale a x, restituisci true
    if (l -> data == x) {
        return true; 
    } else if (l -> data > x) {
        // Se il valore del nodo corrente è maggiore di x, x non può essere presente nella lista
        return false; 
    } else {
        return recursive_isElementInOrderedList(l -> next, x);
    }
}