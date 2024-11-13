#ifndef LIST_TEST
#define LIST_TEST

#include <iostream>
#include <string>
using namespace std;

// tipo contenuto della Cella
typedef string City;

// tipo Cell di una lista doppiamente linkata
struct Cell { 
    City city;
    struct Cell* next;
    struct Cell* prev; 
    };

// tipo lista
typedef Cell* List;

void inserimentoInTesta(List &list, City newCity);
string stampaAndata(List list);
string stampaRitorno(List list);
string stampaAdiacenti(List list, City newCity);

#endif