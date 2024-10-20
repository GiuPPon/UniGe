#include <string>

typedef std::string Elem;

struct Cell {
   Elem elem;
   struct Cell* next;
};

typedef Cell * List;

void tailInsert(List &list, Elem newElem);

unsigned int elementIstancesCount(List list, Elem toFind);

std::string lessFrequentFind(List list);