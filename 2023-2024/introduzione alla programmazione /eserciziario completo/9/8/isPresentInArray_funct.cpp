/* Scrivere una funzione di nome isPresentInArray che preso un array t di interi, la sua dimensione 
size e un intero x restituisce true se x è presente in t e false altrimenti. Usate l’aritmetica dei 
puntatori per scorrere t.
[ File isPresentInArray_funct.h ] e [ File isPresentInArray_funct.cpp ] per dichiarazione e definizione 
della funzione e [ File isPresentInArray_main.cpp ] per i test. */

#include <iostream>
#include "isPresentInArray_funct.h"
using namespace std;

bool isPresentInArray(int* t, int size, int x) {
    for (int *p = t; p < t + size; ++p) {
        if (*p == x) {
            return true;
        }
    }
    return false;
}