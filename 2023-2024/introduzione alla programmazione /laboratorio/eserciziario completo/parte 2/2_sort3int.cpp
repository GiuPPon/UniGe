/*Scrivere un programma che legge tre interi e li stampa in ordine crescente, seguendo l’algoritmo 
proposto (che fissa una serie di dettagli ulteriori). [ File sort3int.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // chiedere di inserire tre numeri interi
    // dichiarare tre variabili a0, a1 e a2 di tipo int
    // leggere a0, a1 e a2
    int a0, a1, a2;
    cout << "Inserire tre variabili intere: " << endl;
    cin >> a0;
    cin >> a1;
    cin >> a2;
    // ordinare a0, a1 e a2, ovvero:
    // dichiarare una variabile intera aux inizializzata con a1
    int aux = a1;
    // se a0 maggiore di a1 scambiare fra loro a0 e a1, cioe'
    // - assegnare ad a1 il valore di a0, ad a0 il valore di aux e...
    // ... ad aux il valore di a1 (a questo punto a0 <= a1==aux)
    if (a0 > a1) {
        a1 = a0;
        a0 = aux;
        aux = a1;
    }
    // se a0 maggiore di a2
    // - assegnare ad a1 il valore di a0, ad a0 il valore di a2 e...
    // ... ad a2 il valore di aux
    // altrimenti
    // - se a1 maggiore di a2 scambiare fra loro a1 e a2, cioe'
    // -- assegnare ad a1 il valore di a2, ad a2 il valore...
    // ... di aux (a questo punto a0<=a1<=a2)
    if (a0 > a2) {
        a1 = a0;
        a0 = a2;
        a2 = aux;
    } else if (a1 > a2) {
        a1 = a2;
        a2 = aux;
    }
    // stampare la stringa "I numeri inseriti, in ordine crescente, sono: "
    // stampare il valore di a0, seguito dal carattere <
    // stampare il valore di a1, seguito dal carattere <
    // stampare il valore di a2
    // stampare un a capo
    cout << "I numeri inseriti, in ordine crescente, sono: " << a0 << " < " << a1 << " < " << a2 << endl;
}