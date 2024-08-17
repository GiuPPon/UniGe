#include <iostream>

int main () {
    // dichiarare una costante N intera inizializzandola a un valore moderato (es. 5)
    const int N = 5;
    // dichiarare due variabili v e p di tipo puntatore a int
    int *v;
    int *p;
    // allocare una quantità di memoria pari a N int, assegnandola a v
    v = new int[N];
    // allocare una quantità di memoria pari a N int, assegnandola a p
    p = new int[N];

    // CASO 1 => unico caso corretto
    // eseguire delete[] su v e p
    delete[] v;
    delete[] p;

    // CASO 2
    // allocare una quantità di memoria pari a N int, assegnandola a v
    v = new int[N];
    // eseguire delete[] su v e p
    delete[] v;
    delete[] p;

    // CASO 3
    // assegnare v a p
    p = v;
    // eseguire delete[] su v
    delete[] v;

    // CASO 4
    // eseguire delete su v e p
    delete[] v;
    delete[] p;
}