/* Scrivere una funzione ricorsiva unsigned coeffBin(unsigned n, unsigned k) per il calcolo del 
coefficiente binomiale. */
#include <string>
using namespace std;

unsigned coeffBin(unsigned n, unsigned k) {
    // se k>n solleva eccezione
    if (k > n) {
        string err = "Errore";
        throw err;
    }
    // se n==k oppure k==0 ritorna 1
    if ((n == k) || (n == 0)) {
        return 1;
    }
    // altrimenti ritorna la somma del coefficiente binomiale di n-1 e k-1 e del coefficiente binomiale
    // di n-1 e k
    else {
        return (coeffBin(n - 1, k - 1) + coeffBin(n - 1, k));
    }
} 