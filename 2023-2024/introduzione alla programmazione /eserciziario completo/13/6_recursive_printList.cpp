/* Scrivere una funzione ricorsiva void recursive_printList(const list &l) che stampa il contenuto 
della lista su una singola riga con elementi separati da spazio " ": (es. 1 5 6 10 21). Confrontare la
stampa di questa funzione con quella standard al punto precedente. */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

void recursive_printList(const list &l) {
    if (l != nullptr) {
        cout << l -> data << " ";
        recursive_printList(l->next); 
    }
}
