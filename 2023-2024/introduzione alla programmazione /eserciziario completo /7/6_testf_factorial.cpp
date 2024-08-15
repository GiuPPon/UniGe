/* Scrivere una funzione che dato come argomento un intero non negativo n restituisce come risultato il
suo fattoriale. Il fattoriale di un numero è definito per induzione come 0! = 1 e (n + 1)! = (n + 1) ∗ n!.
Quindi, ad esempio 3! = (2 + 1)! = 3 ∗ 2! = 3 ∗ (1 + 1)! = 3 ∗ 2 ∗ 1! = 3 ∗ 2 ∗ (0 + 1)! 
= 3 ∗ 2 ∗ 1 ∗ 0! = 3 ∗ 2 ∗ 1 ∗ 1. In generale n! = n ∗ (n − 1) ∗ (n − 2) ∗ ... ∗ 1. */

#include <iostream>
using namespace std;

int factorial(int n){
    // se n è minore di zero
    // - stampare un messaggio di errore pertinente
    // - ritornare -1
    if (n < 0) {
        cout << "errore: valore negativo" << endl;
        return -1;
    }
    // se n è zero
    // - restituire 1
    if (n == 0) {
        return 1;
    }
    /* iterare su una variabile intera i inizializzata a n-1 e decrescente di 1 finché i è maggiore di 1
    - assegnare a n il prodotto di n e i
    */
    for (int i = n - 1; i > 1; --i) {
        n = n * i;
    } 
    // restituire n
    return n;
}

// Scrivere un programma per testare la funzione factorial:
int main () {
    // stampare la stringa "Inserire un numero positivo: "
    cout << "Inserire un numero positivo: ";
    // dichiarare una variabile intera num
    int num;
    // leggere num
    cin >> num;
    // richiamare la funzione factorial su num e salvare il risultato
    int result;
    result = factorial(num);
    // se risultato non è negativo
    // - stampare il risultato seguito da " è il fattoriale di " seguito da num
    // altrimenti stampare messaggio di errore
    if (result > 0) {
        cout << result << " e' il fattoriale di " << num << endl;
    } else {
        cout << "errore" << endl;
    }
}