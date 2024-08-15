/* Scrivere un programma che legge un numero intero strettamente positivo e stampa il triangolo 
rettangolo fatto di '*' con lato lungo quanto il numero letto. [ File stampatriang.cpp ]
Ad esempio su 5 stamperà:
*
**
***
****
***** 
*/

#include <iostream>
using namespace std;

int main () {
    // stampare la stringa "Inserisci un numero maggiore di 0: "
    cout << "Inserisci un numero maggiore di 0: " << endl;
    // dichiarare una variabile length di tipo int
    int lenght;
    // leggere length
    cin >> lenght;
    /* iterare su i a partire da 1 e fino a length
    - iterare su j a partire da 1 e fino a i
    -- stampare '*'
    */
    for (int i = 1; i <= lenght; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
    cout << endl;
    }
}
