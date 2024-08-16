/* Scrivere un programma che legge un intero positivo e stampa il numero di zeri alla fine del suo 
fattoriale (in base 10) senza calcolarne il fattoriale. Ad esempio su 5 stampa 1 perché 5! = 120, 
mentre su 11 stampa 2 perché 11! = 39, 916, 800. Si noti che, siccome il fattoriale diventa 
rapidamente più grande dei numeri rappresentabili sul calcolatore, è molto importante riuscire a 
calcolare quanto richiesto senza dover calcolare il fattoriale. [ File factzeroes.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int num;
    cout << "Inserire un numero intero: ";
    cin >> num;

    if (num <= 0) {
        cout << "Il numero inserito non è valido." << endl;
        return 1;
    }

    int count = 0;

    for (int i = 5; num / i >= 1; i = i * 5) {
        count = count + (num / i);
    }

    cout << "Il numero di zeri alla fine del fattoriale di " << num << " e': " << count << endl;
}