/* Scrivere un programma che, dato un valore di N preimpostato ma modificabile, legge le coordinate di 
N punti in un array di Point (che rappresenta una spezzata o “polilinea” costituita da N-1 segmenti), e:
• calcola e stampa la lunghezza totale della spezzata (vedi Esercizio 6.2, dist.cpp)
• verifica se i lati hanno tutti la stessa lunghezza
• verifica se la spezzata è chiusa (cioè se il primo e ultimo punto coincidono), e se lo è scrive un 
messaggio: “La linea è chiusa e quindi definisce un poligono”. Se i lati hanno tutti la stessa
lunghezza, aggiungere: “regolare”.
[ File poly1.cpp ] */

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
    
    if (spezzataChiusa && LatiUguali) {
        cout << "La linea e' chiusa e quindi definisce un poligono regolare." << endl;
    } else if (spezzataChiusa) {
        cout << "La linea e' chiusa e quindi definisce un poligono." << endl;
    } else {
        cout << "La linea non e' chiusa." << endl;
    }
}