#include <iostream>
using namespace std;

bool isUpper(char array[], int size) {
    for (int i = 0; i < size; ++i) {
        /* if (array[i] < 'A' || array[i] > 'Z') {
            return false;
        } */
        if (*(array + i) < 'A' || *(array + i) > 'Z') {
            return false;
        }
    }
    return true;
}