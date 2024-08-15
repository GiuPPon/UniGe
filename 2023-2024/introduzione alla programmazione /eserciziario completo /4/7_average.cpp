/* Media: scrivere un programma che legge N valori reali, li memorizza in un array di lunghezza N,
e ne stampa la media. [ File average.cpp ]
Esempio di Output atteso
Inserisci un valore float per a[0] = 67.7
Inserisci un valore float per a[1] = 56.7
Inserisci un valore float per a[2] = 73.1
Inserisci un valore float per a[3] = 89.5
Inserisci un valore float per a[4] = 56.0
I valori contenuti nell'array a sono: { 67.7, 56.7, 73.1, 89.5, 56 }
La media dei valori contenuti nell'array a è: 68.6 */

#include <iostream>
using namespace std;

int main () {
    // copiare qui il codice del programma "leggiArrayFloat.cpp"
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
    cout << " }" << endl;
    // dichiarare una variabile sum di tipo float e inizializzarla a zero
    // iterare su i a partire da 0 e fino a N-1
    //- sommare il contenuto dell'i-esimo elemento di a a sum
    float sum = 0;
    for (int i = 0; i <= N - 1; ++i) {
        sum = sum + a[i];
    }
    // stampare la divisione di sum per N
    cout << "La media dei valori contenuti nell'array a e': " << sum / N << endl;
}