/* Partendo da esercizio precedente, implementare poi la seguente variante: se per una certo valore di
N-1 il poligono ha un nome (N-1=3 “triangolo”, N-1=4 “rettangolo”, N-1=5 “pentagono”. . . ) sostituire
alla parola “poligono” il nome appropriato. [ File poly2.cpp ]
[SUGGERIMENTO: Usare switch..case con caso default] */

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

int main () {
    int N;
    cout << "Inserisci il numero di punti N: ";
    cin >> N;

    // array di punti
    Point punti[N];

    // coordinate dei punti
    for (int i = 0; i < N; ++i) {
        cout << "Inserire le coordinate del punto " << i + 1 << ": ";
        cin >> punti[i].x;
        cin >> punti[i].y;
    }

    // lunghezza totale della spezzata
    double lunghezzaTotale = 0.0;
    double lunghezzaS1 = 0.0;
    bool LatiUguali = true;

    for (int i = 0; i < N; ++i) {
        double lunghezzaSpezzata = sqrt((punti[i].x - punti[(i - 1 + N) % N].x) * (punti[i].x - punti[(i - 1 + N) % N].x) 
        + (punti[i].y - punti[(i - 1 + N) % N].y) * (punti[i].y - punti[(i - 1 + N) % N].y));
        lunghezzaTotale = lunghezzaTotale + lunghezzaSpezzata;

        if (i == 1) {
            lunghezzaS1 = lunghezzaSpezzata;
        } else if (lunghezzaSpezzata != lunghezzaS1) {
            LatiUguali = false;
        }
    }

    // verifico se la spezzata è chiusa
    bool spezzataChiusa = false;
    if (N > 1) {
        if (punti[0].x == punti[N - 1].x && punti[0].y == punti[N - 1].y) {
            spezzataChiusa = true;
        }
    }

    cout << "La lunghezza totale della spezzata e': " << lunghezzaTotale << endl;

    if (LatiUguali) {
        cout << "Tutti i lati hanno la stessa lunghezza.";
    }
    
    if (spezzataChiusa) {
        switch (N - 1) {
            case 3:
                cout << "Il poligono è un triangolo." << endl;
                break;
            case 4:
                cout << "Il poligono è un rettangolo." << endl;
                break;
            case 5:
                cout << "Il poligono è un pentagono." << endl;
                break;
            default:
                cout << "Il poligono ha " << N - 1 << " lati." << endl;
                break;
        }
    } else {
        cout << "La linea non e' chiusa." << endl;
    }
}