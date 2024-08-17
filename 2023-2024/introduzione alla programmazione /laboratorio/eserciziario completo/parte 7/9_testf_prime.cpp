/* Scrivere una funzione isPrime con un argomento n di tipo intero che restituisce true se n è positivo 
e primo oppure false negli altri casi (negativo o non primo). Dal main richiamare la funzione su un 
insieme di valori utili a verificarne il funzionamento (memorizzati in un array).
[ File testf_prime.cpp ] */

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; // non è primo
        }
    }
    return true;
}

int main () {
    int N = 5;
    int a[N] = {1, 2, 5, 11, 45};

    for ( int i = 0; i < N; ++i ) {
        if (isPrime(a[i])) {
            cout << a[i] << " e' un numero primo" << endl;
        } else {
            cout << a[i] << " non e' un numero primo" << endl;
        }
    }
}