/* Scrivere un programma che stampi su output l’array bidimensionale di interi A, di dimensioni M × N.
[ File printMatrix.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // Dichiarare le variabili necessarie, dando a M e N i valori 3 e 4 rispettivamente
    int M = 3;
    int N = 4;
    int a[M][N];
    /* iterare sulle righe della matrice (indice i) fino a M
    *//* iterare sulle colonne della matrice (indice j) fino a N
    - scrivere A[i][j]
    *//*
    */
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}