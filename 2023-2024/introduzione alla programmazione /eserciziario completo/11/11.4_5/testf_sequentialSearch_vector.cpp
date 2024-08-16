#include <iostream>
#include <vector>
#include "sequentialSearch_vector.h"

int main () {
    vector<int> v;
    
    readVector(v);
    printVector(v);
    cout << endl;

    int item = 5;
    int pos = sequentialSearch_vector(v, item);

    if (pos != -1) {
        cout << "L'elemento " << item << " e' presente nella posizione " << pos << " del vettore." << endl;
    } else {
        cout << "L'elemento " << item << " non è presente nel vettore." << endl;
    }
}