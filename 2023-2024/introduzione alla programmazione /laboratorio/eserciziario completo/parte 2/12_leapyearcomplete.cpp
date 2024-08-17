/* Scrivere un programma che verifica se un numero intero dato in input rappresenta o meno un anno
bisestile. Usare la regola del calendario gregoriano che si trova su Wikipedia alla voce “Anno 
bisestile”. [ File leaptyearcomplete.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int anno;
    cout << "Inserire un anno: ";
    cin >> anno;

    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        cout << "L'anno e' bisestile" << endl;
    } else {
        cout << "L'anno NON e' bisestile" << endl;
    }
}