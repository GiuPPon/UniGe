/* Scrivere una funzione che prende come argomenti un intero n, compreso fra uno e quattro, e quattro 
stringhe e che stampa su una nuova riga il parametro stringa n-esimo preceduto dalla stringa 
"Scelta effettuata: ". [ File testf_print_choice.cpp ] */

#include <iostream>
#include <string>
using namespace std;

void print_choice(int n, string ch1, string ch2, string ch3, string ch4){
    // Stampare un a capo seguito da "Scelta effettuata: "
    cout << "Scelta effettuata: " << endl;
    // A seconda del valore di n
    // Nel caso 1:
    // - stampare ch1
    // Nel caso 2:
    // - stampare ch2
    // Nel caso 3:
    // - stampare ch3
    // Nel caso 4:
    // - stampare ch4
    switch (n) {
        case 1:
            cout << ch1 << endl;
            break;
        case 2:
            cout << ch2 << endl;
            break;
        case 3:
            cout << ch3 << endl;
            break;
        case 4:
            cout << ch4 << endl;
            break;
        default:
            cout << "Opzione non valida" << endl;
    }
}

int main () {
    // dichiarare una costante s1 di tipo string inizializzata con "Prima scelta"
    const string s1 = "Prima scelta";
    // dichiarare una costante s2 di tipo string inizializzata con "Seconda scelta"
    const string s2 = "Seconda scelta";
    // dichiarare una costante s3 di tipo string inizializzata con "Terza scelta"
    const string s3 = "Terza scelta";
    // dichiarare una costante s4 di tipo string inizializzata con "Quarta scelta"
    const string s4 = "Quarta scelta";
    // chiamare print_choice su 1, s1, s2, s3, s4
    print_choice(1, s1, s2, s3, s4);
    // chiamare print_choice su 2, s1, s2, s3, s4
    print_choice(2, s1, s2, s3, s4);
    // chiamare print_choice su 3, s1, s2, s3, s4
    print_choice(3, s1, s2, s3, s4);
    // chiamare print_choice su 4, s1, s2, s3, s4
    print_choice(4, s1, s2, s3, s4);
}