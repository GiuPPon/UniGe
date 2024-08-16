#include <iostream>
#include "countDigitsInArray_funct.h"
using namespace std;

int main() {
    const int N = 6;
    char a[N] = {'f', '4', 'c', 'r', '5', 'R'};

    cout << "Numero di cifre presenti nell'array: " << countDigitsInArray(a, N) << endl;
}
