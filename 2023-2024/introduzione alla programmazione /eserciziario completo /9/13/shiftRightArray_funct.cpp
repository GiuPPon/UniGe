/* Scrivere una funzione void shiftRightArray(int* t,int size) che preso un array t di interi e la sua 
dimensione size scala tutti gli elementi di t di una posizione verso destra (il primo elemento diventa 
il secondo, il secondo diventa il terzo, etc) mentre l’ultimo elemento diventa il primo.
[ File shiftRightArray_funct.h ] e [ File shiftRightArray_funct.cpp ] per dichiarazione e definizione 
della funzione e [ File shiftRightArray_main.cpp ] per i test. */

#include "shiftRightArray_funct.h"

void shiftRightArray(int* t, int size) {
    if (size <= 1) {
        return;
    }

    int lastElement = t[size - 1];
    for (int i = size - 1; i > 0; --i) {
        t[i] = t[i - 1];
    }
    t[0] = lastElement;
}