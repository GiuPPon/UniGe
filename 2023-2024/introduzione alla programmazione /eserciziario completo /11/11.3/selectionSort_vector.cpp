/* Scrivere una funzione void selectionSort_vector(vector<int> &v, bool ascending) che effettui 
l’ordinamento di v secondo l’algoritmo SelectionSort. Se ascending == true allora l’ordinamento sarà 
crescente altrimenti decrescente. */

#include <iostream>
#include <vector>
#include "selectionSort_vector.h"
using namespace std;

void selectionSort_vector(vector<int> &v, bool ascending) {
    // dichiarare una variabile int index
    unsigned int index;
    /* iterare sul vector dalla prima all'ultima posizione
    - memorizzare in index la posizione corrente (sia i)
    - *//* iterare sul vector dalla posizione successiva alla corrente (i+1) fino all'ultimo elemento
    -- se il valore alla pos corrente (j) e' (< se ascending==true, > altrimenti) del valore alla pos index
    --- memorizzare j in index
    *//*
    - scambiare il valore alla posizione i con quello alla pos index
    */   
    for (unsigned int i = 0; i < v.size() - 1; ++i) {
        index = i;
        for (unsigned int j = i + 1; j < v.size(); ++j) {
            if ((v.at(j) < v.at(index) && ascending) || (v.at(j) > v.at(index) && !ascending)) {
                index = j;
            }
        }
        if (index != i) {
            unsigned int aux = v.at(i);
            v.at(i) = v.at(index);
            v.at(index) = aux;
        }
    }
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