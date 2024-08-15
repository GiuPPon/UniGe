/* Definire una struct Rect per rappresentare un rettangolo mediante i vertici (Point) in alto a 
sinistra e in basso a destra. Scrivere un programma che legge in input due rettangoli, chiedendo le 
coordinate dei punti top_left e bottom_right di ciascuno; verifica se uno dei due rettangoli sia 
contenuto nell’altro; e stampa un messaggio di output opportuno. [ File rectanglesIn.cpp ] */

#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Rectangle {
    Point top_left;
    Point bottom_right;
};

int main () {
    Rectangle r1;
    cout << "Inserisci le coordinate del vertice in alto a sinistra del primo rettangolo: ";
    cin >> r1.top_left.x; 
    cin >> r1.top_left.y;
    cout << "Inserisci le coordinate del vertice in basso a destra del primo rettangolo: ";
    cin >> r1.bottom_right.x;
    cin >> r1.bottom_right.y;

    // Definizione e input del secondo rettangolo
    Rectangle r2;
    cout << "Inserisci le coordinate del vertice in alto a sinistra del secondo rettangolo: ";
    cin >> r2.top_left.x >> r2.top_left.y;
    cout << "Inserisci le coordinate del vertice in basso a destra del secondo rettangolo: ";
    cin >> r2.bottom_right.x >> r2.bottom_right.y;

    // Verifica se uno dei rettangoli è contenuto nell'altro
    if (r1.top_left.x <= r2.top_left.x && r1.top_left.y >= r2.top_left.y &&
        r1.bottom_right.x >= r2.bottom_right.x && r1.bottom_right.y <= r2.bottom_right.y) {
        cout << "Il secondo rettangolo è contenuto nel primo rettangolo." << endl;
    } else if (r2.top_left.x <= r1.top_left.x && r2.top_left.y >= r1.top_left.y &&
               r2.bottom_right.x >= r1.bottom_right.x && r2.bottom_right.y <= r1.bottom_right.y) {
        cout << "Il primo rettangolo è contenuto nel secondo rettangolo." << endl;
    } else {
        cout << "I rettangoli non sono contenuti l'uno nell'altro." << endl;
    }
}