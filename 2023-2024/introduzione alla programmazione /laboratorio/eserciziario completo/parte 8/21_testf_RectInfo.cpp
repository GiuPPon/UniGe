/* Scrivere una funzione computeRectInfo(...) con 4 argomenti di tipo double: l1, l2, area, e 
perimentro. I due ultimi parametri sono usati per fornire in output i valori di area e perimento del 
rettangolo di lunghezza l1 e altezza l2. Nel caso in cui l1 e/o l2 siano negativi sollevare 
un’eccezione di tipo string con il messaggio opportuno (3 messaggi possibili).
[SUGGERIMENTO: Ricordiamo che il passaggio per riferimento consente ad una funzione di "ritornare" più 
valori di output.] [ File testf_RectInfo.cpp ] */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void computeRectInfo(double l1, double l2, double &area, double &perimeter) {
    if (l1 < 0 || l2 < 0) {
        string err = "Errore: valori negativi";
        throw err;
    }

    area = l1 * l2;
    perimeter = 2 * (l1 + l2);
}

int main() {
    double l1, l2;
    cout << "Inserire numero: ";
    cin >> l1;
    cout << "Inserire numero: ";
    cin >> l2;
    double area, perimeter;

    try {
        computeRectInfo(l1, l2, area, perimeter);
        cout << "Area del rettangolo: " << area << endl;
        cout << "Perimetro del rettangolo: " << perimeter << endl;
    } catch (string& err) {
        cout << err << endl;
    }
}
