#include "reverseArrayInStruct_funct.h"
#include <iostream>
using namespace std;

void reverseArrayInStruct(const array_str& source, array_str& dest) {
    if (&source == &dest) {
        string err = "Errore: l'indirizzo di source e' uguale a quello di dest";
        throw err;
    }
    if (source.size != dest.size) {
        string err = "Errore: stessa dimensione";
        throw err;
    }
    for (int i = 0; i < source.size; ++i) {
        dest.array[i] = source.array[source.size - 1 - i];
    }
}

void Print(const array_str& arr) {
    for (int i = 0; i < arr.size; ++i) {
        cout << arr.array[i];
    }
}