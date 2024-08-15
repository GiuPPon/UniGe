/* Scrivere una funzione di nome orderedStringArray che preso un array t di string e la sua 
dimensione size restituisce true se gli elementi di t sono ordinati nel ordine crescente (secondo 
l’ordine del dizionario) e false altrimenti. Usate l’aritmetica dei puntatori per scorrere t.
[ File orderedStringArray_funct.h ] e [ File orderedStringArray_funct.cpp ] per dichiarazione e 
definizione della funzione e [ File orderedStringArray_main.cpp ] per i test */

#include "orderedStringArray_funct.h"
using namespace std;

bool orderedStringArray(string* t, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (t[i] > t[i + 1]) {
            return false;
        }
    }
    return true;
}