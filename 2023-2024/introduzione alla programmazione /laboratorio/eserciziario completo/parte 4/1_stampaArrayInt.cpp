/* Stampa un array di int. Scrivere un programma che, dati un array a di int e la sua lunghezza N, 
stampa tutto l’array. [ File stampaArrayInt.cpp ]
Output atteso:
Valore di a[0] = 2
Valore di a[1] = 4
Valore di a[2] = 34
Valore di a[3] = 78
Valore di a[4] = 4
Valore di a[5] = 3
Valore di a[6] = 876 */

#include <iostream>
using namespace std;

int main () {
    // Creare e popolare un array a di lunghezza 7.
    int a[7]={2, 4, 34, 78, 4, 3, 876};
    // Iterare sulla variabile intera i a partire da 0 e fino a 7 escluso:
    // - Stampare il valore i-esimo dell'array in posizione i e a capo
    for (int i = 0; i < 7; ++i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
}