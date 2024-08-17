/* Scrivere un programma che effettui l’ordinamento di un array v dato secondo l’algoritmo Selection
Sort. [ File selectionSort.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int N = 15;
    int a[N];
    // dichiarare una variabile int greatestIndex
    int greatestIndex;

    for (int i = 0; i < N; ++i) {
        int val;
        cout << "Inserisci un valore intero per a[" << i << "] = ";
        cin >> val;
        a[i] = val;
    }

    /* iterare sull'array dalla prima all'ultima posizione
    - memorizzare in greatestIndex la posizione corrente (sia i)
    - *//* iterare sull'array dalla posizione successiva alla corrente (i+1) fino all'ultimo elemento
    -- se il valore alla pos corrente (j) e' < del valore alla pos greatestIndex
    --- memorizzare j in greatestIndex
    */
    for (int i = 0; i < N; ++i) {
        greatestIndex = i;
        for (int j = i + 1; j < N; ++j) {
            if (a[j] < a[greatestIndex]) {
                greatestIndex = j;
            }
        }
    // - scambiare il valore alla posizione i con quello alla pos greatestIndex
        int aux = a[i];
        a[i] = a[greatestIndex];
        a[greatestIndex] = aux;
    }
    
    cout << "Array dopo l'ordinamento: ";
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}