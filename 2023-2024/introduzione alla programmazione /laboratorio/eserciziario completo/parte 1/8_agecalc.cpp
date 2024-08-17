/* Scrivere un programma che chiede all’utente in che anno è nato e stampa quanti anni ha 
(supponiamo sia nato il 1 Gennaio). Il programma deve essere scritto in un file chiamato agecalc.cpp. */

#include <iostream>
using namespace std;

int main () {
    int currentyear = 2024;
    int yearofbirth = 0;

    cout << "inserire anno di nascita " << endl;
    cin >> yearofbirth;

    cout << "Hai " << currentyear - yearofbirth << " anni" << endl;
}