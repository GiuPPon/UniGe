#include <iostream>
#include "orderedStringArray_funct.h"
using namespace std;

int main() {
    const int N = 5;
    string t1[N] = {"apple", "banana", "grape", "orange", "pear"}; 
    string t2[N] = {"apple", "banana", "orange", "grape", "pear"}; 

    if (orderedStringArray(t1, N)) {
        cout << "Gli elementi di t1 sono ordinati alfabeticamente." << endl;
    } else {
        cout << "Gli elementi di t1 non sono ordinati alfabeticamente." << endl;
    }

    if (orderedStringArray(t2, N)) {
        cout << "Gli elementi di t2 sono ordinati alfabeticamente." << endl;
    } else {
        cout << "Gli elementi di t2 non sono ordinati alfabeticamente." << endl;
    }
}