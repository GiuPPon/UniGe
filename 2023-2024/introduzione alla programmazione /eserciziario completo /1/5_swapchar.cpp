/*Scrivere un programma che scambia i valori di due variabili di tipo char, lette da input, 
e stampa i valori prima e dopo lo scambio. Il programma deve essere scritto in un file 
chiamato swapchar.cpp. */

#include <iostream>
using namespace std;

int main () {
    char a, b;
    
    cin >> a;
    cin >> b;
    cout << "il primo valore è " << a << endl;
    cout << "il secondo valore è " << b << endl;

    char c = a;
    a = b;
    b = c;
    cout << "il primo valore è " << a << endl;
    cout << "il secondo valore è " << b << endl;
}