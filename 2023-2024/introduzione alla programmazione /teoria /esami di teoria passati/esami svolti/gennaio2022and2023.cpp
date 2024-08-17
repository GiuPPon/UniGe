#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 2022
// ESERCIZIO 1
// 1.A (2 PUNTI) Realizzare due struct indirizzo e cliente:
// • Indirizzo contiene: via, numero civico, CAP, città
// • Cliente contiene: codice fiscale, cognome, nome, indirizzo
// 1.B (2 PUNTI) Realizzare una funzione che verifichi se due clienti abitano nella stessa zona
// della città (da verificare tramite il CAP)*/

// 2023
// 1.C (1 PUNTO) Realizzare il prototipo di una funzione che acquisisca gli opportuni parametri 
// formali, passati in modo adeguato, per aggiornare l’indirizzo di un cliente 

// 1.A

struct indirizzo {
    string via;
    int numero_civico;
    int CAP;
    string città;
};

struct cliente {
    string codice_fiscale;
    string nome;
    string cognome;
    indirizzo indirizzo;
};

// 1.B

bool same_zone (cliente &cliente1, cliente &cliente2) {
    if (cliente1.indirizzo.CAP == cliente2.indirizzo.CAP) {
        return true;
    }
    return false;
}

// 1.C

void new_address (cliente &cliente, indirizzo &nuovoIndirizzo);

// ESERCIZIO 2

// 2022
// Consideriamo il tipo di dato “coda di Elem” e un’implementazione basata su vector
// 2.A (2 PUNTI) Produrre i prototipi (o interfacce) delle 3 funzioni principali
// - enqueue (inserisci elemento in fondo alla coda)
// - dequeue (elimina elemento dalla testa della coda)
// - front (accedi in lettura e restituisci il prossimo elemento nella coda)
// 2.B (2 PUNTI) Implementare la funzione dequeue

// 2023
// 2.B (2.5 PUNTI) Implementare la funzione
// DISPARI enqueue
// trattando opportunamente il caso coda vuota

// 2.A

void enqueue (vector<int> &v, int elem);

void dequeue (vector<int> &v);

int front (vector<int> &v);

// 2.B 

void dequeue (vector<int> &v) {
    v.erase(v.begin());
}

void enqueue (vector<int> &v, int elem) {
    if (v.empty()) {
        v.push_back(elem);
    } else {
    v.push_back(elem);
    }
}

// ESERCIZIO 3

// 2022
// Considerate le liste collegate semplici:
// 3.A (2.5 PUNTI) Realizzare una funzione ricorsiva che permetta di contare il numero
// di elementi di una lista
// 3.B (2.5 PUNTI) Realizzare una funzione booleana che restituisce true se tutti gli
// elementi della lista sono pari, false altrimenti. Trattare in modo opportuno il caso
// lista vuota

typedef struct
cell {
int head;
cell *next;
} *lista;

// 3.A (2022)

int n_elem (lista &l) {
    if (l != nullptr) {
        return 1 + n_elem(l -> next);
    }
    return 0;
}

// 3.B (2022)

bool is_even (lista &l) {
    if (l == nullptr) {
        return 0;
    } else if (l->head % 2 != 0) {
        return false;
    }
    return is_even(l->next);
}

// 2023
// 3.A (2.5 PUNTI) Realizzare una funzione ricorsiva che
// PARI inserisca un elemento in ordine in una lista
// DISPARI cancelli un elemento da una lista ordinata
// 3.B (2 PUNTI) Realizzare una funzione booleana che restituisce true se due liste
// PARI sono consecutive (il primo elemento della 2a lista è maggiore dell’ultimo della 1a)
// DISPARI sono uguali

typedef struct
cell {
int head;
cell *next;
} *lista;

// 3.A (2023)

// PARI
void insert_elem (lista &l, int elem) {
    if (l == nullptr) {
        cell *aux = new cell;
        aux -> head = elem;
        aux -> next = l;
        l = aux;
        // se l è vuota, creo una nuova cella 
    } else {
        insert_elem(l->next, elem);
        // else inserisco l'elemento nel next di l
    }
}

// DISPARI
void delete_elem (lista &l, int elem) {
    if (l->head == elem) {
        cell *cur = l;
        l = cur->next;
        delete cur;
        return;
    } else {
        return delete_elem(l->next, elem);
    }
}

// 3.B

// PARI
bool is_consecutive (lista &l1, lista &l2) {
    while (l1->next != nullptr) {
        l1 = l1->next;
    }
    if (l2->head > l1->head) {
        return true;
    }
    return false;
}

// DISPARI
bool sono_uguali (lista &l1, lista &l2) {
    (l1->head == l2->head) {
        return true;
    }
    return false;
}