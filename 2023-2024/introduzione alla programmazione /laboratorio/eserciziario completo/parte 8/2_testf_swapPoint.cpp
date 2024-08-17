/* Scrivere una funzione di nome swapPoint che prende due argomenti p1 e p2 di tipo Point (una struct),
e quando viene chiamata ne scambia i valori, e restituisce void. Passare i parametri per riferimento 
swapPoint(Point& x, Point& y). Provare a passare i parametri per valore, che cosa succede?
[ File testf_swapPoint.cpp ] */

#include <iostream>
using namespace std;

struct Point {
double x;
double y;
};

void swapPoint(Point& P1, Point& P2){
    // scambiare i valori x e y tra P1 e P2
    double tempX = P1.x;
    double tempY = P1.y;
    P1.x = P2.x;
    P1.y = P2.y;
    P2.x = tempX;
    P2.y = tempY;
}
void printPoint(const Point& P){
    // stampare le coordinate x e y di P
    cout << "(" << P.x << ", " << P.y << ")" << endl;
}
int main (){
    // dichiarare due punti P1 e P2
    Point P1, P2;
    // assegnare valori a scelta a P1 e P2
    P1 = {4.8, 5};
    P2 = {13, 6.3};
    // stampare P1 e P2 usando printPoint(...)
    cout << "punto 1: ";
    printPoint(P1);
    cout << "punto 2: ";
    printPoint(P2);
    // scambiare valori P1 e P2 usando swapPoint(...)
    swapPoint(P1, P2);
    // stampare P1 e P2 usando printPoint(...) (per osservare risultato)
    cout << "punto 1: ";
    printPoint(P1);
    cout << "punto 2: ";
    printPoint(P2);
}