/* Scrivere un programma che legge le informazioni relative a due Point P1 e P2 e ne stampa la distanza.
[ File dist.cpp ]
[SUGGERIMENTO: dati due punti P1 = (x1, y1) e P2 = (x2, y2), la loro distanza si calcola come D
(P1, P2) = pow(x2 − x1)^2 + ( y2 − y1)^2.] */

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

int main () {
    // Stampare "Inserire le coordinate del punto P1: "
    // Dichiarare una variabile P1 di tipo Point
    // Leggere da input le coordinate e memorizzarle in P1.x e P1.y
    cout << "Inserire le coordinate del punto P1: ";
    Point P1;
    cin >> P1.x;
    cin >> P1.y;
    
    // Stampare "Inserire le coordinate del punto P2: "
    // Dichiarare una variabile P2 di tipo Point
    // Leggere da input le coordinate e memorizzarle in P2.x e P2.y
    cout << "Inserire le coordinate del punto P2: ";
    Point P2;
    cin >> P2.x;
    cin >> P2.y;

    // Calcolare e stampare la distanza tra i due punti
    double distanza = sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));
    if ((P1.x == P2.x) && (P1.y == P2.y)) {
        cout << "I punti sono uguali" << endl;
    } else {
        cout << "La distanza tra i due punti e' " << distanza << endl;
    }
}