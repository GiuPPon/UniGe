/* . Scrivere una funzione che preso come argomento numero intero strettamente positivo stampa un 
triangolo rettangolo fatto di '*' con lato lungo quanto il numero letto. Ad esempio, ricevuto come 
argomento il valore 5, stamperà:
*
**
***
****
*****
Come per l’esercizio precedente dichiarare una struct OutOfRangeError con un campo stringa chiamato 
functionName, un campo stringa chiamato paramName e uno di tipo intero chiamato paramValue. Questa 
struct sarà usata sia per segnalare errori in replicate(...) che in triangle(...)
[ File testf_triangle_exception.cpp ] */

#include <iostream>
#include <string>
using namespace std;

struct OutOfRangeError {
    string functionName;
    string paramName;
    int paramValue;
};

void replicate(int length, char c){
    if (length < 0) {
        OutOfRangeError err;
        err.functionName = "replicate";
        err.paramName = "length";
        err.paramValue = length;
        throw err;
    }

    for (int i = 0; i < length; ++i) {
        cout << c;
    }
}

void triangle(int length){
    // se len non è maggiore di zero
    // - dichiarare una variabile err di tipo OutOfRangeError
    // - inizializzare il campo functionName di err con la stringa triangle
    // - inizializzare il campo paramName di err con la stringa length
    // - inizializzare il campo paramValue con il valore del parametro length
    // - sollevare una eccezione con argomento err (throw err)
    if (length <= 0) {
        OutOfRangeError err;
        err.functionName = "triangle";
        err.paramName = "length";
        err.paramValue = length;
        throw err;
    }
    /* iterare su i a partire da 1 e fino a length
    - chiamare replicate(...) su i e '*'
    - stampare un a capo
    */
    for (int i = 0; i <= length; ++i) {
        replicate(i, '*');
        cout << endl;
    }
}

int main () {
    try {
    // stampare la stringa "Inserisci un numero maggiore di 0: "
    cout << "Inserisci un numero maggiore di 0: ";
    // dichiarare una variabile len di tipo int
    int len;
    // leggere len
    cin >> len;
    // chiamare triangle su len
    triangle(len);
    }
    catch(OutOfRangeError& err) {
        // stampare un messaggio di errore usando i campi di err
        cout << "Errore: Il parametro " << err.paramName << " (" << err.paramValue;
        cout << ") non è valido per la funzione " << err.functionName << endl;
    }
}