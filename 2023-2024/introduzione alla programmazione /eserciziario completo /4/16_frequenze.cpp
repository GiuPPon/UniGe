/* Scrivere un programma che legge un array di int e stampa la frequenza di ogni valore contenuto 
(il numero di volte che compare). [ File frequenze.cpp ]
[SUGGERIMENTO: conviene avere un array di contatori (int) lungo tanto quanto l’array di ingresso.] */

#include <iostream>
using namespace std;

int main () {
    const int N = 5;
    const int max = 100;
    int a[N];
    int count[max] = {0};

    cout << "Inserire gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] >= 0 && a[i] < max) {
            ++count[a[i]];
        }
    }

    cout << "Numero di volte che ciascun elemento compare:" << endl;
    for (int i = 0; i < max; ++i) {
        if (count[i] > 0) {
            cout << i << " compare " << count[i] << " volte" << endl;
        }
    }
}