/* Scrivere una funzione ricorsiva void recursive_reversePrintList(const list &l) che stampa il 
contenuto della lista su una singola riga con elementi separati da spazio " ": (es. 21 10 6 5 1). */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

void recursive_reversePrintList(const list &l) {
    // stampa 
    if (l != nullptr) {
        /* Una volta raggiunto il nodo finale, inizierà a risalire all'indietro, stampando il contenuto
        di ogni nodo man mano che torna indietro. Alla fine, l'output sarà il contenuto della lista 
        stampato al contrario. */
        recursive_reversePrintList(l -> next); 
        cout << l -> data << " ";
    }
}

void insertElemInOrderedList(list &l, int n) {
    // Base case: if the list is empty or n should be inserted at the beginning
    if ((l == nullptr) || (l -> data > n)) {
        cell *aux = new cell;
        aux -> data = n;
        aux -> next = l;
        l = aux;
    } else {
        insertElemInOrderedList(l -> next, n); 
    }
}

int main () {
    list list = nullptr; 
    insertElemInOrderedList(list, 5);
    insertElemInOrderedList(list, 21);
    insertElemInOrderedList(list, 6);
    insertElemInOrderedList(list, 1);
    insertElemInOrderedList(list, 10);
    recursive_reversePrintList(list);
}