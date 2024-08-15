/* Scrivere un programma che calcola perimetro e area di un rettangolo, dopo aver chiesto e letto
i dati necessari. Il programma deve essere scritto in un file chiamato rectangle.cpp. */

#include <iostream>
using namespace std;

int main () {
    double base = 0;
    double altezza = 0;
    cout << "Inserire base" << endl;
    cin >> base;
    cout << "Inserire altezza" << endl;
    cin >> altezza;

    double perimetro = (base + altezza) * 2;
    double area = base * altezza;

    cout << "Il perimetro del rettangolo e' " << perimetro << endl;
    cout << "L'area del rettangolo e' " << area << endl;
}