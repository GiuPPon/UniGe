/* Scrivere una funzione void insert(vector<int> &v, unsigned long int i, int val) che riceve tre 
argomenti: v di tipo vector, un intero i, un intero val. La funzione aggiunge a v in posizione i il 
valore di val. La lunghezza di v deve essere incrementata di 1 e tutto l’eventuale contenuto di v, 
dalla posizione i (compresa) fino alla fine, deve essere spostato in avanti di una posizione.
NOTA: siccome è previsto che il vettore si incrementi di dimensione, le posizioni di inserimento 
valide sono tutte quelle esistenti (da 0 a v.size()-1) e anche una oltre l’ultima (la posizione 
v.size()), quindi i∈ [0,v.size()]. Se i non è compreso in questo intervallo sollevare una eccezione 
int.
[SUGGERIMENTO: Inserire in coda a v il suo ultimo elemento (se esiste), spostare in avanti di una 
posizione gli elementi di v a partire dalla posizione i in avanti (copiandoli a partire dal fondo in 
modo da non sovrascriverli) e assegnare il valore da inserire nella posizione i.]
Valore restituito: v dopo la modifica. */

#include "insert.h"
#include <iostream>
using namespace std;

void insert(vector<int> &v, unsigned long int i, int val) {
    if (i > v.size()) {
        throw 1;
    }

    if (v.empty()) {
        v.push_back(val);
    }

    v.push_back(v.back());

    for (unsigned long int k = v.size() - 1; k > i; --k) {
        v.at(k) = v.at(k - 1);
    }

    v.at(i) = val;
}

void printVector(const vector<int> &v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        cout << v.at(i);
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}