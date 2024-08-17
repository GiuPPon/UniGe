/* Scrivere un programma che definisce un valore costante, N pari a 10.
Dichiara poi un array bidimensionale tavolaPitagorica di dimensioni N×N, e lo riempie dei valori della
tavola pitagorica, dove l’elemento (i, j) contiene il prodotto tra i+1 e j+1 (perché?).
Infine chiede all’utente una coppia di valori tra 1 e 10 (verificare che siano entrambi nell’intervallo
altrimenti richiederli entrambi), e restituisce il loro prodotto – ottenuto consultando la tavola
pitagorica come una look-up table, e non eseguendo la moltiplicazione. [ File tabelline.cpp ] */

#include <iostream>
using namespace std;

int main () {
    const int N = 10;
    int a[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = (i+1) * (j+1);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}