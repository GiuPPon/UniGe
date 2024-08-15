/* Scrivere un programma che legge due interi e ne stampa la media (come numero reale).
Ad esempio sull’input 1 e 2 stampa 1.5. Il programma deve essere scritto in un file chiamato mean.cpp. */

#include <iostream>
using namespace std;

int main () {
    int a = 0;
    int b = 0;
    cout << "Inserire primo valore" << endl;
    cin >> a;
    cout << "Inserire secondo valore" << endl;
    cin >> b;

    double media = (a + b) / 2.0;
    cout << "La media e' " << media << endl;
}