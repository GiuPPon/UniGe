/*Scrivere un programma che legge da input un numero intero Temp e stampa:
• “Freddo incredibile” se Temp è compreso fra −20 e 0
• “Freddo” se Temp è compreso fra 1 e 15
• “Normale” se Temp è compreso fra 16 e 23
• “Caldo” se Temp è compreso fra 24 e 30
• “Caldo da morire” se Temp è compreso fra 31 e 40
• “Non ci credo, il termometro deve essere rotto” se Temp è superiore a 40 o inferiore a −20
[ File temperature.cpp ]*/

#include <iostream>
using namespace std;

int main () {
    int temp;
    cout << "Inserire temperatura: ";
    cin >> temp;

    if (-20 <= temp && temp <= 0) {
        cout << "Freddo incredibile" << endl;
    } else if (1 <= temp && temp <= 15) {
        cout << "Freddo" << endl;
    } else if (16 <= temp && temp <= 23) {
        cout << "Normale" << endl;
    } else if (24 <= temp && temp <= 30) {
        cout << "Caldo" << endl;
    } else if (31 <= temp && temp <= 40) {
        cout << "Caldo da morire" << endl;
    } else {
        cout << "Non ci credo, il termometro deve essere rotto" << endl;
    }
}