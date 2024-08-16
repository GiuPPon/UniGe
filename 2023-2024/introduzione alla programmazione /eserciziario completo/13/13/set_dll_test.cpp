#include "set_dll.h"
#include <iostream>
using namespace std;

int main () {
    set_dll l1 = nullptr;
    set_dll l2 = nullptr;
    
    insert_set_dll(l1, 5);
    insert_set_dll(l1, 7);
    insert_set_dll(l1, 1);
    insert_set_dll(l1, 2);
    insert_set_dll(l1, 10);
    insert_set_dll(l1, 21);
    cout << "Lista 1 : " << endl;
    print_set_dll(l1);
    cout << "Lista 1 reverse: " << endl;
    revprint_set_dll(l1);
    
    insert_set_dll(l2, 6);
    insert_set_dll(l2, 3);
    insert_set_dll(l2, 1);
    insert_set_dll(l2, 2);
    insert_set_dll(l2, 14);
    insert_set_dll(l2, 26);
    cout << "Lista 2 : " << endl;
    print_set_dll(l2);
    cout << "Lista 2 reverse : " << endl;
    revprint_set_dll(l2);

    set_dll unione = union_set_dll(l1, l2);
    cout << "Unione : ";
    print_set_dll(unione);
    cout << endl;

    set_dll intersezione = intersect_set_dll(l1, l2);
    cout << "Intersezione : ";
    print_set_dll(intersezione);
    cout << endl;
}