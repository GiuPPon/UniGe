/* Scrivere un programma che ripete le seguenti operazioni finché l’utente non decide di terminare:
• chiede all’utente un numero intero positivo
• stampa su una nuova riga tante '|' quanto è grande il numero
• chiede all’utente se vuole terminare
[ File barplot.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // dichiarare una variabile answer di tipo carattere
    char answer;
    /* ripetere
    - stampare la stringa "inserisci un numero intero positivo"
    - dichiarare una variabile n di tipo intero
    - leggere n
    - iterare su una variabile intera i a partire da 1 fino a n
    -- stampare '|'
    - stampare un'andata a capo
    - stampare su una nuova riga la stringa
    "inserisci s o S per terminare, qualsiasi altro carattere per proseguire"
    - leggere answer
    finché answer è diverso sia da 's' che da 'S'
    */
    do {
        cout << "inserisci un numero intero positivo" << endl;
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cout << '|';
        }
        cout << endl;

        cout << "inserisci s o S per terminare, qualsiasi altro carattere per proseguire" << endl;
        cin >> answer;
    } while (answer != 's' && answer != 'S');
    // stampare la stringa "ho terminato perchè hai inserito " seguita da answer
    // che cosa succede se inserisci un numero negativo e perchè?
    cout << "ho terminato perche' hai inserito " << answer << endl;
}