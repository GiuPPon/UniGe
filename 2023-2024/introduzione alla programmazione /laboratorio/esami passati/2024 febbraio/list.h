typedef int Elem;

struct Cell {
   Elem elem;
   struct Cell* next;
};


typedef Cell* List;

unsigned int computeListSize(const List l);
bool allDiffInCircList(const List l);
void deleteAllCircList(List &l,int v);

