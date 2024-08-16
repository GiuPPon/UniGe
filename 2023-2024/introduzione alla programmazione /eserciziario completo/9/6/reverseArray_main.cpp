#include <iostream>
#include <string>
#include "reverseArray_funct.h"
using namespace std;

int main () {
    // definire un array di interi source inizializzato con N interi a scelta;
    int N = 5;
    int source[N] = {1, 2, 3, 4, 5};
    // definire un array di interi dest inizializzato con N interi zeri;
    int dest[N] = {0, 0, 0, 0, 0};
    // chiamare printArray su source
    try {
        printArray(source, N);
        cout << endl;
        // chiamare printArray su dest
        printArray(dest, N);
        cout << endl;
        // chiamare reverseArray su source e dest
        reverseArray(source, dest, N);
        // chiamare printArray su source
        printArray(source, N);
        cout << endl;
        // chiamare printArray su dest
        printArray(dest, N);
        cout << endl;
    }catch(string& err) {
        cout << err << endl;
    }
}

/* Il programma di test quando esegue la chiamata reverseArray(source, source, N) deve essere in grado 
di catturare l’eccezione (stampate un messaggio di errore che dice che non si può chiamare reverseArray 
usando la stesso parametro attuale per entrambi i parametri formali). */