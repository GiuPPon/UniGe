// ESERCIZIO 1

#include <iostream>
#include <string>
using namespace std;

/* 1.A (2 PUNTI) Realizzare due struct indirizzo e
cliente:
• Indirizzo contiene: via, numero civico, CAP,
città
• Cliente contiene: codice fiscale, cognome,
nome, indirizzo */

struct indirizzo {
    string via;
    int numCivico;
    int CAP;
    string città;
};

struct cliente {
    string codFiscale;
    string cognome;
    string nome;
    indirizzo indirizzo;
};

/* 1.B (2 PUNTI) Realizzare una funzione che
verifichi se due clienti abitano nella stessa zona
della città (da verificare tramite il CAP) */

bool same_zone(cliente &cliente1, cliente &cliente2) {
    if (cliente1.indirizzo.CAP == cliente2.indirizzo.CAP) {
        return true;
    }
    return false;
}

//ESERCIZIO 2

// Consideriamo il tipo di dato “coda di Elem” e un’implementazione basata su vector
/* 2.A (2 PUNTI) Produrre i prototipi (o interfacce) delle 3
funzioni principali
- enqueue (inserisci elemento in fondo alla coda)
- dequeue (elimina elemento dalla testa della coda)
- front (accedi in lettura e restituisci il prossimo
elemento nella coda) */

void enqueue(vector<int> v, int Elem);

void dequeue(vector<int> v);

void front(vector<int> v, int Elem);

// 2.B (2 PUNTI) Implementare la funzione dequeue

void dequeue(vector<int> v) {
    v.erase(v.begin());
}

// ESERCIZIO 3
// Considerate le liste collegate semplici:

typedef struct
cell {
int head;
cell *next;
} *lista;

/* 3.A (2.5 PUNTI) Realizzare una funzione ricorsiva che permetta di contare il numero
di elementi di una lista */

int n_elementi(lista &l) {
    return 1 + n_elementi(l -> next);
}

/* 3.B (2.5 PUNTI) Realizzare una funzione booleana che restituisce true se tutti gli
elementi della lista sono pari, false altrimenti. Trattare in modo opportuno il caso
lista vuota */

bool is_even(lista &l) {
    if (l == nullptr) {
        return false;
    }
    if (l -> data % 2 != 0) {
        return false;
    } 
    return is_even(l -> next);
}