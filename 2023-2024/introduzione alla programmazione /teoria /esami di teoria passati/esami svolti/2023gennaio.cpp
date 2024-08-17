// ESERCIZIO 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*1.A (1+1 PUNTI) Realizzare due struct indirizzo e cliente:
• Indirizzo contiene: via, numero civico, CAP, città
• Cliente contiene: cognome, nome, indirizzo*/

struct indirizzo {
    string via;
    int numCivico;
    int CAP;
    string città;
};

struct cliente {
    string cognome;
    string nome;
    indirizzo indirizzo;
};

/*1.B (1 PUNTO) Realizzare una funzione che verifichi se
due clienti abitano nella stessa zona della città*/

bool same_zone(cliente &cliente1, cliente &cliente2) {
    if (cliente1.indirizzo.CAP == cliente2.indirizzo.CAP) {
        return true;
    }
    return false;
}

/*1.C (1 PUNTO) Realizzare il prototipo di una funzione
che acquisisca gli opportuni parametri formali, passati
in modo adeguato, per aggiornare l’indirizzo di un
cliente*/

void new_address(cliente &cliente, indirizzo &nuovoIndirizzo);

// ESERCIZIO 2 
// Assumiamo di voler implementare il tipo di dato “coda di clienti” basandoci sui vector

/*2.A (2 PUNTI) Produrre i prototipi (o interfacce) delle 3
funzioni principali
- enqueue (inserisci elemento in fondo alla coda)
- dequeue (elimina elemento dalla testa della coda)
- front (accedi in lettura e restituisci elemento nella coda)*/

void enqueue(vector<int> &v, int Elem);

void dequeue(vector<int> &v);

void front(vector<int> &v);

/*2.B (2.5 PUNTI) Implementare la funzione
PARI dequeue
DISPARI enqueue
trattando opportunamente il caso coda vuota*/

//PARI
void dequeue(vector<int> &v) {
    v.pop_back();
}

//DISPARI

void enqueue(vector<int> &v, int Elem) {
    v.push_back(Elem);
}

// ESERCIZIO 3 
//Considerate le liste collegate semplici (ordinate):

typedef struct
cell {
int head;
cell *next;
} *lista;

/*3.A (2.5 PUNTI) Realizzare una funzione ricorsiva che
PARI inserisca un elemento in ordine in una lista
DISPARI cancelli un elemento da una lista ordinata*/

//PARI
void insert_elem(lista &l, int elem) {
    if ((l == nullptr)) {
        cell *aux = new cell;
        aux -> head = elem;
        aux -> next = l;
        l = aux;
    } else {
        insert_elem(l -> next, elem);
    }
}

//DISPARI
void delete_elem(lista &l, int elem) {
    if (l -> head == elem) {
        cell *cur = l;
        l = cur -> next;
        delete cur;
        return;
    } else {
        return delete_elem(l -> next, elem);
    }
}

/*3.B (2 PUNTI) Realizzare una funzione booleana che restituisce true se due liste
PARI sono consecutive (il primo elemento della 2a lista è maggiore dell’ultimo della 1a)
DISPARI sono uguali*/

//PARI

bool is_consecutive(lista &l1, lista &l2) {
    while (l1 -> next != nullptr) {
        l1 = l1 -> next;
    }
    if (l2 -> head > l1 -> head) {
        return true;
    }
    return false;
}

//PARI

bool sono_uguali(lista &l1, lista &l2) {
    if (l1 -> head == l2 -> head) {
        return true;
    }
    return false;
}