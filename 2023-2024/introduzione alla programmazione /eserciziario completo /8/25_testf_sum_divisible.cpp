/* Scrivere una funzione che presi come argomenti tre interi strettamente positivi: a, b e max 
restituisce la somma dei numeri divisibili per almeno uno fra a e b compresi fra 0 e max.
[ File testf_sum_divisible.cpp ] */

#include <iostream>
#include <string>
using namespace std;

int sumDivisible(int a, int b, int max) {
    if (a <= 0 || b <= 0 || max <= 0) {
        string err = "Input non valido. I numeri devono essere strettamente positivi.";
        throw err;
    }

    int sum = 0;
    for (int i = 0; i <= max; ++i) {
        if (i % a == 0 || i % b == 0) {
            sum = sum + i;
        }
    }
    return sum;
}

int main() {
    int a, b, max;
    cout << "Inserisci tre interi strettamente positivi: ";
    cin >> a;
    cin >> b;
    cin >> max;

    try {
        int result = sumDivisible(a, b, max);
        cout << "La somma dei numeri divisibili per " << a << " o " << b << " fino a " << max << " e': " 
        << result << endl;
    } catch(string& err) {
        cout << err << endl;
    }
}
