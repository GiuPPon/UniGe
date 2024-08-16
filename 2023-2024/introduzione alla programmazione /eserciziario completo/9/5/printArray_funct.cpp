/* (Puntatori Array + Compilazione Separata) Scrivere una funzione printArray, che restituisce void, 
che prende due argomenti: un array di interi s da stampare e la sua dimensione size. Usare il puntatore 
all’array per scorrere tutti gli elementi dell’array (cioè con l’aritmetica dei puntatori).
La stampa dell’array deve essere effettuata su una singola riga come visto nelle lezioni precedenti: 
ad esempio dato un array s di 5 elementi deve stampare:
I valori contenuti nell'array s sono: { 3, 4, 5, 3, 4 }
Poi implementare una seconda funzione printArrayWithIndex che invece di scorrere l’array con 
l’aritmetica dei puntatori usa un indice (cioè per stampare la cella i-esima esegue s[i]). La stampa 
attesa deve essere equivalente a quella restituita da printArray.
[ File printArray_funct.h ] e [ File printArray_funct.cpp ] per dichiarazione e definizione della 
funzioni e [ File printArray_main.cpp ] per i test */

#include <iostream>
#include "printArray_funct.h"
using namespace std;

void printArray(int* s, int size) {
    // iterare size volte (cioè per i = 0, ..., size-1)
    // -- stampare il contenuto dell'indirizzo puntato da s (usando *s)
    // -- incrementare s
    for (int i = 0; i < size; ++i) {
        cout << *s;
        if (i < size - 1) {
            cout << ", ";
        }
        ++s;
    }
}

void printArrayWithIndex(int s[], int size) {
    // iterare size volte (cioè per i = 0, ..., size-1)
    // -- stampare s[i]
    for (int i = 0; i < size; ++i) {
        cout << s[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
}