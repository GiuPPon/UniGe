#ifndef D_ARRAY
#define D_ARRAY

//****************************
// d_array.h
//****************************

struct dynamic_array {
    double* store;
    unsigned int size;
};

// PROTOTIPI delle funzioni da sviluppare per libreria d_array
void read_d_array(dynamic_array &d);
void print_d_array(const dynamic_array &d);
void delete_d_array(dynamic_array &d);
void create_d_array(dynamic_array &d, int size, double value);
void set_d_array_element(dynamic_array &d, unsigned int index, double value);
double get_d_array_element(const dynamic_array &d, unsigned int index);
void concat_d_arrays(const dynamic_array &t1, const dynamic_array &t2, dynamic_array &t3);
void sort_d_array(dynamic_array &d); // usando Selection Sort

#endif
