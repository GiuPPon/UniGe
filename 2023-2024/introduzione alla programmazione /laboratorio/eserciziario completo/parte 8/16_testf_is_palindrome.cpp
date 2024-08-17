/* Scrivere una funzione con un argomento intero n che restituisce un booleano, true se n è palindromo, 
ovvero se le sue cifre (in base 10) lette da destra a sinistra corrispondono alle cifre lette da 
sinistra a destra (altrimenti restituisce false, ma questo è sottinteso visto che per una espressione 
di tipo bool sono possibili due soli valori). [ File testf_is_palindrome.cpp ]
[SUGGERIMENTO: usare la funzione reverse.] */

#include <iostream>
using namespace std;

int reverse(int k){
    int sign = 1;
    if (k < 0) {
        sign = -1;
        k = -k;
    }
    int inv = 0;    
    while (k > 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10;
        inv = inv + mod;
    }
    return (inv * sign);
}

bool is_palindrome(int n) {
    int rev = reverse(n);
    return (n == rev);
}

int main () {
    cout << "Inserire numero: ";
    int num;
    cin >> num;
    if (is_palindrome(num)) {
        cout << "Il numero e' palindromo" << endl;
    } else {
        cout << "Il numero NON e' palindromo" << endl;
    }
}