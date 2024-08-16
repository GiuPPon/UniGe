/* Leggi un array di int da tastiera. Scrivere un programma che dichiara un array a di N interi e lo “popola” leggendo valori
da input. [ File leggiArrayInt.cpp ]
Esempio di Output atteso
Inserisci un valore intero per a[0] = 4
Inserisci un valore intero per a[1] = 5
Inserisci un valore intero per a[2] = 2
Inserisci un valore intero per a[3] = 44
Inserisci un valore intero per a[4] = 788
Inserisci un valore intero per a[5] = 3354
Inserisci un valore intero per a[6] = 56343
Inserisci un valore intero per a[7] = 35643
Inserisci un valore intero per a[8] = 353
Inserisci un valore intero per a[9] = 3
Valore di a[0] = 4
Valore di a[1] = 5
Valore di a[2] = 2
Valore di a[3] = 44
Valore di a[4] = 788
Valore di a[5] = 3354
Valore di a[6] = 56343
Valore di a[7] = 35643
Valore di a[8] = 353
Valore di a[9] = 3 */

#include <iostream>
using namespace std;

int main () {
    // Dichiarare una costante N con valore 10
    const int N = 10;
    // Dichiarare un array a di N interi
    int a[N];
    // Iterare sulla variabile intera i a partire da 0 e fino a N escluso:
    // - Dichiarare una variabile intera val
    // - Stampare il messaggio composto dalla stringa "Inserisci un valore intero per a[" i "] = "
    // - Leggere da input un valore val
    // - Assegnare all'elemento i-esimo di a il valore di val
    for (int i = 0; i < N; ++i) {
        int val;
        cout << "Inserisci un valore intero per a[" << i << "] = ";
        cin >> val;
        a[i] = val;
    }
    // Stampare l'array in ordine crescente da a[0] a a[N-1] come visto sopra
    for (int i = 0; i < N; ++i) {
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
}