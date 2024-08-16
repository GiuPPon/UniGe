/* Partendo da quanto fatto nell’Esercizio 19 della Parte 3, scrivere una funzione con un argomento
intero n compreso fra 1 e 3000 e lo stampa in notazione romana. [ File testf_roman.cpp ] */

#include <iostream>
#include <string>
using namespace std;

string roman (int n) {
    if (n < 1 && n > 3000) {
        cout << "Il numero inserito non è valido." << endl;
    }

    string roman;

    while (n >= 1000) {
        roman = roman + "M";
        n = n - 1000;
    }
    if (n >= 900) {
        roman = roman + "CM";
        n = n - 900;
    }

    if (n >= 500) {
        roman = roman + "D";
        n =  n - 500;
    }
    if (n >= 400) {
        roman = roman + "CD";
        n = n - 400;
    }

    while (n >= 100) {
        roman = roman + "C";
        n = n - 100;
    }
    if (n >= 90) {
        roman = roman + "XC";
        n = n - 90;
    }

    if (n >= 50) {
        roman = roman + "L";
        n = n - 50;
    }
    if (n >= 40) {
        roman = roman + "XL";
        n = n - 40;
    }

    while (n >= 10) {
        roman = roman + "X";
        n = n - 10;
    }
    if (n >= 9) {
        roman = roman + "IX";
        n = n - 9;
    }
    if (n >= 5) {
        roman = roman + "V";
        n = n - 5;
    }
    if (n >= 4) {
        roman = roman + "IV";
        n = n - 4;
    }
    while (n >= 1) {
        roman = roman + "I";
        n = n - 1;
    }

    return roman;
}

int main () {
    int num;
    cout << "Inserire un numero: ";
    cin >> num;

    string numRoman = roman(num);
    cout << num << " in numeri romani e' " << numRoman << endl;
}