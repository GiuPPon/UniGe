/* Scrivere un programma che definisce due valori costanti, M pari a 5 e N pari a 8. Dichiara poi un 
array bidimensionale a di dimensioni M×N con int a[M][N]; (M=righe e N=colonne), e riempe ogni riga 
con N valori pari all’indice della riga corrente. Terminata la fase di inizializzazione dell’array, 
il programma stampa l’array. [ File bidimensional.cpp ]
Output atteso con M=5 e N=8:
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 */

#include <iostream>
using namespace std;

int main () {
    const int M = 5;
    const int N = 8;
    int a[M][N];

    for (int i = 0; i < M; i++) {
        for (int k = 0; k < N; k++) {
            a[i][k] = i;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int k = 0; k < N; k++) {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}
