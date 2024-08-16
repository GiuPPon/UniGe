/* Scrivere una funzione con argomenti interi n e d, con d compreso fra 0 e 9 e n maggiore di 10, che 
restituisce il più grande numero compreso fra 0 e n che nella sua rappresentazione in base 10 usa la 
cifra d. Ad esempio la sua chiamata con argomenti 3 per d e 15 per n restituisce 13 e la sua chiamata 
con argomenti 3 per d e 42 per n restituisce 39. [ File testf_usedigit.cpp ]
Riuscite a generalizzare questa funzione al caso in cui invece di cercare una singola cifra ne 
cerchiamo una sequenza? Ad esempio se cerco il più grande numero fra 0 e 400 che nella sua 
rappresentazione in base 10 contiene 39 il risultato sarà 399. */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int maxNumberWithDigit(int n, int d) {
    int maxNumber = -1;
    int result;

    if (d < 0 || d > 9 || n <= 10) {
        string err = "Input non valido";
        throw err;
    }

    for (int i = n; i >= 0; --i) {
        int num = i;
        while (num > 0) {
            int digit = num % 10;
            if (digit == d) {
                if (i > maxNumber) {
                    maxNumber = i;
                    result = i;
                }
                break;
            }
            num = num / 10;
        }
    }

    return result;
}

int main() {
    int n, d;
    cout << "Inserire n e d: ";
    cin >> n;
    cin >> d;

    try {
        int result = maxNumberWithDigit(n, d);
        cout << "Il numero massimo con la cifra " << d << " fino a " << n << " e': " << result << endl;
    } catch (string& err) {
        cout << err << endl;
    }
}