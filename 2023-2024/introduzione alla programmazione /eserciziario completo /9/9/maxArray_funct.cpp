/* Scrivere una funzione di nome maxArray che preso un array t di interi e la sua dimensione size 
restituisce il valore del suo elemento più grande. Se size vale 0, la funzione solleverà un eccezione 
di tipo string. Usate l’aritmetica dei puntatori per scorrere t.
[ File maxArray_funct.h ] e [ File maxArray_funct.cpp ] per dichiarazione e definizione della funzione
e [ File maxArray_main.cpp ] per i test */

#include <iostream>
#include <string>
#include "maxArray_funct.h"
using namespace std;

int maxArray(int* t, int size) {
    if (size == 0) {
        string err = "Dimensione dell'array è 0.";
        throw err;
    }
    
    int max = *t;
    for (int *p = t; p < t + size; ++p) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}