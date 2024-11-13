#include <iostream>
#include "array.h"
#include "list.h"
using namespace std;

string stampa ( int arrayInteri [] , int dimensione ) {
    string out;
    for (int i = 0; i < dimensione; ++i) {
        out = out + to_string(arrayInteri[i]);
        if (i < dimensione - 1) {
            out = out + ",";
        }
    }
    return out;
}

string stampaKelementi ( int arrayInteri [] , int dimensione , int k) {
    if (k >= dimensione) {
        return stampa(arrayInteri, dimensione);
    } else {
        return stampa(arrayInteri, k);
    }
}

void sort (int arrayInteri [] , int dimensione ) {
    for (int i = 0; i < dimensione - 1; ++i) {
        for (int j = 0; j < dimensione - i - 1; ++j) {
            if (arrayInteri[j] > arrayInteri[j + 1]) {
                int temp = arrayInteri[j];
                arrayInteri[j] = arrayInteri[j + 1];
                arrayInteri[j + 1] = temp;
            }
        }
    }
}

void inserimentoInTesta ( List &list , City newCity ) {
    Cell *aux = new Cell;
    aux -> city = newCity;
    aux -> next = nullptr;
    aux -> prev = nullptr;

    if (list == nullptr) {
        list = aux;
        return;
    } 
    list -> prev = aux;
    aux -> next = list;
    list = aux;
}

string stampaAndata ( List list ) {
    string out;
    Cell *cur = list;
    while (cur != nullptr) {
        out = out + cur -> city;
        if (cur -> next != nullptr) {
            out = out + ",";
        }
        cur = cur -> next;
    }
    return out;
}

string stampaRitorno ( List list ) {
    string out;
    Cell *cur = list;
    Cell *last = nullptr;
    while (cur != nullptr) {
        last = cur;
        cur = cur -> next;
    }
    cur = last;
    while (cur != nullptr)  {
        out = out + cur -> city;
        if (cur -> prev != nullptr) {
            out = out + ",";
        }
        cur = cur -> prev;
    }
    return out;
}

string stampaAdiacenti ( List list , City newCity ) {
    if (list == nullptr) {
        return "";
    }
    
    string X;
    string Y;
    string Z;

    Cell *cur = list;
    while (cur != nullptr && cur -> city != newCity) {
        cur = cur -> next;
    }

    if (cur == nullptr) {
        Y = "-";
    } else {
        Y = cur -> city;
    }

    if (cur -> prev == nullptr) {
        X = "-";
    } else {
        X = cur -> prev -> city;
    }

    if (cur -> next == nullptr) {
        Z = "-";
    } else {
        Z = cur -> next -> city;
    }

    return X + "," + Y + "," + Z;
}