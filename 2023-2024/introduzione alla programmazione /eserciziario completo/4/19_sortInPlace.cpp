/* Scrivere un programma che legge un array di int, riordina i suoi elementi in modo crescente, 
e poi lo stampa. [ File sortInPlace.cpp ] */

#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int a[N];
    
    cout << "Inserisci gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // bubble sort
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Array ordinato in modo crescente:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
