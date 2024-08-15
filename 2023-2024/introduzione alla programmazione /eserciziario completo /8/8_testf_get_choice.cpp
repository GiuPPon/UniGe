/* Scrivere una funzione con un argomento intero max che chiede all’utente di inserire una scelta 
compresa fra uno e max finché l’utente non ne inserisce una accettabile e la restituisce.
[ File testf_get_choice.cpp ] */

#include <iostream>
using namespace std;

int get_choice(int max){
    // Dichiarare una variabile scelta di tipo int
    int scelta;
    /* Ripetere
    - Stampare "Inserisci una scelta fra 1 e " seguito da max
    - Stampare un a capo
    - Leggere scelta
    finché scelta minore di uno o maggiore di max */
    do {
        cout << "Inserisci una scelta fra 1 e " << max << endl;
        cin >> scelta;
    } while (scelta < 1 || scelta > max);
    // Restituire scelta
    return scelta;
}

int main () {
    // stampare il risultato della chiamata di get_choice su 7
    int result = get_choice(7);
    cout << "Il numero scelto e' " << result << endl;
}