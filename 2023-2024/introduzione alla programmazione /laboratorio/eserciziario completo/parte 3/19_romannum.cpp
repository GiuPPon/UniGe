/* Scrivere un programma che legge un intero positivo compreso fra 1 e 3000 e lo stampa in notazione 
romana. [ File romannum.cpp ]
Si ricorda che
• i numeri romani sono scritti usando le lettere I (per 1), V (per 5), X (per 10), L (per 50), C 
(per 100), D (per 500) e M (per 1000) e rappresentano un numero in maniera additiva (non posizionale 
come i numeri arabi), partendo dai simboli che rappresentano i numeri più grandi a sinistra e man mano
scendendo con simboli che rappresentano numeri sempre più piccoli; ad esempio MMXVII rappresenta 2017 
come 1000 + 1000 + 10 + 5 + 1 + 1.
• si possono incontrare dei simboli in ordine inverso, ma in questo caso i valori invece di andare 
sommati vanno sottratti; questo meccanismo può essere usato solo per i numeri 4, rappresentato da IV, 
9, rappresentato da IX, 40, rappresentato da XL, 90, rappresentato da XC, 400, rappresentato da CD, e 
900, rappresentato da CM. Quindi ad esempio 1984 si rappresenta con MCMLXXXIV e 999 si rappresenta con
CMXCIX (e non con IM).
[SUGGERIMENTO: La logica di rappresentazione dei numeri romani è di sommare da sinistra a destra le 
rappresentazioni dei numeri 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4 e 1.]
*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    int num;
    cout << "inserire un numero positivo compreso fra 1 e 3000: ";
    cin >> num;

    if (num < 1 && num > 3000) {
        cout << "Il numero inserito non è valido." << endl;
        return 1;
    }

    string roman;
    int aux = num;

    while (num >= 1000) {
        roman = roman + "M";
        num = num - 1000;
    }
    if (num >= 900) {
        roman = roman + "CM";
        num = num - 900;
    }

    if (num >= 500) {
        roman = roman + "D";
        num =  num - 500;
    }
    if (num >= 400) {
        roman = roman + "CD";
        num = num - 400;
    }

    while (num >= 100) {
        roman = roman + "C";
        num = num - 100;
    }
    if (num >= 90) {
        roman = roman + "XC";
        num = num - 90;
    }

    if (num >= 50) {
        roman = roman + "L";
        num = num - 50;
    }
    if (num >= 40) {
        roman = roman + "XL";
        num = num - 40;
    }

    while (num >= 10) {
        roman = roman + "X";
        num = num - 10;
    }
    if (num >= 9) {
        roman = roman + "IX";
        num = num - 9;
    }
    if (num >= 5) {
        roman = roman + "V";
        num = num - 5;
    }
    if (num >= 4) {
        roman = roman + "IV";
        num = num - 4;
    }
    while (num >= 1) {
        roman = roman + "I";
        num = num - 1;
    }

    cout << aux << " in numeri romani e' " << roman << endl;
}