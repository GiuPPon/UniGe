#include <iostream>
#include "sortArrayInv_funct.h"
using namespace std;

int main() {
    const int N = 5; 
    int t[N] = {5, 3, 7, 1, 2};

    cout << "Array prima dell'ordinamento:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << t[i] << " ";
    }
    cout << endl;

    sortArrayInv(t, N);

    cout << "Array dopo l'ordinamento:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << t[i] << " ";
    }
    cout << endl;
}
