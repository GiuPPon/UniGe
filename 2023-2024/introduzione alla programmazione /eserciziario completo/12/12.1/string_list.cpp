#include "string_list.h"
#include <iostream>
using namespace std;

// inserisce un elemento contenente s in testa alla lista l
void headInsert(list &l, string s) {
    // creazione aux
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = l;
    // aux primo elemento di l
    l = aux;
}

// inserisce un elemento contenente s in coda alla lista l
void tailInsert(list &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    // aux -> next = nullptr perchè ultimo elemento (dopo non c'è nulla)
    aux -> next = nullptr;

    // se la lista è vuota, l'unico elemento è aux
    if (l == nullptr) {
        l = aux;
    } else {
        cell *cur = l;
        //sposto cur all'elemento successivo fino a quando l'elemento successivo (next) è nullptr
        while (cur -> next != nullptr) {
            cur = cur -> next;
        }
        //aux diventa l'elemento successivo (next to) di cur
        cur -> next = aux;
    }
}

// legge valori da input e li memorizza nella lista l
// l'inserimento termina se l'utente inserisce "STOP!"
void read(list &l) {
    string s;
    cout << "Inserire valore: ";
    do {
        cin >> s;
        if (s != "STOP!") {
            headInsert(l, s);
        }
    } while (s != "STOP!");
}

/* void read(list &l) {
    string s;
    string stop = "STOP!";
    cin >> s;
    while (s != stop) {
        headInsert(l, s);
        if (s == stop) {
            break;
        }
    }
} */

// stampa tutti gli elementi della lista l
// in linea separati da "->"
void print(const list &l) {
    cell *cur = l;
    while (cur != nullptr) {
        cout << cur -> data;
        if (cur -> next != nullptr) {
            cout << " -> ";
        }
        cur = cur -> next;
    }
}

// ritorna il numero di elementi della lista l
unsigned int size(const list &l) {
    unsigned int count = 0;
    cell *cur = l;
    while (cur != nullptr) {
        ++count;
        cur = cur -> next;
    }
    return count;
}

// ritorna true se la lista l e vuota, false altrimenti
bool isEmpty(const list &l) {
    if (l == nullptr) {
        return true;
    }
    return false;
}

// ritorna il contenuto dell'i-esimo elemento della lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
string getElem(const list &l, unsigned int i) {
    if (l == nullptr) {
        string err = "getElem : lista vuota";
        throw err;
    }
    unsigned int lSize = size(l);
    if ((i <= 0) || (i > lSize)) {
        string err = "getElem : indice invalido";
        throw err;
    }

    cell *cur = l;
    unsigned int count = 0;
    while ((cur != nullptr) || (count < i)) {
        cur = cur -> next;
        ++count;
    }
    return cur -> data;
}

// inserisce un elemento contenente s in posizione i nella lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void insertAt(list &l, string s, unsigned int i) {
    if (l == nullptr) {
        string err = "insertAt : lista vuota";
        throw err;
    }
    unsigned int lSize = size(l);
    if ((i <= 0) || (i > lSize)) {
        string err = "insertAt : indice invalido";
        throw err;
    }

    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    cell *cur = l;
    cell *prev = nullptr;
    int count = 0;

    while ((cur != nullptr) || (count < i)) {
        prev = cur;
        cur = cur -> next;
        ++count;
    }
    // la cella successiva a prev diventa aux e la cella successiva ad aux è cur
    prev -> next = aux;
    aux -> next = cur;
}

// cancella l'elemento in posizione i dalla lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteAt(list &l, unsigned int i) {
    if (l == nullptr) {
        string err = "deleteAt : lista vuota";
        throw err;
    }
    unsigned int lSize = size(l);
    if ((i <= 0) || (i > lSize)) {
        string err = "deleteAt : indice invalido";
        throw err;
    }

    cell *cur = l;
    cell *prev = nullptr;
    int count = 0;

    while ((cur != nullptr) || (count < i)) {
        prev = cur;
        cur = cur -> next;
        ++count;
    }
    // la cella successiva a prev diventa quella che prima era la cella successiva di cur,
    // poi cancello cur
    prev -> next = cur -> next;
    delete cur;
}

// cancella dalla lista l il primo elemento contenente s
// (partendo dall'inizio)
void deleteOnce(list &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;
    while ((cur != nullptr) && (cur -> data != s)) {
        prev = cur;
        cur = cur -> next;
    }
    prev -> next = cur -> next;
    delete cur;
}

// cancella dalla lista l tutti gli elementi contenenti s
void deleteAll(list &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;
    while (cur != nullptr) {
        prev = cur;
        cur = cur -> next;
        if (cur -> data == s) {
            prev -> next = cur -> next;
            delete cur;
        }
    }
}

// Modificare la funzione deleteOnce in modo che restituisca un booleano, vero se l’elemento da 
// cancellare è stato trovato e rimosso, falso altrimenti
bool deleteOnceBool(list &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;
    bool found = false;
    while ((cur != nullptr) && (cur -> data != s)) {
        prev = cur;
        cur = cur -> next;
    }
    if (cur -> data == s) {
        return true;
    }
    return false;
    prev -> next = cur -> next;
    delete cur;
}

// Modificare la funzione deleteAll in modo che restituisca un intero pari al numero di occorrenze 
// trovate e cancellate (0 se la stringa non è presente nella lista, quindi)
int deleteAllCount(list &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;
    int count = 0;
    while (cur != nullptr) {
        prev = cur;
        cur = cur -> next;
        if (cur -> data == s) {
            ++count;
            prev -> next = cur -> next;
            delete cur;
        }
    }
    return count;
}