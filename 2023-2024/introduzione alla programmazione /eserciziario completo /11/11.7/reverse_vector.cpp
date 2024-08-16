/* Scrivere una funzione vector<int> reverse(const vector<int> &v) che prende in ingresso un 
std::vector<int> v e restituisce un nuovo vector<int> contenente il contenuto di v in ordine inverso. */

#include "reverse_vector.h"
using namespace std;

vector<int> reverse(const vector<int> &v) {
    vector<int> r(v.rbegin(), v.rend()); 
    return r;
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