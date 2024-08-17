// si stampi il numero ottenuto leggendo il numero dato da destra verso sinistra. Ad esempio su -56 
// si stampi -65. [ File reversedigitsneg.cpp ] 

#include <iostream>
using namespace std;

int main() {
    int k;

    cout << "Inserire un numero intero: ";
    cin >> k;

    int sign = 1;
    if (k < 0) {
        sign = -1;
        k = -k;
    }

    cout << "Rovesciando " << (sign == -1 ? "-" : "") << k;

    int inv = 0;

    while (k != 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10;
        inv = inv + mod;
    }
    
    inv = inv * sign;

    cout << " si ottiene " << inv << endl;
}