/* Scrivere una funzione ricorsiva unsigned fact(unsigned n) per il calcolo del fattoriale di un intero 
positivo n: */

unsigned fact(unsigned n) {
    // se n==0 ritorna 1
    if (n == 0) {
        return 1;
    }
    // altrimenti ritorna n moltiplicato per il fattoriale di n-1
    else {
        return (n * fact(n - 1));
    }
}
