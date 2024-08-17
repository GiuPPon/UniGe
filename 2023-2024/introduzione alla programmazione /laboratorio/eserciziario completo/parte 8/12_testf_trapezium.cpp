/* . Scrivere una funzione con due parametri di tipo intero che stampa il trapezio rettangolo fatto di
'x' con le basi lunghe quanto gli argomenti, e l’altezza pari alla differenza fra le basi più uno. Ad 
esempio su 5 e 9 stamperà:
xxxxx
xxxxxx
xxxxxxx
xxxxxxxx
xxxxxxxxx
(che è alto 5 = 9 − 5 + 1). Si noti che data la scelta dell’altezza a ogni riga bisogna stampare un 
carattere in più rispetto alla precedente. [ File testf_trapezium.cpp ]
[SUGGERIMENTO: usare la funzione replicate.] */

#include <iostream>
#include <string>
using namespace std;

void replicate(int length, char c){
    for (int i = 0; i < length; ++i) {
        cout << c;
    }
}

void trapezium(int b, int B) {
    int h = B - b + 1;

    if (b <= 0 && B <= 0) {
        string err = "ERRORE: basi negative";
        throw err;
    }
    if (b <= 0) {
        string err = "ERRORE: base minore negativa";
        throw err;
    }
    if (B <= 0) {
        string err = "ERRORE: base maggiore negativa";
        throw err;
    }
    if (b >= B) {
        string err = "ERRORE: base maggiore piu' piccola della minore";
        throw err;
    }

    for (int i = 0; i <= h; ++i) {
        replicate(b + i, 'x');
        cout << endl;
    }
}

int main () {
    try {
        int b1, B2;
        cout << "inserire prima base: ";
        cin >> b1;
        cout << "inserire seconda base: ";
        cin >> B2;
        trapezium(b1, B2);
    } catch (string& err) {
        cout << err << endl;
    }
}