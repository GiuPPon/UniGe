/* Definire un tipo struct Complex che rappresenta un numero complesso in due forme:
(a) come parte reale e parte immaginaria (forma cartesiana);
(b) come modulo e fase (forma esponenziale),
tutte variabili-membro di tipo double.
Scrivere un programma che legge due numeri complessi e ne calcola:
• Somma
• Differenza
• Prodotto
• Rapporto
Ogni operazione deve mantenere consistenti, allineate fra loro, le due rappresentazioni, ovvero le 
coppie (re, im) e (modulo, fase) di un dato numero complesso devono sempre rappresentare lo stesso 
numero. Stampare i risultati delle operazioni nelle due forme, cartesiana ed esponenziale.
[ File complexCalc.cpp ] */

#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    // forma cartesiana
    double reale;        
    double immaginaria;   
    // forma esponenziale
    double modulo;     
    double fase;
};

int main() {
    Complex c1, c2;

    cout << "Inserisci la parte reale del primo numero complesso: ";
    cin >> c1.reale;
    cout << "Inserisci la parte immaginaria del primo numero complesso: ";
    cin >> c1.immaginaria;

    c1.modulo = sqrt(c1.reale * c1.reale + c1.immaginaria * c1.immaginaria);
    c1.fase = atan2(c1.immaginaria, c1.reale);

    cout << "Inserisci la parte reale del secondo numero complesso: ";
    cin >> c2.reale;
    cout << "Inserisci la parte immaginaria del secondo numero complesso: ";
    cin >> c2.immaginaria;

    c2.modulo = sqrt(c2.reale * c2.reale + c2.immaginaria * c2.immaginaria);
    c2.fase = atan2(c2.immaginaria, c2.reale);

    Complex sum;
    sum.reale = c1.reale + c2.reale;
    sum.immaginaria = c1.immaginaria + c2.immaginaria;
    sum.modulo = sqrt(sum.reale * sum.reale + sum.immaginaria * sum.immaginaria);
    sum.fase = atan2(sum.immaginaria, sum.reale);

    Complex diff;
    diff.reale = c1.reale - c2.reale;
    diff.immaginaria = c1.immaginaria - c2.immaginaria;
    diff.modulo = sqrt(diff.reale * diff.reale + diff.immaginaria * diff.immaginaria);
    diff.fase = atan2(diff.immaginaria, diff.reale);

    Complex prod;
    prod.reale = c1.reale * c2.reale - c1.immaginaria * c2.immaginaria;
    prod.immaginaria = c1.reale * c2.immaginaria + c1.immaginaria * c2.reale;
    prod.modulo = sqrt(prod.reale * prod.reale + prod.immaginaria * prod.immaginaria);
    prod.fase = atan2(prod.immaginaria, prod.reale);

    Complex rapp;
    double denominatore = c2.reale * c2.reale + c2.immaginaria * c2.immaginaria;
    rapp.reale = (c1.reale * c2.reale + c1.immaginaria * c2.immaginaria) / denominatore;
    rapp.immaginaria = (c1.immaginaria * c2.reale - c1.reale * c2.immaginaria) / denominatore;
    rapp.modulo = sqrt(rapp.reale * rapp.reale + rapp.immaginaria * rapp.immaginaria);
    rapp.fase = atan2(rapp.immaginaria, rapp.reale);

    // Stampa i risultati
    cout << "Somma:" << endl;
    cout << "Forma cartesiana: " << sum.reale << " + " << sum.immaginaria << "i" << endl;
    cout << "Forma esponenziale: " << sum.modulo << " * e^(" << sum.fase << "i)" << endl;

    cout << "Differenza:" << endl;
    cout << "Forma cartesiana: " << diff.reale << " + " << diff.immaginaria << "i" << endl;
    cout << "Forma esponenziale: " << diff.modulo << " * e^(" << diff.fase << "i)" << endl;

    cout << "Prodotto:" << endl;
    cout << "Forma cartesiana: " << prod.reale << " + " << prod.immaginaria << "i" << endl;
    cout << "Forma esponenziale: " << prod.modulo << " * e^(" << prod.fase << "i)" << endl;

    cout << "Rapporto:" << endl;
    cout << "Forma cartesiana: " << rapp.reale << " + " << rapp.immaginaria << "i" << endl;
    cout << "Forma esponenziale: " << rapp.modulo << " * e^(" << rapp.fase << "i)" << endl;
}