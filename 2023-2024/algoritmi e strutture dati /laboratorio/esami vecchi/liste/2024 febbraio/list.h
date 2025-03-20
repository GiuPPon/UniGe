#ifndef LIST_H
#define LIST_H

struct cell {
    int value;
    cell* next;
};
typedef cell* List;

void insert_tail(List& l, const int v);
bool remove(List& l, unsigned int pos);
unsigned int count_between(const List& l, const int a, const int b);

#endif // LIST_H
