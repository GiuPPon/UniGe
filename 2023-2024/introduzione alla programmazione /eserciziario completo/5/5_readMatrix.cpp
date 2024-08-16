/* Scrivere un programma che permetta di riempire l’array bidimensionale (matrice) di interi A, di 
dimensioni M × N, con valori letti da input. [ File readMatrix.cpp ] */

#include <iostream>
using namespace std;

int main () {
    // Dichiarare le variabili necessarie, dando a M e N i valori 3 e 4 rispettivamente
    int M = 3;
    int N = 4;
    int a[M][N];
    /* iterare sulle righe della matrice (indice i) fino a M
    *//* iterare sulle colonne della matrice (indice j) fino a N
    - leggere un valore e memorizzarlo in A[i][j]
    *//*
    */
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Inserisci il valore per la cella [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}