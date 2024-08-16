/*Scrivere un programma che legge due numeri e li stampa in ordine crescente senza confrontarli.
Il programma deve essere scritto in un file chiamato sorttwo.cpp.
[SUGGERIMENTO: se alla media sottraggo la semidistanza, che valore ottengo?]*/

#include <iostream>
using namespace std;

int main () {
    double a = 0;
    double b = 0;
    cout << "Inserire primo valore" << endl;
    cin >> a;
    cout << "Inserire secondo valore" << endl;
    cin >> b;

    double media = (a + b) / 2;
    double semidistanza = abs(a - b) / 2;

    cout << "Numeri in ordine crescente: ";
    cout << (media - semidistanza) << " " << (media + semidistanza) << endl;
}