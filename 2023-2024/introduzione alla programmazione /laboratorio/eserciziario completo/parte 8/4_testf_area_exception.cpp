/* Scrivere una funzione che dati due float base e altezza, restituisce l’area del rettangolo di base 
base e altezza altezza. La funzione deve verificare che base e altezza siano valori positivi ed in 
caso contrario sollevare una eccezione di tipo int. [ File testf_area_exception.cpp ] */

#include <iostream>
using namespace std;

float area(float base, float altezza) {
    // se base AND altezza non è positivi
    // - dichiarare una variabile err di tipo int inizializzata a 3
    // - sollevare una eccezione con argomento err (throw err)
    if (base <= 0 && altezza <= 0) {
        int err = 3;
        throw err;
    }
    // se base non è positivo
    // - dichiarare una variabile err di tipo int inizializzata a 1
    // - sollevare una eccezione con argomento err (throw err)
    if (base <= 0) {
        int err = 1;
        throw err;
    }
    // se altezza non è positivo
    // - dichiarare una variabile err di tipo int inizializzata a 2
    // - sollevare una eccezione con argomento err (throw err)
    if (altezza <= 0) {
        int err = 2;
        throw err;
    }
    // restituire base x altezza
    return (base * altezza);
}

int main () {
    // dichiarare due variabili b e h di tipo float
    float b, h;
    // leggere b e h
    cout << "Inserire base: ";
    cin >> b;
    cout << "Inserire altezza: ";
    cin >> h;
    try {
        // dichiarare la variabile float a
        float a;
        // chiamare la funzione area assegnando ad a il valore che restituisce
        a = area(b, h);
        // stampare l'area
        cout << "l'area e' " << a << endl;
    }
    catch (int& err) {
        // stampare un messaggio che indica un errore sul valore della...
        // ... base (se err==1) o dell'altezza (se err==2) o di entrambi (se err==3)
        if (err == 1) {
            cout << "Errore: base negativa" << endl;
        } else if (err == 2) {
            cout << "Errore: altezza negativa" << endl;
        } else if (err == 3) {
            cout << "Errore: base e altezza negativi" << endl;
        }
    }
}