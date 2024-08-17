/* Scrivere un programma che scambia (in inglese swap) tra loro i valori di due variabili intere, 
lette da input, e stampa i valoriprima e dopo lo scambio. 
Il programma deve essere scritto in un file chiamato swapint.cpp.

Situazione iniziale:
    a contiene il valore x      b contiene il valore y
Risultato finale:
    a contiene il valore y      b contiene il valore x */

#include <iostream>
using namespace std;

int main () {
    // chiedere di inserire il valore per la variabile a
    // dichiarare una variabile a di tipo int
    // leggere a
    int a = 0;
    cout << "Inserire il valore della variabile a" << endl;
    cin >> a;
    // chiedere di inserire il valore per la variabile b
    // dichiarare una variabile b di tipo int
    // leggere b
    int b = 0;
    cout << "Inserire il valore della variabile b" << endl;
    cin >> b;
    // stampare un a capo seguito dalla stringa "a vale " e dal valore di a
    cout << "a vale " << a << endl;
    // stampare un a capo seguito dalla stringa "b vale " e dal valore di b
    cout << "b vale " << b << endl;

    // scambiare fra loro i valori di a e b: per farlo serve una variabile di appoggio c
    
    // dichiarare una variabile c di tipo int inizializzata con il valore di a
    int c = a;
    // assegnare ad a il valore di b
    a = b;
    // assegnare a b il valore di c, ovvero il valore iniziale di a
    b = c;
    // stampare un a capo seguito dalla stringa "a vale " e dal valore di a
    cout << "a vale " << a << endl;
    // stampare un a capo seguito dalla stringa "b vale " e dal valore di b
    cout << "b vale " << b << endl;
}
