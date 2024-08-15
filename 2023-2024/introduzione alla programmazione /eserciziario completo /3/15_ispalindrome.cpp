/* Scrivere un programma che chiede all’utente un numero intero e verifica se è palindromo, ovvero se 
le sue cifre (in base 10) lette da destra a sinistra corrispondono alle cifre lette da sinistra a 
destra (ad esempio 165373561 è palindromo). Dopo la verifica stampa il risultato all’utente. Per 
risolvere questo esercizio si può partire dalla soluzione dell’esercizio 3.8. 
[ File ispalindrome.cpp ] */

#include <iostream> 
using namespace std;

int main () {
    int k; 
    int v;

    do {
        cout << "Inserire un numero intero: ";
        cin >> k;
        v = k;

        if (k < 0) {
            cout << "Numero negativo inserito. Riprova con un numero positivo." << endl;
        }
    } while (k < 0);

    int inv = 0;
    
    while (k != 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10;
        inv = inv + mod;
    }

    if (v != inv) {
        cout << "il numero NON e' palindromo" << endl;
    } else {
        cout << "Il numero e' palindromo" << endl;
    }
} 