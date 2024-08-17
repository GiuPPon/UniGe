/* Definire una struct StraightLine per rappresentare l’equazione di una retta, completamente 
caratterizzata da coefficiente angolare e quota all’origine
Scrivere un programma che legge i parametri di una retta e li memorizza in una variabile di tipo 
StraightLine, poi legge le coordinate di un punto (memorizzato nella struct definita al punto 1.) e 
verifica se la retta passi o no per il punto.
[SUGGERIMENTO: per calcolare il valore assoluto di un float si usa la funzione fabs (per gli interi è abs).]
[ File retta.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

struct StraightLine {
    double m; // coefficiente angolare
    double q; // quota
};

struct Point {
    double x;
    double y;
};

int main () {
    // Stampare "Inserire i parametri della retta R: "
    cout << "Inserire i parametri della retta R: ";
    // Dichiarare una variabile R di tipo StraightLine
    StraightLine R;
    // Leggere da input i parametri in R.m e R.q
    cin >> R.m;
    cin >> R.q;
    // Stampare "Inserire le coordinate del punto P: "
    cout << "Inserire le coordinate del punto P: ";
    // Dichiarare una variabile P di tipo Point
    Point P;
    // Leggere da input le coordinate e memorizzarle in P.x e P.y
    cin >> P.x;
    cin >> P.y;
    // Stampare il messaggio "La retta R di equazione y=mx+q "...
    cout << "La retta R di equazione y = mx + q ";
    // ... (dove m e q saranno opportunamente sostituiti con R.m e R.q)
    // Se la retta passa per il punto, ossia se il valore assoluto di...
    // ... P.y - R.m*P.x - R.q è minore della tolleranza
    // - Stampare il messaggio " passa "
    // Altrimenti
    // - Stampare il messaggio " non passa "
    // Stampare il messaggio "per il punto di coordinate " ...
    // ...seguito da P.x e P.y e da un a capo
    double differenza = fabs(P.y - R.m * P.x - R.q);
    double tolleranza = 0.0001; 
    if (differenza < tolleranza) {
        cout << "passa ";
    } else {
        cout << "NON passa ";
    }
    cout << "per il punto di coordinate (" << P.x << ", " << P.y << ")." << endl;
}