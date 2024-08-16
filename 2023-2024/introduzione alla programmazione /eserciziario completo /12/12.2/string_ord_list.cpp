#include <string>
#include "string_ord_list.h"
using namespace std;

// inserisce un elemento contenente s nella lista ordinata l mantenendo la lista ordinata
void insertElement(ordList &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    cell *cur = l;
    cell *prev = nullptr;

    while ((cur != nullptr) && (cur -> data < s)) {
        prev = cur;
        cur = cur -> next;
    }
    if ((l == nullptr) || (cur -> data > s)) {
        aux -> next = l;
        l = aux;
    } else {
        prev -> next = aux;
        aux -> next = cur;
    }
}

// legge valori da input e li memorizza (aggiunge) nella lista ordinata l
// al termine dell'esecuzione di readList la lista l deve essere una lista ordinata.
// l'inserimento termina se l'utente inserisce "STOP!"
// NB: differente rispetto alla versione per liste non ordinate
void readList(ordList &l) {
    string s;
    cout << "Inserire valori: ";
    do {
        cin >> s;
        if (s != "STOP!") {
            insertElement(l, s);
        } 
    } while (s != "STOP!");
}

// stampa tutti i valori (data) degli elementi della lista ordinata l in linea separati da "->"
// NB: nessuna variazione rispetto alla versione per liste non ordinate
void printList(const ordList &l) {
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

// ritorna il numero di elementi della lista ordinata l
// NB: nessuna variazione rispetto alla versione per liste non ordinate
unsigned int listSize(const ordList &l) {
    cell *cur = l;
    unsigned int count = 0;
    while (cur != nullptr) {
        cur = cur -> next;
        ++count;
    }
    return count;
}

// ritorna true se la lista ordinata l e vuota, false altrimenti
// NB: nessuna variazione rispetto alla versione per liste non ordinate
bool isEmptyList(const ordList &l) {
    if (l == nullptr) {
        return true;
    }
    return false;
    // return (l == nullptr);
}

// ritorna il contenuto dell'i-esimo elemento della lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
// NB: nessuna variazione rispetto alla versione per liste non ordinate
string getElement(const ordList &l, unsigned int i) {
    if (l == nullptr) {
        string err = "getElement : lista vuota";
        throw err;
    }
    if ((i < 0) || (i >= listSize(l))) {
        string err = "getElement : indice invalido";
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

// cancella l'elemento in posizione i dalla lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
// NB: nessuna variazione rispetto alla versione per liste non ordinate
void deleteElementAt(ordList &l, unsigned int i) {
    if (l == nullptr) {
        string err = "getElement : lista vuota";
        throw err;
    }
    if ((i < 0) || (i >= listSize(l))) {
        string err = "getElement : indice invalido";
        throw err;
    }

    cell *cur = l;
    cell *prev = nullptr;
    unsigned int count = 0;

    // caso posizione zero
    if (i == 0) {
        l = cur -> next;
        delete cur;
        return;
    }
    while ((cur != nullptr) && (count < i)) {
        prev = cur;
        cur = cur -> next;
        ++count;
    }
    prev -> next = cur -> next;
    delete cur;
}

// cancella dalla lista ordinata l il primo elemento contenente s
// NB: nessuna variazione rispetto alla versione per liste non ordinate
void deleteElementOnce(ordList &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;

    // caso elemento in testa
    if (cur -> data == s) {
        l = cur -> next;
        delete cur;
        return;
    }
    while ((cur != nullptr) && (cur -> data != s)) {
        prev = cur;
        cur = cur -> next;
    }
    prev -> next = cur -> next;
    delete cur;
}

// cancella dalla lista ordinata l tutti gli elementi contenenti s
// NB: deve essere ottimizzata rispetto alla versione per liste non ordinate
void deleteAllElements(ordList &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;

    while (cur != nullptr) {
        if (cur -> data == s) {
            // caso primo elemento
            if (prev == nullptr) {
                // aux copia (puntatore) di cur (l = cur)
                cell *aux = cur;
                // mi sposto nella seconda cella
                l = cur -> next;
                cur = cur -> next;
                // non elimino cur ma aux perchè cur mi serve per scorrere
                delete aux;
            } else {
                // il next di prev diventa il next di cur
                prev -> next = cur -> next;
                // temp puntatore di cur
                cell *temp = cur;
                // mi sposto
                cur = cur -> next;
                // deleto temp perchè cur serve dopo
                delete temp;
            }
        } else {
            prev = cur;
            cur = cur -> next;
        }
    }
}

// restituisce true se le due liste contengono le stesse stringhe (con la stessa molteplicità)
// false altrimenti
bool listAreEqual(const ordList &l1, const ordList &l2) {
    const cell *cur1 = l1;
    const cell *cur2 = l2;

    // fino alla fine delle liste
    while ((cur1 != nullptr) && (cur2 != nullptr)) {
        // se l'elemento di cur1 (quindi di l1) è diverso da quello di cur2 (quindi di l2)
        // return false
        if (cur1 -> data != cur2 -> data) {
            return false;
        }
        // cur di entrambe le liste diventa cur next
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    return true;
}

// restituisce una nuova lista ordinata contenente gli elementi delle 2 liste ordinate l1 e l2
// Il numero di occorrenze di un elemento nel risultato
// è la somma del numero delle sue occorrenze nelle due liste l1 e l2
// NB: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
// in questo modo sia l1 che l2 non subiscono alcuna modifica
ordList concatLists(const ordList &l1, const ordList &l2) {
    ordList l3 = nullptr;

    cell *cur1 = l1;
    while (cur1 != nullptr) {
        insertElement(l3, cur1 -> data);
        cur1 = cur1 -> next;
    }

    cell *cur2 = l2;
    while (cur2 != nullptr) {
        insertElement(l3, cur2 -> data);
        cur2 = cur2 -> next;
    }
}

// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in almeno una delle due liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
// in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare il fatto che
// le due liste sono ordinate per minimizzare il numero di operazioni necessarie

// Funzione ausiliaria per unionList, mi serve per trovare un possibile duplicato
bool findElement(const ordList &lista, string e) {
    cell *cur = lista;

    while (cur != nullptr) {
        if (cur -> data == e) {
            return true;
        }
        cur = cur -> next;
    }
    return false;
}

ordList unionLists(const ordList &l1, const ordList &l2) {
    ordList NewList = nullptr;

    // Copia gli elementi della prima lista nella lista concatenata
    cell *cur = l1;
    while (cur != nullptr) {
        // se l'elemento non è duplicato, inserisco l'elemento 
        if (!findElement(NewList, cur -> data)) {
            insertElement(NewList, cur -> data);
        }
        cur = cur -> next;
    }

    // Aggiunge gli elementi della seconda lista alla fine della lista concatenata
    cur = l2;
    while (cur != nullptr) {
        if (!findElement(NewList, cur->data)) {
            insertElement(NewList, cur->data);
        }
        cur = cur->next;
    }

    return NewList;
}

// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in entrambe le liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
// in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare il fatto che
// le due liste sono ordinate per minimizzare il numero di operazioni necessarie
ordList intersectLists(const ordList &l1, const ordList &l2) {
    ordList NewList = nullptr;
    cell *cur1 = l1;
    cell *cur2 = l2;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1 -> data == cur2 -> data) {
            insertElement(NewList, cur1 -> data);
        }
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    return NewList;
}