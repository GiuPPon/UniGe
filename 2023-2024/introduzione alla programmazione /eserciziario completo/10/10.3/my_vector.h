#ifndef MY_VECTOR
#define MY_VECTOR

//****************************
// my_vector.h
//****************************

struct my_vector {
    unsigned int size;
    unsigned int capacity;
    double* store;
};

// PROTOTIPI delle funzioni da sviluppare per libreria my_vector
my_vector create_my_vector(unsigned int capacity);
void print_my_vector_status(const my_vector &v);
void push_back_my_vector_element(my_vector &v, double x);
double pop_back_my_vector_element(my_vector &v);
void set_my_vector_element(my_vector &v, double value, unsigned int index);
double get_my_vector_element(const my_vector &v, unsigned int index);
void resize_my_vector(my_vector &v, unsigned int new_capacity);
void safe_push_back_my_vector_element(my_vector &v, double x);
void destroy_my_vector(my_vector &v);
bool looks_consistent_my_vector(const my_vector &v);
void sort_my_vector(my_vector &v);

#endif
