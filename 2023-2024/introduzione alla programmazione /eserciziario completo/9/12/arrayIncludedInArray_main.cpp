#include <iostream>
#include "arrayIncludedInArray_funct.h"
using namespace std;

int main() {
    const int N1 = 5;
    const int N2 = 8;
    int t1[N1] = {1, 2, 3, 4, 5};
    int t2[N2] = {4, 2, 5, 1, 3, 6, 7, 8};

    if (arrayIncludedInArray(t1, N1, t2, N2)) {
        cout << "Tutti gli elementi di t1 sono presenti in t2." << endl;
    } else {
        cout << "Non tutti gli elementi di t1 sono presenti in t2." << endl;
    }
}