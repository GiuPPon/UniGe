/* Scrivere una funzione dist che riceve come argomenti in ingresso due oggetti p1 e p2 di tipo struct
Punto. La funzione calcola e restituisce in uscita la distanza euclidea tra i due punti, un valore di 
tipo double definito come da teorema di Pitagora (somma tra la differenza tra le coordinate x, al 
quadrato, e la differenza tra le coordinate y, al quadrato, il tutto sotto radice quadrata).
Scrivere un programma che, fissato un valore ≥ 2 per una costante N, legge da input (cin) gli elementi
di un array di Punto lungo N, che rappresenta una linea spezzata composta da N−1 segmenti, ne calcola 
la lunghezza totale tot usando la funzione dist, e stampa un messaggio del tipo “La lunghezza della 
spezzata è tot”. [ File testf_poly1.cpp ] */

#include <iostream> 
#include <cmath>
using namespace std;

struct Punto {
double x, y;
};

double dist(Punto& p1, Punto& p2) {
    double deltaX = p2.x - p1.x;
    double deltaY = p2.y - p1.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

int main() {
    int N = 3; 
    Punto punti[N];

    cout << "Inserisci le coordinate dei punti:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Punto " << i + 1 << ":" << endl;
        cout << "x: ";
        cin >> punti[i].x;
        cout << "y: ";
        cin >> punti[i].y;
    }

    double lunghezzaTotale = 0;
    for (int i = 0; i < N - 1; ++i) {
        lunghezzaTotale = lunghezzaTotale + dist(punti[i], punti[i + 1]);
    }

    cout << "La lunghezza della spezzata e' " << lunghezzaTotale << endl;
}