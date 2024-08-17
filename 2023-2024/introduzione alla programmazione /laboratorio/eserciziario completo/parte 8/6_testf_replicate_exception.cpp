/* Scrivere una funzione chiamata replicate, che restituisce void. La funzione riceve come argomenti 
un numero intero N > 0 e un carattere c, e stampa N volte il carattere c. Usare le eccezioni per 
gestire i casi di errore. In particolare la funzione replicate come segue. Dichiarare una struct 
OutOfRangeError con un campo stringa chiamato functionName, un campo stringa chiamato paramName e uno 
di tipo intero chiamato paramValue. [ File testf_replicate_exception.cpp ] */

#include <iostream>
#include <string>
using namespace std;

struct OutOfRangeError {
    string functionName;
    string paramName;
    int paramValue;
};

void replicate(int length, char c){
    // se length non è maggiore di zero
    // - dichiarare una variabile err di tipo OutOfRangeError
    // - inizializzare il campo functionName di err con la stringa replicate
    // - inizializzare il campo paramName di err con la stringa length
    // - inizializzare il campo paramValue con il valore del parametro length
    // - sollevare una eccezione con argomento err (throw err)
    if (length < 0) {
        OutOfRangeError err;
        err.functionName = "replicate";
        err.paramName = "length";
        err.paramValue = length;
        throw err;
    }
    /* iterare su i a partire da 1 e fino a length
    - stampare c
    */
    for (int i = 0; i < length; ++i) {
        cout << c;
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
    // stampare la stringa "Inserisci il carattere da replicare: "
    cout << "Inserisci il carattere da replicare: ";
    // dichiarare una variabile c di tipo char
    char c;
    // leggere c
    cin >> c;
    // chiamare replicate su len e c
    replicate(len, c);
    }
    catch(OutOfRangeError& err) {
        // stampare un messaggio d'errore usando i campi di err
        cout << "Errore: Il parametro " << err.paramName << " (" << err.paramValue;
        cout << ") non è valido per la funzione " << err.functionName << endl;
    }
} 