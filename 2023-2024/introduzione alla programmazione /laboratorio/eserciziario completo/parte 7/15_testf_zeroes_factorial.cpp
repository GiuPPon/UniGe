/* Partendo da quanto fatto nell’Esercizio 18 della Parte 3, scrivere una funzione con un argomento 
intero n che restituisce il numero di zeri alla fine del fattoriale (in base 10) del suo argomento 
senza calcolarne il fattoriale. Ad esempio su 5 stampa 1 perché 5 = 120, mentre su 11 stampa 2 perché
11! = 39 916 800. [ File testf_zeroes_factorial.cpp ] */

#include <iostream>
using namespace std;

int zeroesFactorial (int n) {
    if (n <= 0) {
        cout << "Il numero inserito non è valido." << endl;
    }

    int count = 0;
    for (int i = 5; n / i >= 1; i = i * 5) {
        count = count + (n / i);
    }

    return count;
}

int main () {
    int num;
    cout << "Inserire un numero: ";
    cin >> num;

    int zeroes = zeroesFactorial(num);
    cout << "Il numero di zeri alla fine del fattoriale di " << num << " e': " << zeroes << endl;
}