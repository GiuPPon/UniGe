/* Riscrivere il programma dell’esercizio precedente spostando la funzione main dopo i comandi 
iniziali, ma prima di tutte le altre funzioni. Verificare che la compilazione non ha successo. 
(Perché?) Modificare poi tale programma scrivendo i prototipi delle cinque funzioni subito prima 
della funzione main. I prototipi devono specificare quanto indicato qui di seguito:
// funzione hello restituisce void e non richiede argomenti
// funzione hellomany restituisce void e richiede un argomento di tipo int
// funzione givemefive restituisce un valore di tipo int e non richiede argomenti
// funzione prossimo restituisce un valore di tipo int e richiede un argomento di tipo int
// funzione somma restituisce un valore di tipo int e richiede due argomenti di tipo int
Riprovare a compilare e a eseguire.
[ File testf_basic2.cpp ] */

#include <iostream>
using namespace std;

void hello();
void hellomany(int);
int givemefive();
int prossimo(int);
int somma (int, int);

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

void hello() {
    cout << "Hello, world\n";
}

void hellomany(int n) {
    cout << "Hello, we are " << n << endl;
}

int givemefive() {
    return 5;
}

int prossimo(int n) {
    return n + 1;
}

int somma(int a, int b) {
    return a + b;
}