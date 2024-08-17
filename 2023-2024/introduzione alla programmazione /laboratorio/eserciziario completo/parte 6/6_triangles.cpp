/* Definire una struct Triangle per rappresentare triangoli sul piano cartesiano con coordinate intere. 
Triangle includerà dunque tre campi che rappresentano altrettanti punti. Triangle avrà inoltre due 
ulteriori campi per memorizzare area e perimetro del triangolo.
[SUGGERIMENTO: Per memorizzare i vertici del triangolo, potete usare una variante della struct Point 
del punto 1.]
• Scrivere un programma che legge le coordinate dei 3 vertici di un triangolo e le memorizza in una 
struct di tipo Triangle. Verifica quindi che i tre vertici siano distinti. Poi calcola il perimetro e
l’area del triangolo e memorizza le informazioni nei corrispondenti campi della struct.
Infine stampa area e perimetro leggendoli dalla struct. [ File triangles.cpp ]
• Scrivere un programma che legge e calcola le informazioni relative a 3 triangoli, memorizzate in 
altrettante variabili di tipo Triangle. Verificare poi quale dei tre triangoli abbia area maggiore e 
stampare un opportuno messaggio di output. [ File largestTriangle.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
    double area;
    double perimetro;
};

int main() {
    Triangle triangle;

    cout << "Inserisci le coordinate del primo punto: ";
    cin >> triangle.p1.x;
    cin >> triangle.p1.y;

    cout << "Inserisci le coordinate del secondo punto: ";
    cin >> triangle.p2.x;
    cin >> triangle.p2.y;

    cout << "Inserisci le coordinate del terzo punto: ";
    cin >> triangle.p3.x;
    cin >> triangle.p3.y;

    // Verifica che i punti siano distinti
    if ((triangle.p1.x == triangle.p2.x && triangle.p1.y == triangle.p2.y) ||
        (triangle.p1.x == triangle.p3.x && triangle.p1.y == triangle.p3.y) ||
        (triangle.p2.x == triangle.p3.x && triangle.p2.y == triangle.p3.y)) {
        cout << "Errore: I punti non possono essere uguali." << endl;
    }

    // distanza = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    
    double distanzap1p2 = sqrt((triangle.p2.x - triangle.p1.x) * (triangle.p2.x - triangle.p1.x) 
    + (triangle.p2.y - triangle.p1.y) * (triangle.p2.y - triangle.p1.y));
    double distanzap2p3 = sqrt((triangle.p3.x - triangle.p2.x) * (triangle.p3.x - triangle.p2.x) 
    + (triangle.p3.y - triangle.p2.y) * (triangle.p3.y - triangle.p2.y));
    double distanzap3p1 = sqrt((triangle.p3.x - triangle.p1.x) * (triangle.p3.x - triangle.p1.x) 
    + (triangle.p3.y - triangle.p1.y) * (triangle.p3.y - triangle.p1.y));

    // formula di erone
    double erone = (distanzap1p2 + distanzap2p3 + distanzap3p1) / 2;

    triangle.area = sqrt(erone * (erone - distanzap1p2) * (erone - distanzap2p3) * (erone - distanzap3p1));
    triangle.perimetro = distanzap1p2 + distanzap2p3 + distanzap3p1;

    cout << "Area del triangolo: " << triangle.area << endl;
    cout << "Perimetro del triangolo: " << triangle.perimetro << endl;
}
