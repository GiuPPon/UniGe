/* Partendo da quanto fatto nell’Esercizio 17 della Parte 3, scrivere una funzione con un argomento 
intero n che verifica se un numero intero positivo dato in input è un numero di Armstrong e se sì 
restituisce true, altrimenti restituisce false. Un intero positivo che si può rappresentare con n 
cifre (come minimo) si dice numero di Armstrong se è uguale alla somma delle potenze n-esime delle 
cifre che lo compongono. Ad esempio 153 = 1^3 + 5^3 + 3^3 = 1 ∗ 1 ∗ 1 + 5 ∗ 5 ∗ 5 + 3 ∗ 3 ∗ 3 è un
numero di Armstrong, come pure 1634 = 1^4 + 6^4 + 3^4 + 4^4 = 1 + 1296 + 81 + 256.
[ File testf_armstrong.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

bool Armstrong (int n) {
    if (n <= 0) {
        return false;
    }

    int copy = n;
    int count = 0;
    int sum = 0;

    int temp = n;
    while (temp != 0) {
        temp = temp / 10;
        ++count;
    }

    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        sum = sum + (pow(digit, count));
        temp = temp / 10;
    }

    if (sum != copy) {
        return false;
    } 

    return true;
}

int main () {
    int num;
    cout << "Inserire un numero: ";
    cin >> num;

    if (Armstrong(num)) {
        cout << num << " e' un numero di Armstrong." << endl;
    } else {
        cout << num << " NON e' un numero di Armstrong." << endl;
    }
}