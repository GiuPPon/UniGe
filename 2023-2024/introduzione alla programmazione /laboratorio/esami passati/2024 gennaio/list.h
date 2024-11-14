#include <string>

typedef std::string Elem;

struct Cell {
   Elem elem;
   struct Cell* next;
};


typedef Cell* List;

unsigned int computeListSize(const List &l);
bool insertElemInListAtIndex(List &l, Elem s, unsigned int index);
void deleteLastInstanceOfElemInList(List &l, Elem s);