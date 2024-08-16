/* Scrivere una funzione getLength con un argomento num di tipo intero che restituisce il numero di 
cifre (in base 10). Ad esempio su 27458 restituisce 5. Dal main richiamare la funzione su un insieme 
di valori utili a verificarne il funzionamento (memorizzati in un array).
[ File testf_ndigits.cpp ] */

#include <iostream>
using namespace std;

int getLength (int num) {
    int count = 0;
    while (num != 0) {
        num = num / 10;
        count++;
    }
    return count;
}

int main () {
    int N = 5;
    int a[N] = {145, 2, 34565, 111, 45};

    
    for (int i = 0; i < N; ++i) {
        int length = getLength(a[i]);
        cout << "Il numero di cifre in " << a[i] << " e' " << length << endl;
    }
}