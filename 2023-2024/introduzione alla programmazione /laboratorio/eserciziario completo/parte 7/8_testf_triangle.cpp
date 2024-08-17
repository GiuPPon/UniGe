/* Scrivere una funzione che preso come argomento numero intero strettamente positivo stampa un 
triangolo rettangolo fatto di '*' con lato lungo quanto il numero letto. Ad esempio, ricevuto come 
argomento il valore 5, stamperà:
*
**
***
****
*****
*/

#include <iostream>
using namespace std;

void replicate (int N, char c){
    for (int i = 0; i < N; ++i) {
        cout << c;
    }
}

void triangle(int length){
    // iterare su i a partire da 1 e fino a length:
    // - chiamare replicate su i e '*'
    // - stampare un a capo
    for (int i = 0; i <= length; ++i) {
        replicate(i, '*');
        cout << endl;
    }
}


// Scrivere un programma per testare la funzione:
int main () {
    // stampare la stringa "Inserisci un numero maggiore di 0: "
    cout << "Inserisci un numero maggiore di 0: ";
    // dichiarare una variabile len di tipo int
    int len;
    // leggere len
    cin >> len;
    // se len e' positivo chiamare triangle su len
    // altrimenti stampare un messaggio di errore
    if (len > 0) {
        triangle(len);
    } else {
        cout << "Errore: lunghezza negativa" << endl;
    }
}