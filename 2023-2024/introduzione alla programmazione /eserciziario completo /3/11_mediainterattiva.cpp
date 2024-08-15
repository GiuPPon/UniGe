/* Scrivere un programma che chiede all’utente di inserire numeri interi. Dopo ogni numero inserito 
chiede all’utente se terminare con l’inserimento (carattere ’n’) o continuare (qualsiasi altro 
carattere). Finito il ciclo di lettura dei numeri stampa la media dei numeri letti.
[ File mediainterattiva.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int num;
    double sum;
    char answer;
    int count = 0; 

    do {
        cout << "inserire un numero intero: ";
        cin >> num;
        sum = sum + num;
        ++count;
        cout << "se vuoi terminare l'inserimento digita 'n'";
        cin >> answer;
    } while (answer != 'n');

    cout << "La media dei numeri e' " << sum / count << endl;
}