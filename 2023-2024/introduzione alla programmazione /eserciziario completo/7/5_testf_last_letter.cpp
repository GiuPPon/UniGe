/* Scrivere una funzione senza argomenti che legge lettere minuscole finchè l’utente non inserisce un 
carattere che non è una lettera minuscola, e restituisce l’ultima in ordine alfabetico (ovvero quella
che numericamente è la massima). */

#include <iostream>
using namespace std;

char last_letter(){
    // stampare la stringa "Inserisci una lettera minuscola "
    cout << "Inserisci una lettera minuscola " << endl;
    // dichiarare una variabile last di tipo char
    char last;
    /* ripetere
    - leggere last
    fintanto che last minore di 'a' o maggiore di 'z'
    */
    do {
        cin >> last;
    } while (last < 'a' || last > 'z');
    // dichiarare una variabile c di tipo char inizializzata con 'a'
    char c = 'a';
    /* ripetere
    - se c è maggiore di last
    -- assegnare il valore di c a last
    - stampare la stringa: "Inserisci una lettera minuscola (o altro carattere per terminare)"
    - leggere c
    finché c è maggiore o uguale ad 'a' e minore o uguale a 'z'
    */
    do {
        if (c > last) {
            last = c;
        }
        cout << "Inserisci una lettera minuscola (o altro carattere per terminare)" << endl;
        cin >> c;
    } while (c > 'a' && c <= 'z');
    // restituire il carattere last
    return last;
}

// Scrivere un programma per testare la funzione last_letter secondo il seguente algoritmo
int main () {
    // dichiarare la variabile char last
    char last;
    // chiamare la funzione last_letter() assegnando a last il valore che restituisce
    last = last_letter();
    // stampare la stringa "La lettera più grande inserita è "
    // stampare il contenuto di last
    cout << "La lettera piu' grande inserita e' " << last << endl;
}