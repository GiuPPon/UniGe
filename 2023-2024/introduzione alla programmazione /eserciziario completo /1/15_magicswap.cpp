/*Scrivere un programma che scambia fra loro i valori di due variabili int senza usare variabili di 
appoggio. Il programma deve essere scritto in un file chiamato magicswap.cpp.
[SUGGERIMENTO: l’or esclusivo, o XOR (in C++ l’operatore ^), gode di varie proprietà, tra cui la 
proprietà di simmetria – cioè A^B == B^A – e la proprietà associativa – cioè (A^B)^C == A^(B^C). 
Inoltre, A^A ==0 e A^0==A per qualsiasi A, B e C.]*/

#include <iostream>
using namespace std;

int main () {
    int a = 0;
    int b = 0;
    cout << "Inserire a" << endl;
    cin >> a;
    cout << "Inserire b" << endl;
    cin >> b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    
    cout << "magicswap: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}