/* Scrivere un programma che verifica se un numero intero positivo dato in input è un numero di 
Armstrong. Un intero positivo a n cifre si dice numero di Armstrong se è uguale alla somma delle
potenze n-esime delle cifre che lo compongono. Ad esempio 153 = 1^3+5^3+3^3 = 1∗1∗1+5∗5∗5+3∗3∗3 è 
un numero di Armstrong, come pure 1634 = 1^4+6^4+3^4+4^4 = 1+1296+81+256. [ File armstrongnum.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int num;
    cout << "Inserire un numero intero: ";
    cin >> num;

    if (num <= 0) {
        cout << "Il numero inserito non è valido." << endl;
        return 1;
    }

    int copy = num;
    int count = 0;
    int sum = 0;

    int temp = num;
    while (temp != 0) {
        temp = temp / 10;
        ++count;
    }


    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum = sum + (pow(digit, count));
        temp = temp / 10;
    }

    if (sum != copy) {
        cout << copy << " NON e' un numero di Armstrong." << endl;
    } else {
        cout << copy << " e' un numero di Armstrong." << endl;
    }
}