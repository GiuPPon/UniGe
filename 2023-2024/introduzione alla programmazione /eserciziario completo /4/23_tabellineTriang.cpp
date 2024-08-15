/* La tavola pitagorica è simmetrica, quasi metà di essa contiene informazione ripetuta. Precisamente,
N (N − 1) / 2 elementi sopra la diagonale sono uguali a N (N − 1) / 2 elementi sotto la diagonale.
  1 2 3 4
1 1 2 3 4
2 2 4 6 8
3 3 6 9 12
4 4 8 12 16
N = 4, N (N − 1) / 2 = 6
Scrivere un programma che usa un array monodimensionale per rappresentare la tavola pitagorica usando
solo gli N (N + 1)/2 elementi necessari. Dal punto di vista dell’utente il programma deve comportarsi 
in modo identico a quello dell’esercizio 14. [ File tabellineTriang.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int N;
    cout << "Inserisci la dimensione della tavola pitagorica: ";
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << i * j << " ";
            if (i * j < 10)
                std::cout << " "; // Aggiunge uno spazio per allineare gli elementi
        }
        cout << endl;
    }
}