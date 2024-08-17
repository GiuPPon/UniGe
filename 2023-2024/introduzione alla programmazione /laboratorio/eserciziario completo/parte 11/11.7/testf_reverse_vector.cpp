/* Scrivere un programma di test che legge alcuni interi in vector<int> source usando la funzione 
readVectorAlt implementata in precedenza (presente in iovector.h), e poi chiama reverse, assegnando il
risultato a un altro vector<int> dest. Quindi stampa su una riga source e sulla riga seguente dest 
utilizzando la funzione printVector implementata in precedenza (presente in iovector.h). */

#include "reverse_vector.h"
#include <iostream>
using namespace std;

int main () {
    vector <int> source;
    readVectorAlt(source);
    printVector(source);

    vector <int> dest = reverse(source);
    printVector(dest);
}