/* Per poter popolare e visualizzare una lista sulla quale testare le funzioni ricorsive da implementare
nei prossimi punti di questo esercizio per prima cosa riprendiamo due funzioni di base dall’esercizio 
2 della Parte 12, implementate in modo standard (cioè non ricorsivo):
• void insertElement(list &l, T s)
• void printList(const list &l)
– Rinominare la insertElement in insertElemInOrderedList e adattarla al fatto che questa volta si 
trattano liste senza ripetizione degli elementi (cioè se un elemento è già presente non lo inserisce).
– Modificare la printList in modo che stampi semplicemente gli elementi separati da spazio 
(es. 1 5 6 10 21).
– Creare una lista e stamparla e verificare che tutto funzioni. */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

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

void printList(const list &l) {
    cell *cur = l;
    while (cur != nullptr) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << endl;
}

int main () {
    list list = nullptr;
    insertElemInOrderedList(list, 5);
    insertElemInOrderedList(list, 21);
    insertElemInOrderedList(list, 6);
    insertElemInOrderedList(list, 1);
    insertElemInOrderedList(list, 10);
    printList(list);
}