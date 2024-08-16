/* Scrivere un programma che legge un numero intero n strettamente positivo ed un carattere, e stampa
il carattere n volte. [ File stampanvolte.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // stampare la stringa "Inserisci un numero maggiore di 0: "
    cout << "Inserisci un numero maggiore di 0: " << endl;
    // dichiarare una variabile len di tipo int
    int len;
    // leggere len
    cin >> len;
    // se len non e` maggiore di zero
    // - stampare "Avevo detto positivo!"
    // - uscire dal programma con l'istruzione return 1;
    if (len <= 0) {
        cout << "Avevo detto positivo!" << endl;
        return 1;
    }
    // stampare la stringa "Inserisci il carattere da replicare: "
    cout << "Inserisci il carattere da replicare: " << endl;
    // dichiarare una variabile c di tipo char
    char c;
    // leggere c
    cin >> c;
    /* iterare su i a partire da 1 e fino a len
    - stampare c */
    for (int i = 1; i <= len; ++i) {
        cout << c;
    }
}