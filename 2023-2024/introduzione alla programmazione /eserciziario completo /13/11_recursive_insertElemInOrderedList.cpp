/* Scrivere una funzione ricorsiva bool recursive_insertElemInOrderedList(list &l, T x) che dati una 
lista l di elementi di tipo T inserisce il nuovo elemento contenente il valore x nella posizione 
giusta. La funzione restituisce true se l’operazione è andata a buon fine, false altrimenti. 
Verificare con Valgrind che non ci siano memory leaks */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

bool recursive_insertElemInOrderedList(list &l, int x) {
    
    if (l == nullptr || l -> data >= x) {
        // inserimento in testa
        cell *aux = new cell;
        aux -> data = x;
        aux -> next = l;
        l = aux;
        return true;
    } else if (l -> next == nullptr) {
        // inserimento in fondo 
        cell *aux = new cell;
        aux -> data = x;
        aux -> next = nullptr;
        l -> next = aux;
        return true;
    } else {
        return recursive_insertElemInOrderedList(l -> next, x);
    }
}