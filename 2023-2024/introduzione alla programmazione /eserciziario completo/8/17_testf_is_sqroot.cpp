/* Scrivere una funzione con due argomenti reali x e sqrt_x che restituisce un valore booleano, true 
se sqrt_x è la radice quadrata di x, ovvero se il quadrato di sqrt_x coincide con x.
Per testare la funzione usate come dati 25.3268614564 la cui radice quadrata è 5.03258 (se preferite 
altri valori, vi conviene partire da un numero con cifre decimali e farne il quadrato, in modo da 
evitare errori di approssimazione dovuti ai troncamenti). [ File testf_is_sqroot.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

bool is_square_root(double x, double sqrt_x) {
    double squared_sqrt_x = sqrt_x * sqrt_x;

    return abs(squared_sqrt_x - x) < 1e-9;
}

int main() {
    double x = 25.3268614564;
    double sqrt_x = 5.03258;

    if (is_square_root(x, sqrt_x)) {
        cout << sqrt_x << " e' la radice quadrata di " << x << endl;
    } else {
        cout << sqrt_x << " NON e' la radice quadrata di " << x << endl;
    }
}
