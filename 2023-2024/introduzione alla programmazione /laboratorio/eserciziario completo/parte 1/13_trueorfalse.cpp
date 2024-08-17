/* Scrivere un programma che, per ciascuna di queste frasi, stampa la frase seguita dal simbolo = e 
da un’espressione booleana che calcola il suo valore di verità. Il programma deve essere scritto in 
un file chiamato trueorfalse.cpp.
[SUGGERIMENTO: per stampare i booleani come true e false invece che come 1 e 0 si deve impostare a 
true il flag boolalpha di cout. Per fare questo si usa la stessa sintassi della stampa, ovvero si 
deve “stampare” un comando, come segue: std::cout << std::boolalpha ]
• tre è maggiore di uno
• quattro diviso due è minore di zero
• il carattere “zero" è uguale al valore zero
• dieci mezzi è compreso fra zero escluso e dieci incluso (ossia: dieci mezzi è maggiore di zero E 
  dieci mezzi è minore o uguale a dieci)
• non è vero che tre è maggiore di due e minore di uno
• tre minore di meno cinque implica sette maggiore di zero
[SUGGERIMENTO: A implica B è vera se B è vera, oppure se A è falsa] */

#include <iostream>
using namespace std;

int main () {
    cout << boolalpha;

    cout << "tre è maggiore di uno = " << (3 > 1) << endl;
    cout << "quattro diviso due è minore di zero = " << ( 4 / 2 < 0) << endl;
    cout << "il carattere 'zero' è uguale al valore zero = " << ('0' == 0) << endl;
    cout << "dieci mezzi è compreso fra zero escluso e dieci incluso = " << ((10 / 2 > 0) && (10 / 2 <= 10)) << endl;
    cout << "non è vero che tre è maggiore di due e minore di uno = " << !((3 > 2) && (3 < 1)) << endl;
    cout << "tre minore di meno cinque implica sette maggiore di zero = " << !((3 < -5) || (7 > 0)) << endl;
}