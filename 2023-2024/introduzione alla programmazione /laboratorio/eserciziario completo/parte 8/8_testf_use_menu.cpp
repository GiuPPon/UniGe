/* Scrivere una funzione che, prese come argomenti quattro stringhe, le stampa nell’ordine ricevuto, 
ciascuna su una nuova riga e preceduta da un numero progressivo, chiede all’utente un intero n 
compreso fra uno e quattro e stampa su una nuova riga il parametro stringa n-esimo preceduto dalla 
stringa "Scelta effettuata: ". [ File testf_use_menu.cpp ] */

#include <iostream>
#include <string>
using namespace std;

void print_choice(int, string, string, string, string);
void print_menu(string, string, string, string);
int get_choice(int);

int use_menu(string choice1, string choice2, string choice3, string choice4){
    // Chiamare print_menu su choice1, choice2, choice3, choice4
    print_menu(choice1, choice2, choice3, choice4);
    // Dichiarare una variabile n di tipo int inizializzata con il risultato della chiamata di get_choice su 4
    int n = get_choice(4);
    // Chiamare print_choice su n, choice1, choice2, choice3, choice4
    print_choice (n, choice1, choice2, choice3, choice4);
    // Restituire n
    return n;
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
    // chiamare use_menu su s1, s2, s3, s4
    use_menu(s1, s2, s3, s4);
}


void print_menu(string choice1, string choice2, string choice3, string choice4) {
    cout << "1\t" << choice1 << endl;
    cout << "2\t" << choice2 << endl;
    cout << "3\t" << choice3 << endl;
    cout << "4\t" << choice4 << endl;
}

void print_choice(int n, string ch1, string ch2, string ch3, string ch4){
    cout << "Scelta effettuata: " << endl;

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

int get_choice(int max){
    int scelta;

    do {
        cout << "Inserisci una scelta fra 1 e " << max << endl;
        cin >> scelta;
    } while (scelta < 1 || scelta > max);
    
    return scelta;
}