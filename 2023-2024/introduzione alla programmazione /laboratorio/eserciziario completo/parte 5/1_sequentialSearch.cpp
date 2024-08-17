/* Scrivere un programma che effettui la ricerca dell’elemento item (un intero) nell’array v (array di
15 interi letti da input). [ File sequentialSearch.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // dichiarare una variabile const int N inizializzata a 15
    const int N = 15;
    // dichiarare una variabile int item
    int item;
    // leggere item da input
    cout << "Inserire elemento da cercare: " << endl;
    cin >> item;
    // dichiarare un array v di N interi
    int v[N];
    // leggere v da input (vedi esercizi parte precedente)
    for (int i = 0; i < N; ++i) {
        int val;
        cout << "Inserisci un valore intero per a[" << i << "] = ";
        cin >> val;
        v[i] = val;
    }
    // dichiarare una variabile int loc e inizializzarla a -1
    int loc = -1;
    // dichiarare una variabile bool found e inizializzarla a false
    bool found = false;
    /* iterare sugli elementi di v fino a che found diventa true o si è iterato su tutto l'array
    - se il valore alla pos corrente (i) e' uguale a item
    -- assegnare true a found e il valore di i a loc
    */
    for (int i = 0; i < N; ++i) {
        if (v[i] == item) {
            found = true;
            loc = i;
        }
    }
    // se trovato, scrivere su output: item " è stato trovato in posizione " loc
    // altrimenti scrivere: item " non è stato trovato"
    if (found == true) {
        cout << item << " e' stato trovato in posizione " << loc << endl;
    } else {
        cout << item << " non e' stato trovato" << endl;
    }
}