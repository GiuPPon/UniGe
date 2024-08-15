#include <iostream>
using namespace std;

/* (a) Una funzione che non riceve alcun argomento e non restituisce alcun valore (tipo del valore 
restituito: void) */
void hello() {
    cout << "Hello, world\n";
}

/* (b) Una funzione che riceve un argomento di tipo int e non restituisce alcun valore (tipo del valore
restituito: void) */
void hellomany(int n) {
    cout << "Hello, we are " << n << endl;
}

// (c) Una funzione che non riceve alcun argomento e restituisce un valore di tipo int
int givemefive() {
    return 5;
}
// (d) Una funzione che riceve un argomento di tipo int e restituisce un valore di tipo int
int prossimo(int n) {
    return n + 1;
}
// (e) Una funzione che riceve due argomenti di tipo int e restituisce un valore di tipo int
int somma(int a, int b) {
    return a + b;
}
/* Scrivere in testa al file sorgente le solite istruzioni (vedi parte introduttiva) e in coda un 
programma principale (funzione int main()) che fa il test delle cinque funzioni [ File testf_basic.cpp ] */

int main () {
    // chiamare la funzione hello
    hello();
    // chiamare la funzione hellomany passandole come argomento il valore 5
    hellomany(5);
    // chiamare la funzione givemefive stampando il valore restituito
    cout << givemefive() << endl;
    // chiamare la funzione prossimo passandole come argomento il valore 4 e stampando il valore restituito
    cout << prossimo(4) << endl;
    // chiamare la funzione somma passandole come argomenti i valori 2 e 3 e stampando il valore restituito
    cout << somma(2,3) << endl;
}