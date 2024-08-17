/* Scrivere un programma che esegua la rotazione verso destra degli elementi di un array letto in 
ingresso (di dimensione D fissata nel codice del programma), ovvero ogni elemento deve essere copiato
in quello di indice immediatamente maggiore, e il valore del primo elemento deve rimpiazzato da quello 
dell’ultimo. Quindi stampa il risultato.
Ad esempio: [1 10 15 18] −→ [18 1 10 15]
[ File rotateRight ] */

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

    int aux = a[N - 1]; 
    for (int i = N - 1; i > 0; --i) {
        a[i] = a[i - 1];
    }
    a[0] = aux; 

    cout << "Vettore rotato verso destra:";
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
