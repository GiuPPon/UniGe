#include "set_dll.h"
#include <iostream>
using namespace std;

// inserisce un nuovo elemento (con data = v) nel set s
void insert_set_dll(set_dll &s, int v) {
    set_cell *aux = new set_cell;
    aux -> data = v;

    if (s == nullptr) {
        s = aux;
        // double linked e circolare
        s -> next = s;
        s -> prev = s;
        return;
    }

    set_cell *cur = s;
    // cur -> next != s perchè è circolare
    // cur -> next -> data < s perchè è una lista ordinata
    while ((cur -> next != s) && (cur -> next -> data < v)) {
        cur = cur -> next;
    }

    // Se l'elemento inserito è minore del primo elemento, aggiorna il puntatore s
    if (v < s -> data) {
        s = aux;
    }

    aux -> next = cur -> next;
    aux -> prev = cur;
    cur -> next -> prev = aux;
    cur -> next = aux;
}

// stampa il contenuto set s dal primo all'ultimo elemento
// (in linea con elementi separati da "->")
void print_set_dll(const set_dll &s) {
    set_cell *cur = s;

    cout << cur -> data;
    cur = cur -> next;
    
    while (cur != s) {
        cout << " -> " << cur -> data;
        cur = cur -> next;
    }
    cout << endl;
}

// stampa il contenuto set s dall'ultimo al primo elemento
// (in linea e con elementi separati da "->")
void revprint_set_dll(const set_dll &s) {
    set_cell *cur = s -> prev;

    do {
        cout << cur -> data;
        if (cur -> prev != s -> prev) {
            cout << " -> ";
        }
        cur = cur -> prev;
    } while (cur != s -> prev);
    cout << endl;
}

// ritorna un set che rappresenta l'unione dei set s1 e s2
// NB: ogni elemento del nuovo set deve essere un duplicato di quelli contenuti in s1 e s2
// in questo modo sia s1 che s2 non subiscono alcuna modifica
set_dll union_set_dll(const set_dll &s1, const set_dll &s2) {
    set_dll unione = nullptr;

    set_cell *cur1 = s1;
    set_cell *cur2 = s2;

    while ((cur1 != nullptr) && (cur2 != nullptr)) {
        if (cur1 -> data < cur2 -> data) {
            insert_set_dll(unione, cur1 -> data);
            cur1 = cur1 -> next;
        } else if (cur1 -> data > cur2 -> data) {
            insert_set_dll(unione, cur2->data);
            cur2 = cur2 -> next;
        } else {
            // se duplicato, inserisco solo uno e scorro entrambi
            insert_set_dll(unione, cur1 -> data);
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
    }

    while (cur1 != nullptr) {
        insert_set_dll(unione, cur1 -> data);
        cur1 = cur1 -> next;
    }

    while (cur2 != nullptr) {
        insert_set_dll(unione, cur2 -> data);
        cur2 = cur2 -> next;
    }

    return unione;
}

// ritorna un set che rappresenta l'intersezione dei set s1 e s2
// NB: ogni elemento del nuovo set deve essere un duplicato di quelli contenuti in s1 e s2
// in questo modo sia s1 che s2 non subiscono alcuna modifica
set_dll intersect_set_dll(const set_dll &s1, const set_dll &s2) {
    set_dll intersezione = nullptr;

    set_cell *cur1 = s1;
    set_cell *cur2 = s2;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1 -> data < cur2 -> data) {
            cur1 = cur1 -> next;
        } else if (cur1 -> data > cur2 -> data) {
            cur2 = cur2 -> next;
        } else {
            // se duplicato, inserisco solo uno e scorro entrambi
            insert_set_dll(intersezione, cur1 -> data);
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
    }

    return intersezione;
}