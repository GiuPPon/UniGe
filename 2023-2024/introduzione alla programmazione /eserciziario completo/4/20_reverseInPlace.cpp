/* Scrivere un programma che esegue lo stesso compito di reverse, ovvero legge un array di float e 
inverte l’ordine dei valori contenuti, ma questa volta senza usare un altro array come spazio di 
lavoro. [ File reverseInPlace.cpp ]
[SUGGERIMENTO: Basta fare swap fra le celle poste alla stessa distanza dagli estremi dell’array.]
 */

#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    float a[N];
    
    cout << "Inserisci gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N / 2; ++i) {
        float temp = a[i];
        a[i] = a[N - i - 1];
        a[N - i - 1] = temp;
    }

    cout << "Array invertito:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
