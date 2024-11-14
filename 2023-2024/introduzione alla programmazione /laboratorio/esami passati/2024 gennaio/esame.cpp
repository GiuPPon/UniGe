#include <iostream>
#include "array.h"
#include "list.h"

bool arrayContainsFibonacciSeries ( const int* arr , unsigned int size ) {
    if (size == 0 || arr == nullptr) {
        return true;
    }

    if (arr[0] != 0 && arr[1] != 1) {
        return false;
    }

    if (arr[0] != 0 && arr[1] == 1) {
        return false;
    }

    for (unsigned int i = 2; i < size - 1; ++i) {
        if (arr[i] + arr[i - 1] != arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void reverseArray ( int* arr , unsigned int size ) {
    int reverse[size];

    for (unsigned int i = 0; i < size; ++i) {
        reverse[i] = arr[size - i - 1];
    }

    for (unsigned int i = 0; i < size; ++i) {
        arr[i] = reverse[i];
    }
}

int findEquilibriumIndex ( const int* arr , unsigned int size ) {
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int sinistra = 0;
        unsigned int destra = 0;

        for (unsigned int j = 0; j < i; ++j) {
            sinistra = sinistra + arr[j];
        }

        for (unsigned int k = i + 1; k < size; ++k) {
            destra = destra + arr[k];
        }

        if (destra == sinistra) {
            return i;
        }
    }
    return -1;
}

unsigned int computeListSize ( const List &l) {
    if (l == nullptr) {
        return 0;
    }
    unsigned int count = 0;
    Cell *cur = l;
    while (cur != nullptr) {
        cur = cur -> next;
        ++count;
    }
    return count;
}

bool insertElemInListAtIndex ( List &l, Elem s, unsigned int index ) {
    Cell *aux = new Cell;
    aux -> elem = s;
    aux -> next = nullptr;

    Cell *cur = l;
    Cell *prev = nullptr;

    if (index < 0 || computeListSize(l) < index) {
        return false;
    }

    if (index == 0 || l == nullptr) {
        aux -> next = l;
        l = aux;
        return true;
    }

    unsigned int count = 0;
    if (cur != nullptr && count < index) {
        prev = cur; 
        cur = cur -> next;
        ++count;    
    }

    prev -> next = aux;
    aux -> next = cur;
    return true;
}

void deleteLastInstanceOfElemInList ( List &l, Elem s) {
    if (l == nullptr) {
        return;
    }

    Cell *cur = l;
    Cell *prev = nullptr;

    Cell *last = nullptr;
    Cell * lastprev = nullptr;

    while (cur != nullptr) {
        if (cur -> elem == s) {
            last = cur;
            lastprev = prev;
        } 
        prev = cur;
        cur = cur -> next;
    }

    if (last == nullptr) {
        return;
    }

    if (last == l) {    // se last è il primo elemento della lista
        l = l -> next;
    } else {
        lastprev -> next = last -> next;
    }
    delete last;
}
