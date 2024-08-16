/* Crea un array con N elementi di tipo int. Scrivere un programma che dichiara un array a di N 
interi e lo “popola” (assegna valori ai suoi elementi). [ File creaArrayInt.cpp ]
Output atteso:
Valore di a[0] = 10
Valore di a[1] = 9
Valore di a[2] = 8
Valore di a[3] = 7
Valore di a[4] = 6
Valore di a[5] = 5
Valore di a[6] = 4
Valore di a[7] = 3
Valore di a[8] = 2
Valore di a[9] = 1 */

#include <iostream>
using namespace std;

int main () {
    // Dichiarare una costante N con valore 10
    const int N = 10;
    // Dichiarare un array a di N interi
    int a[N];
    // Iterare sulla variabile intera i a partire da 0 e fino a N escluso:
    // Assegnare all'elemento i-esimo di a il valore N-i
    // Stampare l'array in ordine crescente da a[0] a a[N-1] come visto sopra
    for (int i = 0; i < N; ++i) {
        a[i] = N - i;
        cout << "Valore di a[" << i << "] = " << a[i] << endl;
    }
}