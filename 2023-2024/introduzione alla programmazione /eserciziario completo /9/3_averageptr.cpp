/* (Aritmetica dei Puntatori) Modificare il programma che legge N valori reali, li memorizza in un 
array v di lunghezza N, e ne restituisce la media richiesto dall’Esercizio 7 della Sezione 4 usando 
questa volta l’aritmetica dei puntatori per migliorarne l’efficienza, secondo il seguente schema 
(quindi non accedere mai all’array tramite [indice] ma solo via puntatore): */

#include <iostream>
using namespace std;

int main () {
    // dichiarare una costante N di tipo int inizializzata ad un valore strettamente maggiore di 0
    // dichiarare un array v di N float
    const int N = 5;   
    float v[N];
    // dichiarare un puntatore a float p inizializzato con v
    float *p = v;
    // *** Inserimento Valori Array ***
    /* iterare su i a partire da 0 e fino a N-1
    - leggere un valore intero memorizzandolo nella cella puntata da p
    - incrementate p
    */
    cout << "Inserire " << N << " numeri:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> *p;
        ++p;
    }
    // *** Stampa Valori Array ***
    // assegnare v a p (per ricominciare da capo a scorrere v)
    // stampare l'array in ordine crescente da v[0] a v[N-1] su un'unica riga usando solo il puntatore p
    cout << "I valori contenuti nell'array a sono: { ";
    p = v;
    for (int i = 0; i < N; ++i) {
        cout << *p;
        ++p;
        if (i != (N - 1)) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
    // *** Calcolo Media ***
    // dichiarare una variabile sum di tipo float e inizializzarla a zero
    // assegnare v a p (per ricominciare da capo a scorrere v)
    /* iterare su i a partire da 0 e fino a N-1
    - sommare il contenuto della cella puntata da p a sum
    - incrementare p
    */
    float sum = 0;
    p = v;
    for (int i = 0; i <= N - 1; ++i) {
        sum = sum + *p;
        ++p;
    }
    // *** Stampa Media ***
    // stampare la divisione di sum per N
    cout << "La media dei valori contenuti nell'array a e': " << sum / N << endl;
}