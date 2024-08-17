#include <iostream>
#include "selectVar_funct.h"
using namespace std;

int main () {
    // dichiarare tre variabili di tipo char ch1, ch2, ch3 inizializzate con lettere fra loro diverse
    char ch1 = 'a';
    char ch2 = 'b';
    char ch3 = 'c';
    // definire un puntatore di tipo char selected inizializzato con la chiamata di selectVar su ch1, ch2 e ch3
    char *selected = selectVar(ch1, ch2, ch3);
    // confrontare selected con l'indirizzo di ch1 e se sono uguali
    // - stampare il messaggio "hai scelto ch1 che ha valore = " ...
    if (selected == &ch1) {
        cout << "hai scelto ch1 che ha valore = " << ch1 << endl;
    }
    // confrontare selected con l'indirizzo di ch2 e se sono uguali
    // - stampare il messaggio "hai scelto ch2 che ha valore = " ...
     else if (selected == &ch2) {
        cout << "hai scelto ch2 che ha valore = " << ch2 << endl;
    }
    // confrontare selected con l'indirizzo di ch3 e se sono uguali
    // - stampare il messaggio "hai scelto ch3 che ha valore = " ...
    else if (selected == &ch3) {
        cout << "hai scelto ch3 che ha valore = " << ch3 << endl;
    }
    // altrimenti
    // - stampare "non hai scelto niente"
    else {
        cout << "non hai scelto niente" << endl;
    }
}