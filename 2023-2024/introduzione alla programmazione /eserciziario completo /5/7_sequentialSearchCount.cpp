/* Confrontare l’efficienza della sequentialSearch vs binarySearch quando si cerca se un certo valore
(item) è presente nell’array.
Modificare i precedenti esercizi 1 e 2 nel seguente modo:
(a) Inizializzare con valori a scelta un array di 30 elementi direttamente nel codice. I valori scelti
devono essere inseriti in ordine crescente. (in questo modo si evita di dover digitare in input ogni 
volta i valori ad ogni esecuzione)
(b) Dichiarino una variabile intera count inizializzata a 0
(c) Ogni volta che nel programma si controlla se l’elemento che si sta cercando (item) è l’elemento 
corrente dell’array, incrementare count
(d) Alla fine, stampare il valore di count (numero di accessi effettuati all’array)
Provare quindi a cercare con entrambi gli algoritmi (e su array contenenti gli stessi 30 valori) degli
elementi che sono memorizzati all’inizio, a metà, e alla fine dell’array. Quanti accessi sono necessari
con i due algoritmi? Ragionare su quale sia meno costoso (e quindi il più veloce).
[ File sequentialSearchCount.cpp ] [ File binarySearchCount.cpp ] */

#include <iostream>
using namespace std;

int main () {
    const int N = 30;
    int v[N] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};

    int item;
    cout << "Inserire elemento da cercare: " << endl;
    cin >> item;
    
    int loc = -1;
    bool found = false;
    int count = 0;
    
    for (int i = 0; i < N; ++i) {
        ++count;
        if (v[i] == item) {
            found = true;
            loc = i;
        }
    }
    
    if (found == true) {
        cout << item << " e' stato trovato in posizione " << loc << endl;
    } else {
        cout << item << " non e' stato trovato" << endl;
    }

    cout << "Numero di accessi effettuati all'array: " << count << endl;
}