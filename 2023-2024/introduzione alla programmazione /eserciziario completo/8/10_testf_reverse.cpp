/* Scrivere una funzione con un parametro intero k che restituisce il numero ottenuto leggendo k da
destra verso sinistra. Ad esempio su 17 restituisce 71, su 27 458 restituisce 85472 e così via.
[ File testf_reverse.cpp ] */

#include <iostream>
using namespace std;

int reverse(int k){
    // dichiarare una variabile intera sign inizializzata con 1
    int sign = 1;
    // se k minore di zero
    // - assegnare -1 a sign
    // - assegnare -k a k
    if (k < 0) {
        sign = -1;
        k = -k;
    }
    // dichiarare una variabile intera inv inizializzata a zero
    int inv = 0;
    /* finché k è maggiore di zero
    - dichiarare una variabile intera mod inizializzata con il resto della divisione intera di k per 10
    - assegnare a k il quoziente di k per 10
    - assegnare a inv la moltiplicazione di inv per 10
    - assegnare a inv la somma di inv e mod
    */
    while (k > 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10;
        inv = inv + mod;
    }
    // restituire inv moltiplicato per sign
    return (inv * sign);
}

int main () {   
    // stampare la stringa "Inserire un numero intero: "
    cout << "Inserire un numero intero: ";
    // dichiarare una variabile intera z
    int z;
    // leggere z
    cin >> z;
    // stampare su una nuova riga la stringa "Rovesciando " seguita da z
    // stampare la stringa " si ottiene " seguita dal risultato della chiamata di...
    // ... reverse su z
        cout << "Rovesciando " << z << " si ottiene " << reverse(z) << endl;
}