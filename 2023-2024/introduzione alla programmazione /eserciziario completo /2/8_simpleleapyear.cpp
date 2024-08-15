/* Scrivere un programma che verifica se un numero intero dato in input rappresenta o meno un anno 
bisestile (per semplicità intendiamo solo come divisibile per 4 e non gestiamo i casi "particolari",
piu’ avanti, negli esercizi avanzati c’è l’esercizio completo su anno bisestile). 
[ File simpleleapyear.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int anno;
    cout << "Inserire un anno: ";
    cin >> anno;

    if (anno % 4 != 0) {
        cout << "L'anno NON e' bisestile" << endl;
    } else {
        cout << "L'anno e' bisestile" << endl;
    }
}