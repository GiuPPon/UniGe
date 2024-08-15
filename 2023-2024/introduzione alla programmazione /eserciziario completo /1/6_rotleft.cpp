/* Scrivere un programma che scambia in maniera circolare “verso sinistra” i valori di tre variabili 
di tipo float, lette da input, e stampa i valori prima e dopo lo scambio. Il programma deve essere 
scritto in un file chiamato rotleft.cpp.

Situazione iniziale:
    a contiene il valore x      b contiene il valore y       c contiene il valore z
Risultato finale:
    a contiene il valore y      b contiene il valore z       c contiene il valore x 

Ad esempio se vengono inseriti i valori 3.5, 4.7 e −8.978 li assegna a variabili a, b e c 
(nell’ordine) e stampa 3.5, 4.7 e −8.978. Poi assegna 4.7 ad a, −8.978 a b e 3.5 a c e 
stampa 4.7, −8.978 e 3.5. */

#include <iostream>
using namespace std;

int main () {
    float x = 3.5;
    float y = 4.7;
    float z = -8.978;

    cout << "x vale " << x << endl;
    cout << "y vale " << y << endl;
    cout << "z vale " << z << endl;

    float w = x;

    x = y;
    y = z;
    z = w;

    cout << "x vale " << x << endl;
    cout << "y vale " << y << endl;
    cout << "z vale " << z << endl;
}