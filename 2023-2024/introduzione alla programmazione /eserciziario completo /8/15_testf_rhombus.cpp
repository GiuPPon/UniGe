/* Scrivere una funzione con un parametro n di tipo intero che stampa un rombo di asterischi che sulla
diagonale ha 2*n+1 caratteri. Ad esempio, dato 8 stampa
        *
       ***
      *****
     *******
    *********
   ***********
  *************
 ***************
*****************
 ***************
  *************
   ***********
    *********
     *******
      *****
       ***
        *
che sulla diagonale ha 17 caratteri. [ File testf_rhombus.cpp ] 
[SUGGERIMENTO: 1)è più facile stampare il rombo con due cicli, il primo per le righe in cui il numero
di asterischi cresce e il secondo per le righe in cui il numero di asterischi diminuisce.]
[SUGGERIMENTO: 2) volendo si può usare la funzione replicate2_line] */


#include <iostream> 
using namespace std;

void rombo(int n) {
    // prima parte del triangolo (?)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // riga centrale
    for (int i = 0; i < 2 * n + 1; ++i) {
        cout << "*";
    }
    cout << endl;

    // seconda parte del triangolo
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main () {
    int num;
    cout << "inserire un numero intero positivo: ";
    cin >> num;
    rombo(num);
}