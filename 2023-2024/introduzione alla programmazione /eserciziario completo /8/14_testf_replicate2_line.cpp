/* Scrivere una funzione replicate2_line con parametri f, f_c, s, s_c, dove f e s sono di tipo intero 
e f_c e s_c di tipo carattere. La funzione stampa su una riga a sé stante f volte f_c, seguito da s 
volte s_c. Ad esempio replicate2_line(3, 's', 7, 'q') stampa
sssqqqqqqq
Quando per un carattere viene inserito un numero <=0 quel carattere non viene stampato.
[ File testf_replicate2_line.cpp ] */

#include <iostream>
#include <string>
using namespace std;

void replicate2_line(int f, char f_c, int s, char s_c) {
    for (int i = 0; i < f; ++i) {
        if (f > 0) {
            cout << f_c;
        }
    }

    for (int i = 0; i < s; ++i) {
        if (s > 0) {
            cout << s_c;
        }
    }

    cout << endl;
}

int main() {
    char fc, sc;
    int f, s;
    cout << "inserire numero: ";
    cin >> f;
    cout << "inserire carattere da ripetere: ";
    cin >> fc;
    cout << "inserire numero: ";
    cin >> s;
    cout << "inserire carattere da ripetere: ";
    cin >> sc;

    replicate2_line(f, fc, s, sc);
}