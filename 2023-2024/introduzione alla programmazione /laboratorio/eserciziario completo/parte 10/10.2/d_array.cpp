#include "d_array.h"
#include <iostream>
using namespace std;

void read_d_array(dynamic_array &d) {
    int s = -1;
    while (s <= 0) {
        cout << "Inserisci la dimensione dell'array" << endl;
        cin >> s;
    }
    d.size = s;
    d.store = new double[s]; //allocare
    for (int i = 0; i < s; ++i) {
        cout << "inserisci un valore";
        cin >> d.store[i];
    }
}

void print_d_array(const dynamic_array &d) {
    cout << "{ ";
    for (int i = 0; i < d.size; ++i) {
        cout << d.store[i];
        if (i < d.size - 1) {
            cout << ", ";
        }
    }
    cout << " }";
}

void delete_d_array(dynamic_array &d) {
    if (d.size > 0) {
        delete[] d.store; // deallocare
        d.size = 0;
    } else {
        string err = "Errore: array gia' vuoto";
        throw err;
    }
}

void create_d_array(dynamic_array &d, int size, double value) {
    if (size < 0) {
        string err = "Errore";
        throw err;
    }
    if (d.size > 0) {
        delete_d_array(d);
    }
    d.size = size;
    d.store = new double[size];
    for (int i = 0; i < d.size; ++i) {
        d.store[i] = value;
    }
}

void set_d_array_element(dynamic_array &d, unsigned int index, double value) {
    if (index < 0 || index > d.size) {
        string err = "errore";
        throw err;
    }
    // La funzione assegna value all’elemento con indice index di d.store
    d.store[index] = value;
}

double get_d_array_element(const dynamic_array &d, unsigned int index) {
    if (index < 0 || index > d.size) {
        string err = "errore";
        throw err;
    }
    return d.store[index];
}

/* scrivere una funzione che riceve tre riferimenti ad array dinamici t1, t2, e t3. La funzione crea 
dinamicamente un nuovo array (da assegnare a t3) di lunghezza t1.size+t2.size dove nelle prime t1.size
caselle si trovano gli elementi di t1 e nelle prime t2.size caselle si trovano gli elementi di t2. */
void concat_d_arrays(const dynamic_array &t1, const dynamic_array &t2, dynamic_array &t3) {
    int size = t1.size + t2.size;
    t3.size = size;
    t3.store = new double[size];

    for (int i = 0; i < t1.size; ++i) {
        t3.store[i] = t1.store[i];
    }
    for (int i = 0; i < t2.size; ++i) {
        t3.store[t1.size + i] = t2.store[i];
    }
}

void sort_d_array(dynamic_array &d) {
    int greatestIndex;
    for (int i = 0; i < d.size; ++i) {
        greatestIndex = i;
        for (int j = i + 1; j < d.size; ++j) {
            if (d.store[j] < d.store[greatestIndex]) {
                greatestIndex = j;
            }
        }
        int aux = d.store[i];
        d.store[i] = d.store[greatestIndex];
        d.store[greatestIndex] = aux;
    }
}