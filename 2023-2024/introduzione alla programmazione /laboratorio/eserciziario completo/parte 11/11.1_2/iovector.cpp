/* Scrivere due funzioni void readVector(vector<int> &v) e void printVector(const vector<int> &v) che 
permettano rispettivamente di (1) inserire N valori letti da tastiera in un vector v (N positivo) e 
(2) stamparli: */

#include <iostream>
#include "iovector.h"
using namespace std;

void readVector(vector<int> &v) {
    // Stampare "Inserisci la dimensione della sequenza: "
    cout << "Inserisci la dimensione della sequenza";
    // Dichiarare una variabile intera N
    int N;
    // Leggere N
    cin >> N;
    // iterare finché N non è positivo
    // - Stampare "La dimensione deve essere positiva - riprova: "
    // - Leggere N
    while (N <= 0) {
        cout << "La dimensione deve essere positiva - riprova: ";
        cin >> N;
    }
    // iterare N volte
    // - Leggere un valore intero
    // - Memorizzare il valore letto in v
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
}

void printVector(const vector<int> &v) {
    // iterare v.size() volte
    // - stampare l'elemento corrente di v
    for (unsigned int i = 0; i < v.size(); ++i) {
        cout << v.at(i);
    }
}