/*  Scrivere una funzione ricorsiva unsigned fibonacci(unsigned n) per il calcolo del numero di 
Fibonacci, secondo la seguente definizione:
fibonacci(0) = 1
fibonacci(1) = 1
fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)  */

unsigned fibonacci(unsigned n) {
    // se n==0 oppure n==1 ritorna 1
    if ((n == 0) || (n == 1)) {
        return 1;
    }
    // altrimenti ritorna la somma del numero di fibonacci di n-1 e del numero di fibonacci di n-2
    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}