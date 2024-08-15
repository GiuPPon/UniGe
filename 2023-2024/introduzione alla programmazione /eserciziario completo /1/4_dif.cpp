/* Scrivere un programma che legge due interi e ne stampa la differenza, seguendo l’algoritmo proposto
(che fissa una serie di dettagli ulteriori). Il programma deve essere scritto in un file chiamato
dif.cpp. */

#include <iostream>
using namespace std;

int main () {
    // chiedere di inserire due valori interi
    // dichiarare due variabili a e b di tipo int
    int a = 0;
    int b = 0;
    // leggere a e b
    cin >> a;
    cin >> b;
    // stampare la stringa "La differenza vale "
    // stampare il valore di a - b
    // stampare una andata a capo
    cout << "La differenza vale " << a - b << endl;
    }