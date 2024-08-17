/* Stampa inverso di un array di float. Scrivere un programma che lavora su un array di float e li
stampa in ordine inverso [ File stampaArrayFloat.cpp ]
Output atteso:
Valore di a[4] = 846.42
Valore di a[3] = 28.456
Valore di a[2] = 34
Valore di a[1] = 5.67
Valore di a[0] = 2.4 */

#include <iostream>
using namespace std;

int main () {
    // Creare e popolare un array a di lunghezza 5.
    float a[5]={2.4, 5.67, 34, 28.456, 846.42};
    // Iterare sulla variabile intera i a partire da N-1 (4) e fino a 0 incluso:
    // - Stampare il valore i-esimo dell'array in posizione i e a capo
    for (int i = 4; i >= 0; --i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
}