// [SUGGERIMENTO: volendo si può usare la funzione replicate2_line]

#include <iostream> 
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

void rombo(int n) {
    // prima parte del triangolo (?)
    for (int i = 0; i <= n; ++i) {
        replicate2_line(n - i, ' ', 2 * i - 1, '*');
    }

    // seconda parte del triangolo
    for (int i = n - 1; i >= 0; --i) {
        replicate2_line(n - i, ' ', 2 * i - 1, '*');
    }
}

int main () {
    int num;
    cout << "inserire un numero intero positivo: ";
    cin >> num;
    rombo(num);
}