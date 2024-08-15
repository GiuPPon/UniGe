/* Scrivere un programma che prende in input il numero di ore (compreso fra 0 e 23) e di minuti
(compreso fra 0 e 59) e stampa in output il numero di minuti totali. Il programma deve essere 
scritto in un file chiamato time2min.cpp. */

#include <iostream>
using namespace std;

int main () {
    int ore = 0;
    int min = 0;

    cout << "Inserire numero di ore (compreso tra 0 e 23)" << endl;
    cin >> ore;
    cout << "Inserire numero di minuti" << endl;
    cin >> min;

    int mintot = (ore * 60) + min;
    cout << "I minuti totali sono: " << mintot << endl;
}
