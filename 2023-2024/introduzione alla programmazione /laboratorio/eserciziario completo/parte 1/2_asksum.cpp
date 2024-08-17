#include <iostream>
using namespace std;

/* Come esercizio 1, ma prima di ogni input viene dato un messaggio di richiesta, del tipo 
“inserisci il valore di ... ”. Il programma deve essere scritto in un file chiamato asksum.cpp. */

int main () {
    
    int a = 0;
    int b = 0;
    
    cout << "inserisci il valore di a" << endl;
    cin >> a;
    cout << "inserisci il valore di b" << endl;
    cin >> b;
    
    cout << "La somma vale " << a + b << endl;
}
