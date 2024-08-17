// Esercizio 1. Consideriamo vector di int

/* Realizzare una funzione booleana che Restituisca true se ogni elemento del vector è multiplo 
del precedente, false altrimenti */

#include <iostream>
#include <vector>
using namespace std;

bool is_vector_multiplo(vector<int> &v) {
    for (int i = 1; i < v.size; ++i) {
        if (v[i] % v[i - 1] != 0) {
            return false;
        }
    }
    return true;
}

/* Esercizio 2.
Implementare un tipo di dato che permetta all’avatar Pollicino di tenere traccia dei suoi
spostamenti, codificati come segue
- ‘U’ (verso l’alto)
- ‘D’ (verso il basso)
- ‘L’ (verso sinistra)
- ‘R’ (verso destra)
L’implementazione deve basarsi su liste collegate semplici.
2.A SPECIFICARE I TIPI NECESSARI: */

struct cell {
    char spostamento;
    cell *next;
}

/*2.B INDICARE LE INTERFACCE DELLE FUNZIONI
- FaiUnPasso: inserisce un nuovo spostamento al percorso effettuato finora
- FaiUnPassoIndietro: elimina l’ultimo spostamento effettuato
- Stampa: stampa il percorso effettuato sin ora (a ritroso, dall’ultimo spostamento fino
al primo)
- Direzione: restituisce l’ultimo spostamento effettuato, senza modificare il percorso*/
// 2.C IMPLEMENTARE LA FUNZIONE Direzione

void FaiUnPasso(cell &l, char spostamento) {
    cell *aux = new cell;
    aux -> data = spostamento;
    aux -> next = nullptr;
    if (l == nullptr) {
        l = aux;
    } else {
        cell *cur = l;
        while (cur -> next != nullptr) {
            cur = cur -> next;
        }
        cur -> next = aux;
    }
}

void FaiUnPassoIndietro (cell &l) {
    cell *cur = l;
    while (cur -> next != nullptr) {
        cur = cur -> next;
    }
    delete cur -> next;
    cur -> next = nullptr;
}

void Stampa (cell &l, char spostamento) {
    Stampa (l -> next);
    cout << l -> data << " ";
}

cell Direzione (cell &l, char spostamento) {
    cell *cur = l;
    while (cur -> next != nullptr) {
        cur = cur -> next;
    }
    return cur;
}
