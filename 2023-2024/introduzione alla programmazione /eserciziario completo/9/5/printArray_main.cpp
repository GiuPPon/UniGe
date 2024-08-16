#include <iostream>
#include "printArray_funct.h"
using namespace std;

int main () {
    // array con N elementi (es N=5)
    int N = 5;
    int a[N] = { 1, 6, 14, 7, 0};
    // array con 1 elemento
    int v[] = {1};
    // array con zero elementi
    int r[] = {};
    // testare il funzionamento di printArray con almeno tre array
    printArray(a, N);
    cout << endl;
    printArray(v, 1);
    cout << endl;
    printArray(r, 0);
    cout << endl;
    // replicare gli stessi passi per printArrayWithIndex e verificare che i risultati sono equivalenti
    printArrayWithIndex(a, N);
    cout << endl;
    printArrayWithIndex(v, 1);
    cout << endl;
    printArrayWithIndex(r, 0);
    cout << endl;
}