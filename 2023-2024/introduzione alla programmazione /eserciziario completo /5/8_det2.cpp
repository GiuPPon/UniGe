/* Scrivere un programma che, letta una matrice di float A, quadrata di dimensione 2x2, calcoli il
determinante di tale matrice e lo stampi in uscita. [ File det2.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int M = 2;
    float a[M][M];

    cout << "Inserisci i valori della matrice 2x2: " << endl;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << "Inserisci il valore per A[" << i << "][" << j << "]: ";
                cin >> a[i][j];
            }
        }

    // Calcolo del determinante    -->    (a * d) - (b * c)
    float determinante = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

    // Stampare il determinante
    cout << "Il determinante della matrice e': " << determinante << endl;
}