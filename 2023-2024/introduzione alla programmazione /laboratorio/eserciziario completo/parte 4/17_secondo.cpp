/* Scrivere un programma che legge un array di int e stampa il secondo valore più elevato.
[ File secondo.cpp ] */

#include <iostream>
using namespace std;

int main () { 
    const int N = 5;
    int a[N];

    cout << "Inserisci gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int max1 = a[N];
    int max2 = a[N];

    for (int i = 1; i < N; ++i) {
        if (a[i] > max1) {
            /* Durante ogni iterazione, controlliamo se l'elemento corrente a[i] è maggiore di max1. 
            Se lo è, assegnamo max1 a max2 e l'elemento corrente diventa il nuovo max1 */
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2 && a[i] != max1) {
            /* Se l'elemento corrente non è maggiore di max1, controlliamo se è maggiore di max2 e se
            è diverso da max1. Se sì, lo assegnamo a max2. */
            max2 = a[i];
        }
    }

    cout << "Il secondo valore piu' elevato e': " << max2 << endl;

    return 0;
}