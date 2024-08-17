/* Scrivere un programma che legge due caratteri e stampa la stringa “Uguali” se sono lo stesso 
carattere e la stringa “Diversi” se sono due caratteri differenti. [ File equalchars.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // dichiarare due variabili a e b di tipo char
    char a, b;
    // leggere a e b
    cin >> a;
    cin >> b;
    // se a e b sono uguali
    // stampare la stringa "Uguali"
    // altrimenti
    // stampare la stringa "Diversi"
    if (a == b) {
        cout << "Uguali" << endl;
    } else {
        cout << "Diversi" << endl;
    }
}



