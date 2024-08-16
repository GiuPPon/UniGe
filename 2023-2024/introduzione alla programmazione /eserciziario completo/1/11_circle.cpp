/* Scrivere un programma che calcola circonferenza e area di un cerchio, dopo aver chiesto e letto
i dati necessari. Supponiamo π = 3.14. Il programma deve essere scritto in un file chiamato circle.cpp. */

#include <iostream>
using namespace std;

int main () {
    double raggio = 0;
    float pi = 3.14;

    cout << "inserire raggio del cerchio" << endl;
    cin >> raggio;

    double area = pi * (raggio * raggio);
    cout << "L'area del cerchio e' " << area << endl; 
}