/* Scrivere una funzione di nome allDiffArrayElements che preso un array t di interi e la sua 
dimensione size restituisce true se t non contiene due elementi uguali e false altrimenti. Usate 
l’aritmetica dei puntatori per scorrere t.
[ File allDiffArrayElements_funct.h ] e [ File allDiffArrayElements_funct.cpp ] per dichiarazione e 
definizione della funzione e [ File allDiffArrayElements_main.cpp ] per i test. */

#include "allDiffArrayElements_funct.h"

bool allDiffArrayElements(int* t, int size) {
    for (int* p1 = t; p1 < t + size - 1; ++p1) {
        for (int* p2 = p1 + 1; p2 < t + size; ++p2) {
            if (*p1 == *p2) {
                return false;
            }
        }
    }
    return true;
}
