// pre appello dicembre 2021

#include <iostream>
using namespace std;

// esercizio 1

/*scrivere una funzione che calcoli la media degli elementi contenuti in un array di numeri 
e che rispetti la seguente interfaccia:
float avg(float A[], int size)
utilizzare il meccanismo della ricorsione (e’ possibile realizzare funzioni ausiliarie)*/

int somma(int A[], int size) {
    if (size == 1) {
        return(A[size-1]);
    }
    return A[size-1] + somma(A, size-1);
}

float avg(float A[], int size) {
    if (size == 1) {
        return(A[size-1]);
    }
    return (A[size-1] + (size-1)*somma(A, size-1)) / static_cast<float> size;
}

// ESERCIZIO 2

/* Realizzare una funzione che cancelli tutte le istanze
di un dato valore da una lista. Definizione di tipo: */

typedef int Elem;

typedef struct cell {
    Elem head;
    cell *next;
} *lista;

void CancellaElem (lista &l, Elem x) {
    cell *curr = l;
    cell *prev = nullptr;
    while (curr != nullptr) {
        if (curr -> head == x) {
            //se curr è x, il next di prev è uguale al next di curr 
            prev -> next = curr -> next;
            delete curr; 
            curr = prev -> next; 
        } else {
            prev = curr;
            curr = curr -> next;
        }
    }
    if (prev == nullptr) {
        delete curr; 
        l = l -> next;
        curr = l;
    }
    prev -> next = curr -> next;
    delete curr;
    curr = prev -> next;
}

// ESERCIZIO 3 Considerare:

struct Point { double x; double y};
struct Rect {
    Point top_left;
    Point bottom_right;
};

/* Realizzare una funzione che restituisca l’area del
minore tra due Rect passati come parametro.
Prevedere, se ritenuto utile, funzioni ausiliarie */

void area_rettangolo (Rect &rettangolo1, Rect &rettangolo2) {
    double area_rettangolo1 = (rettangolo1.top_left.x - rettangolo1.bottom_right.x) * (rettangolo1.top_left.y - rettangolo1.bottom_right.y);
    double area_rettangolo2 = (rettangolo2.top_left.x - rettangolo2.bottom_right.x) * (rettangolo2.top_left.y - rettangolo2.bottom_right.y);
    if (area_rettangolo1 < area_rettangolo2) {
        return area_rettangolo2;
    } else {
        return area_rettangolo1;
    }
}

// ESERCIZIO 4

struct array_dinamico {
int *d;
int size;
int capacity;
};

// 4B. Realizzare una funzione init_ad di inizializzazione che permetta di costruire 
// un array_dinamico ancora vuoto

void init_ad (array_dinamico &d) {
    int d[0];
    int size = 0;
    int capacity = 0;
}