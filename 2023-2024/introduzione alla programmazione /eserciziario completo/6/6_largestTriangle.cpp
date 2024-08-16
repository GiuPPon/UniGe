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
};

int main() {
    Triangle triangles[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Triangolo " << i + 1 << endl;

        cout << "Inserisci le coordinate del primo punto: ";
        cin >> triangles[i].p1.x;
        cin >> triangles[i].p1.y;

        cout << "Inserisci le coordinate del secondo punto: ";
        cin >> triangles[i].p2.x;
        cin >> triangles[i].p2.y;

        cout << "Inserisci le coordinate del terzo punto: ";
        cin >> triangles[i].p3.x;
        cin >> triangles[i].p3.y;

        if ((triangles[i].p1.x == triangles[i].p2.x && triangles[i].p1.y == triangles[i].p2.y) ||
            (triangles[i].p1.x == triangles[i].p3.x && triangles[i].p1.y == triangles[i].p3.y) ||
            (triangles[i].p2.x == triangles[i].p3.x && triangles[i].p2.y == triangles[i].p3.y)) {
            cout << "Errore: I punti non possono essere uguali." << endl;
        }

       double distanzap1p2 = sqrt((triangles[i].p2.x - triangles[i].p1.x) * (triangles[i].p2.x - triangles[i].p1.x) 
        + (triangles[i].p2.y - triangles[i].p1.y) * (triangles[i].p2.y - triangles[i].p1.y));
        double distanzap2p3 = sqrt((triangles[i].p3.x - triangles[i].p2.x) * (triangles[i].p3.x - triangles[i].p2.x) 
        + (triangles[i].p3.y - triangles[i].p2.y) * (triangles[i].p3.y - triangles[i].p2.y));
        double distanzap3p1 = sqrt((triangles[i].p3.x - triangles[i].p1.x) * (triangles[i].p3.x - triangles[i].p1.x) 
        + (triangles[i].p3.y - triangles[i].p1.y) * (triangles[i].p3.y - triangles[i].p1.y));

        // formula di erone
        double erone = (distanzap1p2 + distanzap2p3 + distanzap3p1) / 2;

        triangles[i].area = sqrt(erone * (erone - distanzap1p2) * (erone - distanzap2p3) * (erone - distanzap3p1));;
    }

    // Trova il triangolo con l'area maggiore
    int largestIndex = 0;
    double largestArea = triangles[0].area;
    for (int i = 1; i < 3; ++i) {
        if (triangles[i].area > largestArea) {
            largestArea = triangles[i].area;
            largestIndex = i;
        }
    }

    cout << "Il triangolo con area maggiore e' il triangolo " << largestIndex + 1 << endl;
}