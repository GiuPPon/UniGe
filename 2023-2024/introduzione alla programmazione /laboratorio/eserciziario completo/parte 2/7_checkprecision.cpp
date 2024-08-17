/* Scrivere un programma che chiede all’utente un numero reale e lo legge salvandolo in una variabile 
di tipo float. Quindi, ne fa una copia (in un’altra variabile di tipo float) e in cascata (ovvero 
usando il risultato di ciascuna operazione come argomento per la successiva), lo divide per 4.9, 
per 3.53 e per 6.9998. Poi, sempre in cascata, moltiplica per 4.9, per 3.53 e per 6.9998. Infine 
confronta il risultato ottenuto con il numero iniziale e se rappresentano due numeri reali diversi 
stampa "moltiplicare NON e' l'inverso di dividere". [ File checkprecision.cpp ] */

#include <iostream>
using namespace std;

int main () {
    float num;
    cout << "Inserire un numero reale: ";
    cin >> num;
    float aux = num;

    float divisione = num / 4.9;
    divisione /= 3.53;
    divisione /= 6.9998;

    float moltiplicazione = divisione * 4.9;
    moltiplicazione *= 3.53;
    moltiplicazione *= 6.9998;

    if (moltiplicazione != aux) {
        cout << "moltiplicare NON e' l'inverso di dividere" << endl;
    }
}