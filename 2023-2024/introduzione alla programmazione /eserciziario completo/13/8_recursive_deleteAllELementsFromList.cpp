/* Scrivere una funzione ricorsiva void recursive_deleteAllElementsFromList(list &l) che elimina tutti
gli elementi dalla lista e alla fine assegna l = nullptr. */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

void recursive_deleteAllElementsFromList(list &l) {
    if (l != nullptr) {
        recursive_deleteAllElementsFromList(l -> next);
        delete l;
        l = nullptr;
    }
}

void recursive_reversePrintList(const list &l) {
    if (l != nullptr) {
        recursive_reversePrintList(l -> next); 
        cout << l -> data << " ";
    }
}

void insertElemInOrderedList(list &l, int n) {
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
    cout << "Lista prima : ";
    recursive_reversePrintList(list);
    cout << endl;
    recursive_deleteAllElementsFromList(list);
    cout << "Lista dopo : ";
    recursive_reversePrintList(list);
}