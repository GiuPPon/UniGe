/* Scrivere una funzione con un argomento intero n che stampa la scomposizione in fattori primi di n. 
Ad esempio su 392 stampa "392 = 2^3 * 7^2", usando il carattere '^' per rappresentare l’elevamento a 
potenza. [ File testf_primefactors.cpp ] */

#include <iostream>
using namespace std;

void primeFactors(int n) {
    cout << n << " = ";

    int count = 0;
    while (n % 2 == 0) {
        n = n / 2;
        count++;
    }
    if (count > 0) {
        cout << "2";
        if (count > 1) {
            cout << "^" << count;
        }
        if (n > 1) {
            cout << " * ";
        }
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        count = 0;
        while (n % i == 0) {
            n = n / i;
            count++;
        }
        if (count > 0) {
            if (n > 1) {
                cout << i;
                if (count > 1) {
                    cout << "^" << count;
                }
                cout << " * ";
            } else {
                cout << i << "^" << count;
            }
        }
    }

    if (n > 2) {
        cout << n;
    }
    
    cout << endl;
}

int main() {
    int n;
    cout << "Inserire numero: ";
    cin >> n;
    primeFactors(n);
}
