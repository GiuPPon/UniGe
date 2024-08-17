/* Scrivere un programma che verifica se una matrice è simmetrica. Stampa poi su output l’esito della
verifica. [ File verifySymmetry.cpp ]
[SUGGERIMENTO: Una matrice simmetrica è una matrice QUADRATA i cui elementi sono simmetrici rispetto 
alla diagonale principale. Es:
                                    1 2 3
                                    2 0 5
                                    3 5 4
] */

#include <iostream>
using namespace std;

int main () {
    int M = 3;
    int matrix[M][M];

    cout << "Inserisci gli elementi della matrice: " << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << "Inserisci il valore per la cella [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Verifica se la matrice è simmetrica
    bool simm = true;

    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                simm = false;
            }
        }
    }

    // Stampa il risultato
    if (simm) {
        cout << "La matrice e' simmetrica." << endl;
    } else {
        cout << "La matrice non e' simmetrica." << endl;
    }
}
