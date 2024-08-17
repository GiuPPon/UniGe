/* Scrivere un programma reverse che legge N interi in un array source (vedi leggiArrayInt), e poi
copia in un array dest gli elementi di source in ordine inverso.
Quindi stampa source e dest (lasciando una riga vuota in mezzo per chiarezza). [ File reverse.cpp ] */

#include <iostream>
using namespace std;

int main () { 
    const int N = 5;
    int source[N];
    int dest[N];

    cout << "Inserisci " << N << " numeri interi: " << endl;
    for (int i = 0; i < N; ++i) {
        cin >> source[i];
    }

    for (int i = 0; i < N; ++i) {
        dest[i] = source[N - 1 - i]; // ordine inverso
    }
    
    cout << " " << endl;

    cout << "ordine originale : { ";
    for (int i = 0; i < N; ++i) {
        cout << source[i];
        if (i != (N - 1)) {
            cout << ", ";
        }
    }
    cout << " }" << endl; 

    cout << " " << endl;

    cout << "ordine inverso : { ";
    for (int i = 0; i < N; ++i) {
        cout << dest[i];
        if (i != (N - 1)) {
            cout << ", ";
        }
    }
    cout << " }"; 
}