/* Scrivere un programma che scrive il fattoriale di un numero chiesto all’utente. Il fattoriale di un
numero è definito per induzione come 0! = 1 e (n + 1)! = (n + 1) ∗ n!. Quindi, ad esempio 
3! = (2 + 1)! = 3 ∗ 2! = 3 ∗ (1 + 1)! = 3 ∗ 2 ∗ 1! = 3 ∗ 2 ∗ (0 + 1)! = 3 ∗ 2 ∗ 1 ∗ 0! = 3 ∗ 2 ∗ 1 ∗ 1. 
In generale n! = n ∗ (n − 1) ∗ (n − 2) ∗ ... ∗ 1. [ File fatt.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // stampare la stringa "Inserire un numero positivo: "
    cout << "Inserire un numero positivo: " << endl;
    // dichiarare una variabile intera n
    int n = 0;
    // leggere n
    cin >> n;
    // se n è minore di zero
    // - stampare "Avevo detto positivo!"
    // - uscire dal programma con l'istruzione return 7;
    if (n < 0) {
        cout << "Avevo detto positivo!" << endl;
        return 7;
    }
    // dichiarare una variabile intera F inizializzata a n
    int F = n;
    /* iterare su una variabile intera i inizializzata a n-1 e decrescente di 1 finché i è maggiore di 1
    - assegnare a F il prodotto di F e i
    */
    for (int i = n-1; i > 1; --i) {
        F = F * i;
    }
    // se F è zero
    // - stampare "Il fattoriale di 0 è 1"
    // altrimenti
    // - stampare "Il fattoriale di " seguito da n, seguito da " è " seguito da F
    if (F == 0) {
        cout << "Il fattoriale di 0 è 1" << endl;
    } else {
        cout << "Il fattoriale di " << n << " e' " << F << endl;
    }
}