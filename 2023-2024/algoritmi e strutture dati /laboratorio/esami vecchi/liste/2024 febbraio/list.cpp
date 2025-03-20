#include "list.h"
#include <iostream>
using namespace std;

void insert_tail(List& l, const int v) {
    cell *aux = new cell;
    aux -> value = v;
    aux -> next = nullptr;

    if (l == nullptr) {
        l = aux;
        return;
    } 

    cell *cur = l;
    while (cur != nullptr) {
        cur = cur -> next;
    }
    cur -> next = aux;
}

bool remove(List& l, unsigned int pos) {
    if (l == nullptr) {
        return false;
    }
    if (pos == 0) {
        cell *aux = l;
        delete aux;
        l = l -> next;
        return true;
    } 
    cell *cur = l;
    cell *prev = nullptr;
    int count = 0;
    while (cur != nullptr && count < pos) {
        prev = cur;
        cur = cur -> next;
        ++count;
    } 
    if (count == pos) {
        prev -> next = cur -> next;
        delete cur;
        return true;
    }
    return false;
}

unsigned int count_between(const List& l, const int a, const int b) {
    cell *cur = l;
    unsigned int count = 0;
    while (cur != nullptr) {
        if (cur -> value >= a && cur -> value < b) {
            ++count;
        }
        cur = cur -> next;
    }
    return count;
}