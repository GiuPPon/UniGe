/* Scrivere una funzione ricorsiva unsigned recursive_ListLength(const list &l) che calcola la 
lunghezza di una lista l. */

#include <iostream>
using namespace std;

struct cell{
    int data;
    cell* next;
};
typedef cell* list;

unsigned recursive_ListLength(const list &l) {
    if (l == nullptr) {
        return 0;
    } else {
        return 1 + recursive_ListLength(l -> next);
    }
}