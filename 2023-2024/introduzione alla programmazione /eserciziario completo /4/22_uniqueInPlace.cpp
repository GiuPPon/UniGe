/* Scrivere un programma come il precedente, ma realizzato senza usare array ausiliari (dovete usare
un algoritmo in place). [ File uniqueInPlace.cpp ] */ 

#include <iostream>
using namespace std;

int main() {
    const int N = 5; 
    int a[N];

    cout << "Inserisci gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int curr = 0;
    for (int i = 0; i < N; ++i) {
        // Se l'elemento corrente è diverso dall'elemento precedente o se siamo all'inizio dell'array
        if (i == 0 || a[i] != a[i - 1]) {
            a[++curr] = a[i]; 
        }
    }

    // Azzeramento degli elementi rimanenti nell'array
    for (int i = curr; i < N; ++i) {
        a[i] = 0;
    }

    // Stampa gli elementi non zero dell'array
    cout << "Elementi unici:" << endl;
    for (int i = 0; i < curr; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
