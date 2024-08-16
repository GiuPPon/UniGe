#include <iostream>
#include "my_vector.h"
using namespace std;

my_vector create_my_vector(unsigned int capacity) {
    if (capacity <= 0) {
        string e = "create_my_vector: capacity fornita non positiva";
        throw e;
    }

    my_vector v;
    v.store = new double[capacity];
    v.size = 0;
    v.capacity = capacity;
    return v;
}

void print_my_vector_status(const my_vector &v) {
    cout << "**********************" << endl;
    cout << "my_vector size = " << v.size << endl;
    cout << "my_vector capacity = " << v.capacity << endl;

    cout << "my_vector store = { ";
    for (unsigned int i = 0; i < v.size; ++i) {
        cout << v.store[i];
        if (i < v.size - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
    cout << "**********************" << endl;
}

void push_back_my_vector_element(my_vector &v, double x) {
    if (v.size == v.capacity) {
        string e = "push_back_my_vector_element: Impossibile inserire elemento in Array pieno";
        throw e;
    }
    
    if (v.size < v.capacity) {
        v.store[v.size] = x;
        ++v.size;
    }
}

double pop_back_my_vector_element(my_vector &v) {
    if (v.size == 0) {
        string e = "pop_back_my_vector_element: Impossibile estrarre elemento da Array vuoto";
        throw e;
    }
    if (v.size < 0) {
        string e = "pop_back_my_vector_element: size negativa";
        throw e;
    }

    double valore = v.store[v.size - 1];
    --v.size;
    return valore;
    
}

void set_my_vector_element(my_vector &v, double value, unsigned int index) {
    if (v.size == 0) {
        string e = "set_my_vector_element: Impossibile impostare un elemento di un My_Vector vuoto";
        throw e;
    } else if (index < 0 || index > (v.size - 1)) {
        string e = "set_my_vector_element: Indice fornito non ammissibile";
        throw e;
    }

     v.store[index] = value;
}

double get_my_vector_element(const my_vector &v, unsigned int index) {
    if (v.size == 0) {
        string e = "get_my_vector_element: Impossibile leggere un elemento da un My_Vector vuoto";
        throw e;
    } else if (index < 0 || index > (v.size - 1)) {
        string e = "get_my_vector_element: Indice fornito non ammissibile";
        throw e;
    }

    return v.store[index];
}

void resize_my_vector(my_vector &v, unsigned int new_capacity) {
    if (new_capacity <= 0) {
        string e = "resize_my_vector: new_capacity fornita non positiva";
        throw e;
    }

    double *new_block = new double[new_capacity];

    unsigned int copy;
    if (v.size < new_capacity) {
       copy = v.size; 
    } else {
        copy = new_capacity;
    }

    for (unsigned int i = 0; i < v.size; ++i) {
        new_block[i] = v.store[i];
    }
    
    if (v.capacity > 0) {
        delete[] v.store;
    }

    v.store = new_block;
    v.capacity = new_capacity;
    v.size = copy;
}

void safe_push_back_my_vector_element(my_vector &v, double x) {
    if (v.capacity == 0) {
        resize_my_vector(v, 1);
        push_back_my_vector_element(v, x);
    }
    if (v.capacity == v.size) {
        resize_my_vector(v, 2*v.capacity);
        push_back_my_vector_element(v, x);
    }

    if (v.size < v.capacity) {
        v.store[v.size] = x;
        ++v.size;
    }  
}

void destroy_my_vector(my_vector &v) {
    if (v.capacity > 0) {
        delete[] v.store;
        v.size = 0;
        v.capacity = 0;
    } 
}

bool looks_consistent_my_vector(const my_vector &v) {
    if (v.store != 0 && v.size > 0 && v.size < v.capacity && v.capacity > 0) {
        return true;
    }
    return false;
}

void sort_my_vector(my_vector &v) {
    int greatestIndex;
    for (unsigned int i = 0; i < v.size; ++i) {
        greatestIndex = i;
        for (unsigned int j = i + 1; j < v.size; ++j) {
            if (v.store[j] < v.store[greatestIndex]) {
                greatestIndex = j;
            }
        }
        int aux = v.store[i];
        v.store[i] = v.store[greatestIndex];
        v.store[greatestIndex] = aux;
    }
}
