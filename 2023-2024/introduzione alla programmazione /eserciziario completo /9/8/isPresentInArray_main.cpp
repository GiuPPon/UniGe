#include <iostream>
#include "isPresentInArray_funct.h"
using namespace std;

int main() {
    const int N = 5;
    int t[N] = {1, 2, 3, 4, 5};
    int x;
    cout << "Inserire elemento da cercare: ";
    cin >> x;

    if (isPresentInArray(t, N, x)) {
        cout << x << " e' presente nell'array." << endl;
    } else {
        cout << x << " NON e' presente nell'array." << endl;
    }
}
