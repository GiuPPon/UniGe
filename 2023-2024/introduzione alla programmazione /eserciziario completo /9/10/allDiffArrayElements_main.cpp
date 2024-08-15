// File: allDiffArrayElements_main.cpp

#include <iostream>
#include "allDiffArrayElements_funct.h"
using namespace std;

int main() {
    const int N = 5; 
    int t1[N] = {1, 2, 3, 4, 5};
    int t2[N] = {1, 2, 3, 4, 4};

    if (allDiffArrayElements(t1, N)) {
        cout << "Tutti gli elementi di t1 sono distinti." << endl;
    } else {
        cout << "Ci sono elementi duplicati in t1." << endl;
    }

    if (allDiffArrayElements(t2, N)) {
        cout << "Tutti gli elementi di t2 sono distinti." << endl;
    } else {
        cout << "Ci sono elementi duplicati in t2." << endl;
    }
}
