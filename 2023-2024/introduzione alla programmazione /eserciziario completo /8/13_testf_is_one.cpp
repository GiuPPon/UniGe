/* . Scrivere una funzione con tre parametri di tipo float che li moltiplica fra loro, divide il 
risultato ottenuto per ciascuno degli argomenti in successione e restituisce un booleano che vale vero
se il risultato dell’operazione è 1. [ File testf_is_one.cpp ] */

#include <iostream>
using namespace std;

bool is_one(float a, float b, float c) {
    float result = a * b * c;
    result = result / a;
    result = result / b;
    result = result / c;

    return (result == 1);
}

int main() {
    float num1, num2, num3;
    cout << "inserire primo numero: ";
    cin >> num1;
    cout << "inserire secondo numero: ";
    cin >> num2;
    cout << "inserire terzo numero: ";
    cin >> num3;

    if (is_one(num1, num2, num3)) {
        cout << "Il risultato e' 1." << endl;
    } else {
        cout << "Il risultato NON e' 1." << endl;
    }
}
