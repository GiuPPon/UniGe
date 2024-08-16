/* Scrivere una funzione che riceve un argomento intero hm, legge hm numeri reali e ne restituisce 
la media. */

#include <iostream>
using namespace std;

float average(int hm){
    // se hm non è positivo
    // - stampare un messaggio di errore
    // - terminare il programma con exit(0)
    if (hm < 0) {
        cout << "errore: numero negativo" << endl;
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
    return (sum / hm);
}

// Scrivere un programma per testare la funzione secondo il seguente algoritmo:
int main () {
    // stampare la stringa "Di quanti numeri vuoi fare la media?"
    cout << "Di quanti numeri vuoi fare la media?" << endl;
    // dichiarare una variabile how_many di tipo int
    int how_many;
    // leggere how_many
    cin >> how_many;
    // dichiara una variabile avg (float) e inizializzarla con il risultato della chiamata di average su how_many
    float avg = average(how_many);
    // stampare un'andata a capo seguita dalla stringa "La media è " 
    //stampare avg
    cout << "La media e' " << avg << endl;
}

/* NOTA. "Chiamare una funzione f su x" è un modo colloquiale per intendere “chiamare una funzione f 
usando x come argomento”, ovvero fare la chiamata f(x). */