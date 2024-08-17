/* Scrivere un programma che verifica se tre numeri reali dati in input possono essere i lati di un 
triangolo, cioè se nessuno di essi è maggiore della somma degli altri due. 
[ File triangleinequality.cpp] */

#include <iostream>
using namespace std;

int main () {
    double lato1, lato2, lato3;

    cout << "Inserisci il primo lato del triangolo: ";
    cin >> lato1;
    cout << "Inserisci il secondo lato del triangolo: ";
    cin >> lato2;
    cout << "Inserisci il terzo lato del triangolo: ";
    cin >> lato3;
    
    if (lato1 < lato2 + lato3 && lato2 < lato1 + lato3 && lato3 < lato1 + lato2) {
        cout << "I tre lati possono formare un triangolo." << endl;
    } else {
        cout << "I tre lati non possono formare un triangolo." << endl;
    }
}