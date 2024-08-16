#include <iostream>
#include "iovector.h"
using namespace std;

int main () {
    // dichiarare un vector v di interi
    vector<int> v;
    // chiamare la funzione readVector su v
    readVector(v);
    // chiamare la funzione printVector su v
    printVector(v);
}