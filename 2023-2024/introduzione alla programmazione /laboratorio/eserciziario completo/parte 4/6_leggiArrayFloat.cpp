/* Leggi un array di float da tastiera e stampalo su singola riga. Scrivere un programma simile al 
precedente, ma che lavora su array di float e stampa il contenuto dell’array su una sola riga 
(gestire la virgola nel caso finale). Usare N = 5. [ File leggiArrayFloat.cpp ]
Esempio di Output atteso
Inserisci un valore float per a[0] = 5.67
Inserisci un valore float per a[1] = 34.2
Inserisci un valore float per a[2] = 73.56
Inserisci un valore float per a[3] = 345.23
Inserisci un valore float per a[4] = 498.45
I valori contenuti nell'array a sono: { 5.67, 34.2, 73.56, 345.23, 498.45 } */

#include <iostream>
using namespace std;

int main () {
    const int N = 5;
    
    float a[N];
    
    for (int i = 0; i < N; ++i) {
        float val;
        cout << "Inserisci un valore reale per a[" << i << "] = ";
        cin >> val;
        a[i] = val;
    }
    
    cout << "I valori contenuti nell'array a sono: { ";
    for (int i = 0; i < N; ++i) {
        cout << a[i];
        if (i != (N - 1)) {
            cout << ", ";
        }
    }
    cout << " }";     
}