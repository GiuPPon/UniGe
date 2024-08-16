/* Scrivere un programma di test che legge alcuni interi usando (2 volte) la funzione readVectorAlt 
implementata in precedenza (presente in iovector.h), popolando quindi i vector<int> first e second.
Quindi chiama cat per concatenare i due vettori e memorizza il risultato in vector<int> total, 
stampando infine i tre elenchi contenuti in first, second e total utilizzando la funzione printVector 
implementata in precedenza (presente in iovector.h). */

#include "cat.h"
#include <iostream>
using namespace std;

int main () {
    vector <int> first;
    vector <int> second;
    readVectorAlt(first);
    readVectorAlt(second);

    vector <int> total = cat(first, second);
    cout << "Primo vector : ";
    printVector(first);
    cout << "Secondo vector : ";
    printVector(second);
    cout << "Risultato : ";
    printVector(total);
}