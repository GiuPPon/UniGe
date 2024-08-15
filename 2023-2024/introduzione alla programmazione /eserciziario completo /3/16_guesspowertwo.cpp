/* Scrivere un programma che chiede all’utente un numero intero e lo legge. Poi chiede all’utente di 
provare a indovinarne il quadrato e se l’utente inserisce il valore giusto gli dice "Bravo!" ed esce, 
altrimenti gli propone di riprovare finché l’utente non riesce ad indovinare.
[ File guesspowertwo.cpp ] */

#include <iostream> 
using namespace std;

int main () {
    int num, answer;
    cout << "Inserire un numero intero: ";
    cin >> num;

    do {
        cout << "Indovina il quadrato del numero inserito: ";
        cin >> answer;
    } while (answer != num * num);

    cout << "Bravo!";
}