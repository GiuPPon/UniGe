/* Scrivere una funzione che dati due float base e altezza, restituisce l’area del rettangolo di base 
base e altezza altezza. La funzione deve verificare che base e altezza siano valori positivi ed in 
caso contrario ritorna rispettivamente -1 e -2 (ritornare -3 se entrambi invalidi). Testare i vari 
casi con input opportuni. */

#include <iostream>
using namespace std;

float area(float base, float altezza) {
    // se base AND altezza non sono positivi
    // - ritornare -3
    // se base non è positivo
    // - ritornare -1
    // se altezza non è positivo
    // - ritornare -2
    // restituire base x altezza
    if (base < 0 && altezza < 0) {
        return -3;
    } else if (base < 0) {
        return -1;
    } else if (altezza < 0) {
        return -2;
    }
    return (base * altezza);
}

// Scrivere un programma per testare la funzione area:
int main () {
    // dichiarare due variabili b e h di tipo float
    float b, h;
    // leggere b e h
    cout << "inserire base: ";
    cin >> b;
    cout << "inserire altezza: ";
    cin >> h;
    // dichiarare la variabile float a
    float a;
    // chiamare la funzione area assegnando ad a il valore che restituisce
    a = area(b, h);
    // se a è negativa gestire i vari casi con opportuni messaggi di errore
    // altrimenti stampare l'area
    if (a < 0) {
        cout << "errore" << endl;
    } else {
        cout << "L'area e' " << a << endl;
    }
}