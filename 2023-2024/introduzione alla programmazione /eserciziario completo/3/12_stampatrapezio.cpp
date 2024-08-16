/* Scrivere un programma che legge due numeri interi strettamente positivi (le 2 basi di un trapezio 
rettangolo: b e B con b<=B) e stampa il trapezio rettangolo fatto di 'x' con le basi lunghe quanto i
numeri letti, e l’altezza pari alla differenza fra le basi più uno. [ File stampatrapezio.cpp ]
Ad esempio avendo in input 5 e 9 stamperà:
xxxxx
xxxxxx
xxxxxxx
xxxxxxxx
xxxxxxxxx
(che è alto 5 = 9 − 5 + 1). Si noti che data la scelta dell’altezza a ogni riga bisogna stampare un
carattere in più. */

#include <iostream>
using namespace std;

int main () {
    cout << "Inserisci la base minore: " << endl;
    int b;
    cin >> b;

    cout << "Inserisci la base maggiore: " << endl;
    int B;
    cin >> B;

    if (b >= B) {
        cout << "le basi non sono compatibili" << endl;
        return 0;
    }

    int altezza = B - b + 1;

    for (int i = 0; i < altezza; ++i) {
        for (int j = 0; j < b + i; ++j) {
            cout << "x";
        }
    cout << endl;
    }
}
