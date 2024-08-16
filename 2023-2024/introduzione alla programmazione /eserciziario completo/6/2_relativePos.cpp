/* Definire un tipo struct Point per rappresentare punti su un piano cartesiano. 
• Scrivere un programma che legge le informazioni relative a due Point P1 e P2 e, dopo aver verificato
che non siano lo stesso punto, esprime la posizione di P1 rispetto a P2. [ File relativePos.cpp ] 
[SUGGERIMENTO: Per verificare l’uguaglianza tra punti si può controllare il valore delle differenze 
tra le coordinate.]
NOTA. È opportuno considerare una tolleranza. Espresso in notazione matematica, questo significa 
verificare non se x = y, ma se |x − y| < t con t positivo piccolo, una “tolleranza” entro cui 
decidiamo di considerare un valore praticamente pari zero */

#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

int main () {
    // Stampare "Inserire le coordinate del punto P1: "
    cout << "Inserire le coordinate del punto P1: ";
    // Dichiarare una variabile P1 di tipo Point
    Point P1;
    // Leggere da input le coordinate e memorizzarle in P1.x e P1.y
    cin >> P1.x;
    cin >> P1.y;
    // Stampare "Inserire le coordinate del punto P2: "
    cout << "Inserire le coordinate del punto P2: ";
    // Dichiarare una variabile P2 di tipo Point
    Point P2;
    // Leggere da input le coordinate e memorizzarle in P2.x e P2.y
    cin >> P2.x;
    cin >> P2.y;
    // Se P1 e P2 sono lo stesso punto (ossia se hanno le stesse coordinate)
    // - Stampare "I punti sono uguali" seguito da un a capo
    // Altrimenti
    // - Stampare "Il secondo punto è "
    // - Se P2.y > P1.y
    // -- Stampare "in alto "
    // - Altrimenti
    // -- Stampare "in basso "
    // - Se P2.x > P1.x
    // -- Stampare "a destra "
    // - Altrimenti
    // -- Stampare "a sinistra "
    // - Stampare " rispetto al primo" seguito da un a capo
    if ((P1.x == P2.x) && (P1.y == P2.y)) {
        cout << "I punti sono uguali" << endl;
    } else {
        cout << "Il secondo punto e' ";
        if (P2.y > P1.y) {
            cout << "in alto ";
        } else {
            cout << "in basso ";
        }
        if (P2.x > P1.x) {
            cout << "a destra ";
        } else {
            cout << "a sinistra ";
        }
        cout << "rispetto al primo" << endl;
    }
}