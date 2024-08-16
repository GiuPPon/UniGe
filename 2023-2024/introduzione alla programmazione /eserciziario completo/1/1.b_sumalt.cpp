#include <iostream>
using namespace std;

int main () {
    // dichiarare due variabili a e b di tipo int
    int a = 0;
    int b = 0;
    // leggere a e b
    cin >> a;
    cin >> b;
    // dichiarare una variabile sum di tipo int inizializzata con il valore della somma di a e b
    int sum = a + b;
    // stampare la stringa "La somma vale " seguito da sum e un a capo
    cout << "La somma vale " << sum << endl;
}