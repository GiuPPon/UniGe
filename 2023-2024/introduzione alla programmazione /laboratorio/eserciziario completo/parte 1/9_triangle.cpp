/* Scrivere un programma che calcola l’area di un triangolo, dopo aver chiesto e letto i dati 
necessari. Il programma deve essere scritto in un file chiamato triangle.cpp. */

#include <iostream>
using namespace std;

int main () {
    double base = 0;
    double altezza = 0;
    cout << "Inserire base" << endl;
    cin >> base;
    cout << "Inserire altezza" << endl;
    cin >> altezza;

    double area = (base * altezza) / 2;

    cout << "L'area del triangolo e' " << area << endl;
}
