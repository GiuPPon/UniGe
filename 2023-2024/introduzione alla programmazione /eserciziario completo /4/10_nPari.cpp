/* . Scrivere un programma che legge N interi in un array a di int (vedi leggiArrayInt). Quindi con un
opportuno messaggio di output stampa il numero P dei numeri pari contenuti nell’array ed il numero D 
di quelli dispari (P e D sono quindi entrambi valori interi). [ File nPari.cpp ] */

#include <iostream>
using namespace std;

int main () {
    const int N = 5;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int pari = 0;
    int dispari = 0;

    for (int i = 0; i < N; ++i) {
        if ( a[i] % 2 == 0 ) {
            ++pari;
        } else {
            ++dispari;
        }
    }

    cout << "numeri pari = " << pari << endl;
    cout << "numeri dispari = " << dispari << endl;
}
