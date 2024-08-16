#include <iostream>
#include "my_vector.h"
using namespace std;

int main () {
    try {
        my_vector v = create_my_vector(3); 
        print_my_vector_status(v);
        push_back_my_vector_element(v, 1.23); 
        print_my_vector_status(v);
        push_back_my_vector_element(v, 45.6);
        print_my_vector_status(v);
        double res = pop_back_my_vector_element(v);
        cout << "Ottenuto: "<< res << endl; 
        print_my_vector_status(v);
        push_back_my_vector_element(v, -34.0); 
        print_my_vector_status(v);
        set_my_vector_element(v, 99.9, 1); 
        print_my_vector_status(v);
        res = get_my_vector_element(v,0); 
        cout << "Ottenuto: "<< res << endl; 
        print_my_vector_status(v);
        resize_my_vector(v, 10); 
        print_my_vector_status(v);
        resize_my_vector(v, 1); 
        print_my_vector_status(v);
        safe_push_back_my_vector_element(v, 55.5); 
        print_my_vector_status(v);
        destroy_my_vector(v); 
        print_my_vector_status(v);
    } catch (string e) {cout << e << endl;}
    return 0;
}