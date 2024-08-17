/* Scrivere una funzione di nome swapDouble che prende due argomenti a e b di tipo double, e quando 
viene chiamata ne scambia i valori, e restituisce void.
Passare i parametri per riferimento (quindi con swapDouble(double& x, double& y)). Provare a passare 
i parametri per valore, che cosa succede? [ File testf_swapDouble.cpp ] */

#include <iostream>
using namespace std;

void swapDouble (double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int main (){
// dichiarare a e b di tipo double
double a, b;
// stampare a e b
cout << "inserire due numeri: " << endl;
cin >> a;
cin >> b;
cout << a << " " << b << endl;
// chiamare swapDouble(...) passando come parametri a e b
swapDouble(a, b);
// stampare a e b (per osservare risultato)
cout << a << " " << b << endl;
}