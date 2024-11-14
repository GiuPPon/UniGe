#include <iostream>
#include "funz.h"
#include "array.h"
#include "list.h"
using namespace std;

unsigned int numIterSequenzaSiracusa ( unsigned int vinit ) {
    unsigned int count = 0;
    while (vinit > 1) {
        if (vinit % 2 == 0) {
            vinit = vinit / 2;
        } else {
            vinit = 3 * vinit + 1;
        }
        ++count;
    }
    return count;
}

bool ascendingSequence ( const int* arr , unsigned int dim) {
    for (unsigned int i = 0; i < dim; ++i) {
        for (unsigned int k = i; k < dim - 1; ++k) {
            if (arr[k] > arr[k + 1]) {
                return false;
            }
        }
    }
    return true;
}

dyn_array indexOfInArray ( int v, const int* arr , unsigned int dim) {
    dyn_array ret;
    ret.D = 0;

    if (dim == 0) {
        return ret;
    }

    // trova quante volte c'è l'elemento
    unsigned int count = 0;
    for (unsigned int i = 0; i < dim; ++i) {
        if (arr[i] == v) {
            ++count;
        }
    }

    if (count == 0) {
        return ret;
    }

    ret.D = count;
    ret.A = new unsigned int [count];

    unsigned int index = 0;
    for (unsigned int k = 0; k < dim; ++k) {
        if (arr[k] == v) {
            ret.A[index] = k;
            ++index;
        }
    }

    return ret;
}

unsigned int computeListSize ( const List l) {
    if (l == nullptr) {
        return 0;
    }

    unsigned int count = 1;
    Cell *cur = l;
    while (cur -> next != l) {
        cur = cur -> next;
        ++count;
    }
    return count;
}

bool allDiffInCircList ( const List l) {
    if (l == nullptr) {
        return true;
    }

    Cell *cur = l;

    while (cur -> next != l) {
        Cell *temp = cur -> next;
        while (temp != l) {
            if (cur -> elem == temp -> elem) {
                return false;
            }
            temp = temp -> next;
        }
        cur = cur -> next;
    }
    return true;
}

void deleteAllCircList ( List &l, int v) {
    if (l == nullptr) {
        return;
    }

    Cell *cur = l;
    Cell *prev = nullptr;

    while (cur -> next != l) {
        if (cur -> elem == v) {
            Cell *temp = cur -> next;
            if (prev == nullptr) {
                if (cur -> next == l) {
                    delete cur;
                    l = nullptr;
                    return;
                } else {
                    Cell *last = l;
                    while (last -> next != l) {
                        last = last -> next;
                    }
                    last -> next = temp; // l'elemento prossimo all'ultimo elemento non è piu l ma l -> next
                    l = temp;
                    delete cur;
                    cur = temp;
                }
            } else {
                prev -> next = temp;
                delete cur;
                cur = temp;
            }
        } else {
            prev = cur;
            cur = cur -> next;
        }
    }

    // devo fare una cosa a parte per l'ultimo elemento
    if (cur -> elem == v) {
        if (prev == nullptr) {
            delete cur;
            l = nullptr;
        } else { 
            prev -> next = cur -> next;
            delete cur;
        }
    }
}