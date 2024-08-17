/* Scrivere un programma che legge un array a e calcola un valore di tipo bool che vale true se 
l’array è palindromo. Poi stampa un messaggio che comunica il risultato all’utente. 
[ File palyndromeArray.cpp ]
[SUGGERIMENTO: usare il programma reverse.] */

#include <iostream>
using namespace std;

int main () { 
    const int N = 5;
    int source[N];
    int dest[N];
    bool palindrome = true;

    cout << "Inserisci " << N << " numeri interi: " << endl;
    for (int i = 0; i < N; ++i) {
        cin >> source[i];
    }

    for (int i = 0; i < N; ++i) {
        dest[i] = source[N - 1 - i]; // ordine inverso
    }
    
    for (int i = 0; i < N; ++ i) {
        if (source[i] != dest[i]) {
            palindrome = false;
        }
    }

    if (palindrome == true) {
        cout << "L'array e' palindromo" << endl;
    } else {
        cout << "L'array NON e' palindromo" << endl;
    }
}