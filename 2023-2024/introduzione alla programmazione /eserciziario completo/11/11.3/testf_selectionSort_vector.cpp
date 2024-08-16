#include <iostream>
#include <vector>
#include "selectionSort_vector.h"

int main () {
    // dichiarare un vector v di interi
    vector<int> v;
    // chiamare la funzione readVector su v
    readVector(v);
    // chiamare la funzione printVector su v
    printVector(v);
    cout << endl;
    // chiamare la funzione selectionSort_vector su v e true
    selectionSort_vector(v, true);
    // chiamare la funzione printVector su v (test: deve essere stampato ordinato crescente)
    printVector(v);
    cout << endl;
    // chiamare la funzione selectionSort_vector su v e false
    selectionSort_vector(v, false);
    // chiamare la funzione printVector su v (test: deve essere stampato ordinato decrescente)
    printVector(v);
    cout << endl;
}