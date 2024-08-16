/*(Puntatori Array + Funzioni) Quando si passa un array come argomento ad una funzione, il passaggio è
per riferimento ovvero in realtà viene passato un puntatore all’indirizzo dove inizia l’array ed è 
questa la ragione per cui all’interno di una funzione non si conosce la dimensione dell’array. Vediamo 
in pratica questo aspetto implementando il seguente programma. */

#include <iostream>
using namespace std;

// dichiarare una costante N di tipo int inizializzata ad un valore strettamente maggiore di 0
const int N = 5;

// dichiarare la funzione
void f(int* array) {
    // stampare il messaggio "Dimensione del parametro = " seguito dalla dimensione di array e andare a capo
    cout << "Dimensione del parametro = " << sizeof(array) << endl;
}

int main () {
    // dichiarare un array v di N interi
    int v[N];
    // dichiarare un puntatore a interi p inizializzato con v
    int *p = v;
    // stampare il messaggio "Dimensione di v = " seguito dalla dimensione di v e andare a capo
    cout << "Dimensione di v = " << sizeof(v) << endl;
    // stampare il messaggio "Dimensione di p = " seguito dalla dimensione di p e andare a capo
    cout << "Dimensione di p = " << sizeof(p) << endl;
    // chiamare f su v
    f(v);
}

/* [SUGGERIMENTO: Per ottenere la dimensione di un valore usare sizeof.]
Nota. Notiamo che la dimensione dell’array nella funzione è persa, per questo motivo è necessario 
passarla come parametro aggiuntivo come mostrato nel cheatsheet di questa sezione. 
[ File arrayptr.cpp ] */