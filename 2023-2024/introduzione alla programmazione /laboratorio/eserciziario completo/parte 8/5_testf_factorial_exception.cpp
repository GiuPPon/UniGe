/* Scrivere una funzione che dato come argomento un intero non negativo n restituisce come risultato il
suo fattoriale. Il fattoriale di un numero è definito per induzione come 0! = 1 e (n + 1)! = (n + 1) ∗ n!. 
Quindi, ad esempio 3! = (2 + 1)! = 3 ∗ 2! = 3 ∗ (1 + 1)! = 3 ∗ 2 ∗ 1! = 3 ∗ 2 ∗ (0 + 1)! = 3 ∗ 2 ∗ 1 ∗ 0! 
= 3 ∗ 2 ∗ 1 ∗ 1. In generale n! = n ∗ (n − 1) ∗ (n − 2) ∗ ... ∗ 1. Usare le eccezioni per gestire i 
casi di errore. [ File testf_factorial_exception.cpp ] */

#include <iostream>
#include <string>
using namespace std;

int factorial(int n){
    // se n è minore di zero
    // - dichiarare una variabile err di tipo string ed inizializzarla con un messaggio di errore pertinente
    // - sollevare una eccezione con argomento err (throw err)
    if (n < 0) {
        string err = "Errore: numero negativo";
        throw err;
    }
    // se n è zero
    // - restituire uno
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

int main () {
    try {
    // stampare la stringa "Inserire un numero positivo: "
    cout << "Inserire un numero positivo: " << endl;
    // dichiarare una variabile intera num
    int num;
    // leggere num
    cin >> num;
    // stampare il risultato della chiamata di factorial su num seguito da " è il fattoriale di " seguito da num
    cout << factorial(num) << " e' il fattoriale di " << num << endl;
    }
    catch(string& err) {
        // stampare err, ossia il messaggio di errore
        cout << err << endl;
    }
}