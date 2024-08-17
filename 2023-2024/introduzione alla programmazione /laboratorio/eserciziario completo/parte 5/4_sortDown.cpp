/* Scrivere un programma che prende in input 20 numeri interi e li stampa in ordine decrescente.
[ File sortDown.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // scegliere 20 come valore per la costante N
    int N = 20;
    // dichiarare un array v di interi
    int v[N];
    // leggere v da input (leggiArrayInt)
    for (int i = 0; i < N; ++i) {
        int val;
        cout << "Inserisci un valore intero per a[" << i << "] = ";
        cin >> val;
        v[i] = val;
    }
    // visualizzare su output i valori inseriti
    cout << "Array: ";
    for (int i = 0; i < N; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    int greatestIndex;
    // usare SelectionSort per ordinare v in ordine decrescente
    for (int i = 0; i < N; ++i) {
        greatestIndex = i;
        for (int j = i + 1; j < N; ++j) {
            if (v[j] > v[greatestIndex]) {
                greatestIndex = j;
            }
        }
    // - scambiare il valore alla posizione i con quello alla pos greatestIndex
        int aux = v[greatestIndex];
        v[greatestIndex] = v[i];
        v[i] = aux;
    }

    // stampare i valori
    cout << "Array dopo l'ordinamento (decrescente): ";
    for (int i = 0; i < N; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}