#include <iostream>
#include "hist.h"
#include "ll.h"
using namespace std;

void add ( Hist & h , int v ) {
    bool found = false;
    for (unsigned int i = 0; i < h.size(); ++i) {
        if (h[i].value == v) {
            ++h[i].num;
            found = true;
        }
    }
    if (!found) {
        Bin newBin;
        newBin.num = 1;
        newBin.value = v;
        h.push_back(newBin);
    }
}

void sort ( Hist & h ) {
    for (unsigned int i = 0; i < h.size() - 1; ++i) {
        for (unsigned int j = 0; j < h.size() - i - 1; ++j) {
            if (h[j].value > h[j + 1].value) {
                int temp = h[j].value;
                h[j].value = h[j + 1].value;
                h[j + 1].value = temp;
            }
        }
    }
}

int count ( const Hist & h , int v ) {
    for (unsigned int i = 0; i < h.size(); ++i) {
        if (h[i].value == v) {
            return h[i].num;
        }
    }
    return 0;
}

void addhead ( ll & s , char & c ) {
    // dichiarare una variabile tmp di tipo puntatore a elem
    // allocare elem
    elem *temp = new elem;
    // assegnare il valore di s all 'elemento next di temp
    temp -> next = s;
    // assegnare il valore di c all 'elemento c di temp
    temp -> c = c;
    // assegnare il valore di temp a s
    s = temp;
} 

bool removehead(ll &s, char & c) {
    if (s == nullptr) {
        return false;
    } else {
        elem *cur = s;
        cur -> c = c;
        s = s -> next;
        delete cur;
        return true;
    }
}

int size(ll s) {
    int count = 0;
    elem *cur = s;
    while (cur != nullptr) {
        cur = cur -> next;
        ++count;
    }
    return count;
}
 