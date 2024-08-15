/* Scrivere una funzione che riceve un argomento intero hm, legge hm numeri reali e ne restituisce la
media. Usare le eccezioni per gestire i casi di errore. [ File testf_average_exception.cpp ] */

#include <iostream>
using namespace std;

float average(int hm){
    // se hm non è positivo
    // - dichiarare una variabile err di tipo int
    // - sollevare una eccezione con argomento err (throw err)
    if (hm <= 0) {
        int err = -1; 
        throw err;
    }
    // dichiarare una variabile sum di tipo float inizializzata a 0
    float sum = 0;
    /* iterare hm volte le seguenti istruzioni
    - stampare un a capo seguito dalla stringa "Inserisci un numero "
    - dichiarare una variabile x di tipo float
    - leggere x
    - assegnare a sum la somma di sum e x
    */
    for (int i = 0; i < hm; ++i) {
        cout << "Inserisci un numero " << endl;
        float x;
        cin >> x;
        sum = sum + x;
    }
    // restituire il risultato della divisione di sum per hm
    return sum / hm;
}

int main () {
    try {
        // stampare la stringa "Di quanti numeri vuoi fare la media?"
        cout << "Di quanti numeri vuoi fare la media?";
        // dichiarare una variabile how_many di tipo int
        int how_many;
        // leggere how_many
        cin >> how_many;

        // stampare un'andata a capo seguita dalla stringa "La media è "
        // stampare il risultato della chiamata di average su how_many
        cout << "La media e' " << endl; 
        cout << average(how_many) << endl;
    }
    catch(int& err) {
        // stampare un messaggio d'errore
        cout << "Errore: numero negativo" << endl;
    }
}