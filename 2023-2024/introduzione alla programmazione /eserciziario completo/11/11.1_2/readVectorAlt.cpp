#include <iostream>
#include "iovector.h"
using namespace std;

void readVectorAlt(vector<int> &v) {
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
    }
}