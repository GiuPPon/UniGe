/* Scrivere un programma di test che dichiara un vector<int> e fa il test della funzione insert nei 
seguenti casi:
(a) Inserimento in v vuoto
(b) Inserimento in testa (in posizione 0) a v non vuoto
(c) Inserimento in coda (dopo l’ultima posizione) a v non vuoto
(d) Inserimento in posizione generica (non testa, non coda) in v non vuoto
(e) Inserimento in posizione non valida (usare try . . . catch per trattare l’eccezione). */

#include <iostream>
#include "insert.h"
using namespace std;

int main () {
    vector<int> v;

    cout << "(a): Inserimento in v vuoto" << endl;
    insert(v, 0, 10);
    cout << "Inserimento riuscito. Contenuto di v: ";
    printVector(v);


    cout << "(b): Inserimento in testa a v non vuoto" << endl;
    v = {1, 2, 3};
    insert(v, 0, 0);
    cout << "Inserimento riuscito. Contenuto di v: ";
    printVector(v);

    cout << "(c): Inserimento in coda a v non vuoto" << endl;
    insert(v, v.size(), 4);
    cout << "Inserimento riuscito. Contenuto di v: ";
    printVector(v);

    cout << "(d): Inserimento in posizione generica in v non vuoto" << endl;
    insert(v, 2, 100);
    cout << "Inserimento riuscito. Contenuto di v: ";
    printVector(v);
    

    cout << "(e): Inserimento in posizione non valida" << endl;
    try {
        insert(v, 10, 100);
        cout << "Inserimento riuscito. Contenuto di v: ";
        printVector(v);
    } catch (int err) {
    cout << "Errore: Posizione non valida." << endl;
    }
}