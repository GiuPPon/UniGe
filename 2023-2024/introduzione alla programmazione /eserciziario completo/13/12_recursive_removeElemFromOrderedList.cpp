/* Scrivere una funzione ricorsiva bool recursive_removeElemFromOrderedList(list &l, T x) che dati una
lista l di elementi di tipo T elimina l’elemento x dalla lista (che è sempre unico). La funzione 
restituisce true se l’operazione è andata a buon fine, false altrimenti. Verificare con Valgrind che 
non ci siano memory leaks. */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

bool recursive_removeElemFromOrderedList(list &l, int x) {
    if (l == nullptr) {
        return false;
    }
    if (l -> data == x) {
        // Se l'elemento da eliminare è nel primo nodo, elimina il nodo e restituisci true
        cell *aux = l;
        l = aux -> next;
        delete aux;
        return true;
    } else if (l -> next != nullptr && l -> next -> data == x) {
        // Se l'elemento da eliminare è nel nodo successivo, elimina il nodo e restituisci true
        cell *aux = l -> next;
        aux = aux -> next;
        delete aux;
        return true;
    } else {
        return recursive_removeElemFromOrderedList(l -> next, x);
    }
}