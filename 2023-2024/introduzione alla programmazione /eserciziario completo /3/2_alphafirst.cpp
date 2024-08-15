/* Scrivere un programma che legge lettere maiuscole finché l’utente non inserisce un carattere che 
non è una lettera maiuscola e stampa la prima in ordine alfabetico. [ File alphafirst.cpp ]
[SUGGERIMENTO: Le lettere maiuscole vengono rappresentate con numeri consecutivi, quindi per sapere se
un carattere rappresenta una lettera maiuscola basta verificare che sia maggiore o uguale del 
carattere ‘A’ e minore o uguale al carattere ‘Z’.] */ 

#include <iostream>
using namespace std;

int main () {
    // stampare la stringa "Inserisci una lettera maiuscola"
    cout << "Inserisci una lettera maiuscola";
    // dichiarare una variabile first di tipo char
    char first;
    /* ripetere
    - leggere first
    finché first minore di 'A' o maggiore di 'Z'
    // Hint: ovvero finché l'utente non inserisce una lettera maiuscola
    */
    do {
        cin >> first;
    } while (first < 'A' || first > 'Z');  
    // Hint: a questo punto sappiamo che first è una lettera maiuscola!
    // dichiarare una variabile c di tipo char inizializzata con 'Z'
    // Hint: a questo punto sappiamo che first <= c!
    char c = 'Z';
    /* ripetere
    - se c è minore di first
    -- assegnare a first il valore di c
    - stampa della stringa "Inserisci una lettera maiuscola (o altro carattere per terminare)"
    - lettura di c
    finché c è maggiore o uguale ad 'A' e minore o uguale a 'Z'
    // Hint: ovvero finché l'utente inserisce lettere maiuscole
    */
    do {
        if (c < first) {
            first = c;
        }
        cout << "Inserisci una lettera maiuscola (o altro carattere per terminare)" << endl;
        cin >> c;
    } while (c >= 'A' && c <= 'Z');
    
    // stampare la stringa "La lettera più piccola inserita è " seguita da first
    cout << "La lettera piu' piccola inserita e' " << first << endl;
}