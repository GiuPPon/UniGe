/* Scrivere una funzione int sequentialSearch_vector(const vector<int> &v, int item) che effettui la 
ricerca dell’elemento item all’interno di v
Scrivere un programma per testare la funzione int sequentialSearch_vector(const vector<int> &v, int item )
[ File sequentialSearch_vector.cpp, sequentialSearch_vector.h, testf_sequentialSearch_vector.cpp ] */

#include <iostream>
#include "sequentialSearch_vector.h"
using namespace std;

int sequentialSearch_vector(const vector<int> &v, int item) {
    // dichiarare una variabile int loc e inizializzarla a -1
    int loc = -1;
    /* iterare su v fino a che found diventa true o si è iterato su tutto il vector
    - se il valore alla pos corrente (i) e' uguale a item
    -- assegnare true a found e i a loc
    */
    for (unsigned int i = 0; i < v.size(); ++i) {
        if (v.at(i) == item) {
            loc = i;
            break;
        }
    } 
    // restituire loc
    return loc;
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