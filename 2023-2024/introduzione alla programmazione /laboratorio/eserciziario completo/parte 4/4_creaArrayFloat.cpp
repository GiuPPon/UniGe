/* Crea un array con N elementi di tipo float con valori dipendenti da un input. Scrivere un programma
simile al precedente, ma che lavora su un array di float e richiede un valore iniziale v di tipo float
usato per inizializzare i suoi elementi. [ File creaArrayFloat.cpp ]
Esempio di Output atteso
Inserisci valore di v = 1.56
Valore di a[0] = 0
Valore di a[1] = 1.56
Valore di a[2] = 3.12
Valore di a[3] = 4.68
Valore di a[4] = 6.24
Valore di a[5] = 7.8
Valore di a[6] = 9.36
Valore di a[7] = 10.92
Valore di a[8] = 12.48
Valore di a[9] = 14.04 */

#include <iostream>
using namespace std;

int main () {
    // Dichiarare una costante N con valore 10
    const int N = 10;
    // Dichiarare un array a di N float
    float a[N];
    // Chiedere in input un valore float v;
    float v;
    cout << "Inserisci valore di v: ";
    cin >> v;
    // Iterare sulla variabile intera i a partire da 0 e fino a N escluso:
    // - Assegnare all'elemento i-esimo di a il valore i*v;
    // Stampare l'array in ordine crescente da a[0] a a[N-1] come visto sopra
    for (int i = 0; i < N; ++i) {
        a[i] = i * v;
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
}