/* Scrivere una funzione void sortArrayInv(int* t, int size) che preso un array t di interi e la sua 
dimensione size ordina gli elementi del array t in ordine decrescente.
[ File sortArrayInv_funct.h ] e [ File sortArrayInv_funct.cpp ] per dichiarazione e definizione della 
funzione e [ File sortArrayInv_main.cpp ] per i test.
[SUGGERIMENTO: Ricordatevi quello che si è visto nel esercizio 3 della sezione 5.] */

#include "sortArrayInv_funct.h"

void sortArrayInv(int* t, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (t[j] < t[j + 1]) {
                int temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}