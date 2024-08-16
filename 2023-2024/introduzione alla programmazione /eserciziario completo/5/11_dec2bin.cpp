/* Fissata una costante intera positiva N = 10, scrivere un programma che, preso in ingresso un numero
intero positivo minore di 2^N (quindi nel caso specifico < 1024 e >= 0), memorizza la sua 
rappresentazione binaria su un array di lunghezza N. Quindi stampare il contenuto dell’array. Nel caso
il numero non sia valido (quindi negativo o >= 2^N ) stampare "Numero NON valido". [ File dec2bin.cpp ]
L’algoritmo per il calcolo della rappresentazione binaria è il seguente: si divide il numero in 
ingresso per 2 fino a che il risultato non è 0. La rappresentazione binaria è data dai resti delle
divisioni nell’ordine inverso in cui sono stati calcolati.
Quindi basta eseguire le divisioni finché non si arriva a 0 e memorizzare a ogni iterazione i resti 
della divisione intera in un array partendo dall’ultima posizione.
Esempi di esecuzione (coppie input e output):
0 0000000000
1 0000000001
5 0000000101
16 0000010000
127 0001111111
128 0010000000
765 1011111101
1000 1111101000
1023 1111111111
1024 Numero NON valido
-1000 Numero NON valido
3456 Numero NON valido
-1 Numero NON valido */

#include <iostream>
using namespace std;

int main () {
    int N = 10;

    int num;
    cin >> num;

    if ( num < 0 || num >= 1024 ) {
        cout << "Numero NON valido" << endl;
        return 0;
    }

    int numBinario[N];
    
    for (int i = 0; i < N; ++i) {
        numBinario[i] = num % 2;
        num = num / 2;
    }

    //rappresentazione binaria
    for (int i = N - 1; i >= 0; --i) {
        cout << numBinario[i];
    }
}