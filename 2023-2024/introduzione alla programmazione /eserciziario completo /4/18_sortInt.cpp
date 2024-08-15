/* Scrivere un programma che legge un array di int source e scrive in un altro array dest il contenuto
dell’array source ordinato in modo crescente. Poi stampa dest. [ File sortInt.cpp ] */

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int source[N];
    int dest[N];

    cout << "Inserisci gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> source[i];
    }

    for (int i = 0; i < N; ++i) {
        dest[i] = source[i];
    }

    // bubble sort
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (dest[j] > dest[j + 1]) {
                int temp = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp;
            }
        }
    }

    cout << "Array ordinato in modo crescente:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << dest[i] << " ";
    }
    cout << endl;
}

