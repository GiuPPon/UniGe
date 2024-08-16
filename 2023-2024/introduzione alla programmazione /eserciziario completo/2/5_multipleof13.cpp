// Scrivere un programma che legge un numero intero da input e stampa se è o no divisibile per 13. 
// [ File multipleof13.cpp]

#include <iostream>
using namespace std;

int main () {
    int num = 0;
    cout << "Inserisci un numero intero: ";
    cin >> num;

    if (num % 13 != 0) {
        cout << "Il numero inserito NON e' divisibile per 13 " << endl;
    } else {
        cout << "Il numero inserito e' divisibile per 13 " << endl;
    }
}