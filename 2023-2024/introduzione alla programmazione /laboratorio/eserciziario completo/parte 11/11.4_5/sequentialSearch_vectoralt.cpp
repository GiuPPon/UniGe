#include <iostream>
#include "sequentialSearch_vector.h"
using namespace std;

int sequentialSearch_vector(const vector<int> &v, int item) {
    /* iterare su v dalla prima all'ultima posizione
    - se il valore alla pos corrente (i) e' uguale a item
    -- restituire i
    */
    for (unsigned int i = 0; i < v.size(); ++i) {
        if (v.at(i) == item) {
            return i;
        }
    }
    // restituire -1
    return -1;
}

void printVector(const vector<int> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        cout << v.at(i);
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
}

void readVector(vector<int> &v) {
    cout << "Inserisci la dimensione della sequenza : ";
    int N;
    cin >> N;

    while (N <= 0) {
        cout << "La dimensione deve essere positiva - riprova: ";
        cin >> N;
    }
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
}