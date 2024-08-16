/* Scrivere una funzione che presi come argomenti quattro stringhe, le stampa nell’ordine ricevuto, 
ciascuna su una nuova riga e preceduta da un numero progressivo.
[ File testf_print_menu.cpp ] */

#include <iostream>
#include <string>
using namespace std;

void print_menu(string choice1, string choice2, string choice3, string choice4){
    // stampare '1' seguito da un carattere tab seguito da choice1
    cout << "1\t" << choice1 << endl;
    // stampare su una nuova riga '2' seguito da un tab seguito da choice2
    cout << "2\t" << choice2 << endl;
    // stampare su una nuova riga '3' seguito da un tab seguito da choice3
    cout << "3\t" << choice3 << endl;
    // stampare su una nuova riga '4' seguito da un tab seguito da choice4
    cout << "4\t" << choice4 << endl;
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
    // chiamare print_menu su s1, s2, s3, s4
    print_menu(s1, s2, s3, s4);
}