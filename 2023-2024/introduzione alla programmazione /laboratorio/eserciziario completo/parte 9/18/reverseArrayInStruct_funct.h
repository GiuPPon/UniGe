#ifndef REVERSEARRAY_FUNCT_H
#define REVERSEARRAY_FUNCT_H

const int N = 5;

struct array_str {
    int size = N;
    int array[N];
};

void reverseArray(int* source, int* dest, int size);
void printArray(int* s, int size);

#endif
