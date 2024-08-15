/* Scrivere una funzione void square(int n) con un parametro di tipo intero che stampa un quadrato 
vuoto con i lati composti di 'x' di dimensioni pari all’argomento. Se l’argomento è negativo o 0 non
stampa nulla ma solleva un’eccezione di tipo string con un messaggio "Errore valore < 1". Ad esempio 
con n=7 stamperà:
x x x x x x x
x           x
x           x
x           x
x           x
x           x
x x x x x x x
[SUGGERIMENTO: IMPORTANTE: per rendere il risultato più graficamente simile a un quadrato ogni x 
(minuscola) andrà stampata usando la stringa "x " e ogni cella vuota come una stringa composta da due 
spazi " ". Quindi ogni elemento stampato per comporre il quadrato è una stringa di due caratteri.]
[ File testf_square.cpp ] */

#include <iostream>
#include <string>
using namespace std;

void square(int n) {
    if (n <= 0) {
        string err = "Errore valore < 1";
        throw err;
    }

    for (int i = 0; i < n; ++i) {
        cout << "x ";
    } 
    cout << endl;

     for (int i = 0; i < n - 2; ++i) {
        cout << "x ";
        for (int j = 0; j < n - 2; ++j) {
            cout << "  ";
        }
        cout << "x " << endl;
    }

    for (int i = 0; i < n; ++i) {
        cout << "x ";
    }
    cout << endl;
}

int main () {
    try {
        cout << "Inserire size del quadrato: ";
        int size;
        cin >> size;
        square(size);
    } catch (string err) {
        cout << err << endl;
    }
}