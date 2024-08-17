#include <iostream>
#include "maxArray_funct.h"
using namespace std;

int main() {
    const int N = 5;
    int t[N] = {5, 3, 9, 2, 7};

    try {
        cout << "Massimo elemento dell'array: " << maxArray(t, N) << endl;
    } catch (string& err) {
        cout << err << endl;
    }
}