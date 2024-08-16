/* Scrivere il programma che esegua la traslazione verso sinistra degli elementi di un vettore letto
in ingresso (di dimensione D fissata nel codice del programma), ovvero ogni elemento deve essere 
copiato in quello di indice immediatamente minore. Il valore del primo elemento deve essere perso, 
quello dell’ultimo deve essere rimpiazzato da 0. Quindi stampa il risultato.
Ad esempio: [1 10 15 18] −→ [10 15 18 0]
[ File shiftLeft.cpp ] */

#include <iostream>
using namespace std;

int main() {
    int N = 5;
    int a[N];

    // Input dei valori per il vettore
    for (int i = 0; i < N; ++i) {
        cout << "valore " << i + 1 << " dell'array: ";
        cin >> a[i];
    }

    // Traslazione verso sinistra degli elementi del vettore
    for (int i = 0; i < N - 1; ++i) {
        a[i] = a[i + 1];
    }
    a[N - 1] = 0; // Assegna 0 all'ultimo elemento

    // Stampa del risultato
    cout << "Vettore traslato verso sinistra:";
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
