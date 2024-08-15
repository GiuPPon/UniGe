/* Scrivere un programma che prende in input tre numeri reali, a, b e c e stampa le radici 
dell’equazione di secondo grado ax2 + bx + c. Attenzione alle radici immaginarie. [ File roots.cpp ]
[SUGGERIMENTO: Radice di x: sqrt(x); aggiungere in testa al file: #include <cmath> ] */

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    double a, b, c;
    cout << "Inserire a, b e c dell'equazione di secondo grado (ax^2 + bx + c):" <<endl;
    cin >> a;
    cin >> b;
    cin >> c;

    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double radice1 = (-b + sqrt(delta)) / (2 * a);
        double radice2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Le radici sono: " << radice1 << " e " << radice2 << endl;
    } else if (delta == 0) {
        double radice = -b / (2 * a);
        cout << "La radice e': " << radice << endl;
    } else {
        // Radici immaginarie
        double parte_reale = -b / (2 * a);
        double parte_immaginaria = sqrt(-delta) / (2 * a);
        cout << "Le radici sono complesse: " << parte_reale << " + " << parte_immaginaria << "i"
            << " e " << parte_reale << " - " << parte_immaginaria << "i" << endl;
    }

    return 0;
}