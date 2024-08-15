/* Scrivere un programma che effettui la ricerca dell’elemento item (un intero) nell’array v (array di
15 interi ORDINATI letti da input). [ File binarySearch.cpp ]
NOTA. Per l’algoritmo di binarySearch vi rimandiamo alle slides presentate a lezione.
[SUGGERIMENTO: Ricordate che il metodo di Ricerca Binaria opera su sequenze ordinate!] */

#include <iostream>
using namespace std;

int main () {
    //lunghezza array e array
    int length = 15;
    int a[length];

    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;

    // elemento da cercare
    int item;
    cout << "Inserire elemento da cercare: " << endl;
    cin >> item;
    
    cout << "Inserire un array ordinato: " << endl;
    for (int i = 0; i < length; ++i) {
        int val;
        cout << "Inserisci un valore intero per a[" << i << "] = ";
        cin >> val;
        a[i] = val;
    }

    while( first <= last && !found) {
        mid = (first + last) / 2;
        if (a[mid] == item) {
            found = true;
        } else if (a[mid] > item) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }

    if (found) {
        cout << item << " e' stato provato a posizione " << mid << endl;
    } else {
        cout << item << " non e' stato trovato" << endl;
    }
}