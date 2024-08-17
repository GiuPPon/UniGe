// Scrivere un programma che legge tre numeri reali e li stampa in ordine decrescente. 
// [ File sortdown3reals.cpp ]

#include <iostream>
using namespace std;

int main () {
    int a, b, c;
    cout << "Inserire tre numeri reali: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    int aux = b;
    
    if (a > b) {
        b = a;
        a = aux;
        aux = b;
    }
    
    if (a > c) {
        b = a;
        a = c;
        c = aux;
    } else if (b > c) {
        b = c;
        c = aux;
    }

    cout << "Ordine crescente: " << a << " < " << b << " < " << c << endl;
}