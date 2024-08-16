#include "double_linked_list.h"
using namespace std;

// inserisce un elemento contenente s in testa alla lista l
void headInsert(list &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    aux -> prev = nullptr;
    aux -> next = nullptr;

    if (l == nullptr) {
        l = aux;
        return;
    }

    l -> prev = aux;
    aux -> next = l;
    l = aux;
}

// inserisce un elemento contenente s in coda alla lista l
void tailInsert(list &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    if (l == nullptr) {
        aux -> prev = nullptr;
        l = aux;
        return;
    }

    cell *cur = l;
    // scorro fino all'ultimo elemento della lista
    while (cur -> next != nullptr) {
        cur = cur -> next;
    }
    
    aux -> prev = cur;
    cur -> next = aux;
}

// legge valori da input e li memorizza nella lista l
// l'inserimento termina se l'utente inserisce "STOP!"
void read(list &l) {
    string s;
    cout << "Inserire valori: ";
    do {
        cin >> s;
        if (s != "STOP!") {
            headInsert(l, s);
        } 
    } while (s != "STOP!");
}

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
    cout << endl;
}

// ritorna il numero di elementi della lista l
unsigned int size(const list &l) {
    cell *cur = l;
    unsigned int count = 0;
    while (cur != nullptr) {
        cur = cur -> next;
        ++count;
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
    if ((i < 0) || (i >= size(l))) {
        string err = "getElem : indice invalido";
        throw err;
    }

    cell *cur = l;
    unsigned int count = 0;
    while ((cur != nullptr) && (count < i)) {
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
    if ((i < 0) || (i >= size(l))) {
        string err = "insertAt : indice invalido";
        throw err;
    }

    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;
    aux -> prev = nullptr;

    if (i == 0) {
        aux -> next = l;
        l -> prev = aux;
        // aux -> prev = nullptr;
        aux = l;
        return;
    }

    cell *cur = l;
    unsigned int count = 0;
    while((cur != nullptr) && (count < i)) {
        cur = cur -> next;
        ++count;
    }
    cur -> prev -> next = aux;
    aux -> prev = cur -> prev;
    aux -> next = cur;
    cur -> prev = aux;

}

// cancella l'elemento in posizione i dalla lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteAt(list &l, unsigned int i) {
    if (l == nullptr) {
        string err = "deleteAt : lista vuota";
        throw err;
    }
    if ((i < 0) || (i >= size(l))) {
        string err = "deleteAt : indice invalido";
        throw err;
    }

    cell *cur = l;

    if (i == 0) {
        // controllare
        l = l -> next;
        delete cur;
    }

    unsigned int count = 0;
    while ((cur != nullptr) && (count < i)) {
        cur = cur -> next;
        ++count;
    }
    cur -> prev -> next = cur -> next;
    cur -> next -> prev = cur -> prev;
    delete cur;
}

// cancella dalla lista l il primo elemento contenente s
// (partendo dall'inizio)
void deleteOnce(list &l, string s) {
    if (l == nullptr) {
        string err = "deleteOnce : lista vuota";
        throw err;
    }

    cell *cur = l;

    while ((cur != nullptr) || (cur -> data != s)) {
        cur = cur -> next;
    }

    if ((cur != nullptr) && (cur -> data == s)) {
        // se devo eliminare il primo elemento
        if (cur -> prev == nullptr) {
            l = cur -> next;
            delete cur;
        } else {
            // il next del prev di cur diventa il next di cur e deleto cur
            cur -> prev -> next = cur -> next;
            cur -> next -> prev = cur -> prev;
            delete cur;
        }
    } else {
        string err = "Elemento non trovato";
        throw err;
    }
}

// cancella dalla lista l tutti gli elementi contenenti s
void deleteAll(list &l, string s) {
    if (l == nullptr) {
        string err = "deleteAll : lista vuota";
        throw err;
    }

    cell *cur = l;

    while (cur != nullptr) {
        cur -> prev = cur;
        cur = cur -> next;
        if (cur -> data == s) {
            // se devo eliminare il primo elemento
            if (cur -> prev != nullptr) {
                cell *aux = cur;
                l = cur -> next;
                delete aux;
            } else {
                cell *temp = cur;
                cur -> prev -> next = cur -> next;
                cur -> next -> prev = cur -> prev;
                delete temp;
            }
        } else {
            cur = cur -> next;
        }
    }
}

// stampa la lista dall’ultimo elemento al primo seguendo i campi prev
void printReverse(const list &l) {
    cell *cur = l;
    while (cur -> next != nullptr) {
        cur = cur -> next;
    }
    while (cur -> prev != nullptr) {
        cout << cur -> prev -> data;
        if (cur -> prev != nullptr) {
            cout << " -> ";
        }
        cur = cur -> prev;
    }
    cout << endl;
}