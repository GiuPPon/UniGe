/* Scrivere una funzione chiamata replicate, che restituisce void. La funzione riceve come argomenti 
un numero intero N > 0 e un carattere c, e stampa N volte il carattere c. Se il numero non è 
strettamente positivo, la funzione non stampa niente. */

#include <iostream>
using namespace std;

void replicate (int N, char c){
    // iterare su i a partire da 1 e fino a N:
    // - stampare c
    for (int i = 0; i < N; ++i) {
        cout << c;
    }
}

/* Scrivere un programma che fa il test di questa funzione con N pari a 10, 1, 0, -10 e c un carattere a 
scelta. */

int main (){
    // chiamare replicate con argomenti 10 e 'x'
    replicate(10, 'x');
    // stampare un a capo
    cout << endl;
    // chiamare replicate con argomenti 1 e 'x'
    replicate(1, 'x');
    // stampare un a capo
    cout << endl;
    // chiamare replicate con argomenti 0 e 'x'
    replicate(0, 'x');
    // stampare un a capo
    cout << endl;
    // chiamare replicate con argomenti -10 e 'x'
    replicate(-10, 'x');
    // stampare un a capo
    cout << endl;
}