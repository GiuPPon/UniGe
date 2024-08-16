/* Scrivere una funzione di nome arrayIncludedInArray che preso un array t1 di interi, la sua 
dimensione size1, un array t2 di interi, la sua dimensione size2 restituisce true se tutti gli 
elementi di t1 sono presenti in t2 e false altrimenti. Usate l’aritmetica dei puntatori per scorrere 
t1 e t2.
[ File arrayIncludedInArray_funct.h ] e [ File arrayIncludedInArray_funct.cpp ] per dichiarazione e 
definizione della funzione e [ File arrayIncludedInArray_main.cpp ] per i test */

#include "arrayIncludedInArray_funct.h"

bool arrayIncludedInArray(int* t1, int size1, int* t2, int size2) {
    for (int* p1 = t1; p1 < t1 + size1; ++p1) {
        bool found = false;
        for (int* p2 = t2; p2 < t2 + size2; ++p2) {
            if (*p1 == *p2) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
