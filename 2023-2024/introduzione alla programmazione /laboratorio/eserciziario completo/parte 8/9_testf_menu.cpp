/* Scrivere un programma, per testare le funzioni implementate nell’esercizio precedente, che propone 
all’utente un menu con quattro alternative, ne legge la scelta e seleziona l’alternativa 
corrispondente finché non viene selezionata l’alternativa quattro. Il programma deve comportarsi come
descritto nel seguente algoritmo. [ File testf_menu.cpp ] */

#include <iostream>
#include <string>
using namespace std;

void print_choice(int, string, string, string, string);
void print_menu(string, string, string, string);
int get_choice(int);
int use_menu(string, string, string, string);

int main () {
    // dichiarare una costante s1 di tipo string inizializzata con "Prima scelta"
    const string s1 = "Prima scelta";
    // dichiarare una costante s2 di tipo string inizializzata con "Seconda scelta"
    const string s2 = "Seconda scelta";
    // dichiarare una costante s3 di tipo string inizializzata con "Terza scelta"
    const string s3 = "Terza scelta";
    // dichiarare una costante s4 di tipo string inizializzata con "Basta!"
    const string s4 = "Basta!";
    /* ripetere
    - dichiarare una variabile intera answer inizializzata con use_menu su s1, s2, s3, s4
    finché answer è diverso da quattro
    */
    int answer;
    do {
        answer = use_menu(s1, s2, s3, s4);
    } while (answer != 4);
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

int use_menu(string choice1, string choice2, string choice3, string choice4){
    print_menu(choice1, choice2, choice3, choice4);
    int n = get_choice(4);
    print_choice (n, choice1, choice2, choice3, choice4);
    return n;
}
