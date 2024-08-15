#include <iostream>
#include "shiftRightArray_funct.h"
using namespace std;

int main() {
    const int N = 5; 
    int t[N] = {1, 2, 3, 4, 5}; 

    cout << "Array prima dello shift:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << t[i] << " ";
    }
    cout << endl;

    shiftRightArray(t, N);

    cout << "Array dopo lo shift:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << t[i] << " ";
    }
    cout << endl;
}