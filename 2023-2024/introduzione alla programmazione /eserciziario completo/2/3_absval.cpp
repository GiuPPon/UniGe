/* Scrivere un programma che legge un numero intero e ne stampa il valore assoluto (ovvero il numero 
senza segno, ad esempio se leggo −7 devo stampare 7, (non usare funzioni matematiche di libreria 
cmath). [ File absval.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int num = 0;
    cout << "Inserire un numero intero" << endl;
    cin >> num;

    cout << "Il suo valore assoluto: " << endl;
    if (num >= 1) {
        cout << num;
    } else {
        cout << num * (-1) << endl;
    }
}