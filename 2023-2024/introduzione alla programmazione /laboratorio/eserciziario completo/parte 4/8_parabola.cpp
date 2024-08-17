/* Parabola: scrivere un programma che dati un array arr di float, la sua lunghezza N, e tre valori 
float a, b, c memorizza in ogni elemento x-esimo dell’array il valore ax2+bx+c. Poi stampa l’array. 
[ File parabola.cpp ]
Esempio di Output atteso
Fornire il valore di a = 2.34
Fornire il valore di b = 5.45
Fornire il valore di c = -8.76
Valori nell'intervallo [0,9] della parabola 2.34x^2 + 5.45x + -8.76
Valore di arr[0] = -8.76
Valore di arr[1] = -0.97
Valore di arr[2] = 11.5
Valore di arr[3] = 28.65
Valore di arr[4] = 50.48
Valore di arr[5] = 76.99
Valore di arr[6] = 108.18
Valore di arr[7] = 144.05
Valore di arr[8] = 184.6
Valore di arr[9] = 229.83 */

#include <iostream>
using namespace std;

int main () {
    // Dichiarare una costante N con valore 10
    const int N = 10;
    // Dichiarare un array arr di N float
    float arr[N];
    // leggere da input un valore di a per il calcolo di ax^2+bx+c
    float a;
    cout << "Fornire il valore di a = ";
    cin >> a;
    // leggere da input un valore di b per il calcolo di ax^2+bx+c
    float b;
    cout << "Fornire il valore di b = ";
    cin >> b;
    // leggere da input un valore di c per il calcolo di ax^2+bx+c
    float c;
    cout << "Fornire il valore di c = ";
    cin >> c;
    // stampare "Valori nell'intervallo [0,9] della parabola " seguito dall'equazione della parabola
    cout << "Valori nell'intervallo [0,9] della parabola " << a << "x^2 + " << b << "x + " << c << endl;
    // Iterare sulla variabile intera x a partire da 0 e fino a N escluso:
    // - Assegnare all'x-esimo elemento dell'array il valore ax^2+bx+c
    // Stampare l'array in ordine crescente da arr[0] a arr[N-1] come visto sopra
    for (int x = 0; x < N; ++x) {
        arr[x] = a * x * x + b * x + c;
        cout << "Valore di arr[" << x << "] = " << arr[x] << endl;
    }  
}