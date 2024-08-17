/* Scrivere una funzione vector<int> cat(const vector<int> &v1, const vector<int> &v2) che riceve due
argomenti v1 e v2, di tipo vector<int>. La funzione crea un terzo vector<int> v12 contenente il 
contenuto di v1 seguito dal contenuto di v2. Valore restituito: v12.
Scrivere un programma di test che legge alcuni interi usando (2 volte) la funzione readVectorAlt 
implementata in precedenza (presente in iovector.h), popolando quindi i vector<int> first e second.
Quindi chiama cat per concatenare i due vettori e memorizza il risultato in vector<int> total, 
stampando infine i tre elenchi contenuti in first, second e total utilizzando la funzione printVector 
implementata in precedenza (presente in iovector.h). [ File cat.cpp, cat.h, testf_cat.cpp ] */

#include <iostream>
#include <vector>
#include "cat.h"
using namespace std;

vector<int> cat(const vector<int> &v1, const vector<int> &v2) {
    vector <int> v12;
    v12.reserve(v1.size() + v2.size());

    v12.insert(v12.end(), v1.begin(), v1.end());
    v12.insert(v12.end(), v2.begin(), v2.end());

    return v12;
}

void readVectorAlt(vector<int> &v) {
    cout << "Inserire numeri interi ('y' per terminare) : " << endl;
    string input;
    while (true) {
        cin >> input;
        if (input == "y") {
            break;
        }
        try {
            int num = stoi(input);
            v.push_back(num);
        }catch (const invalid_argument& e) {
            cout << "Input non valido. Inserire solo numeri interi o 'y' per terminare" << endl;
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
    cout << endl;
}