#include "list.h"

void tailInsert(List &list, Elem newElem) {
	Cell *aux = new Cell;
	aux -> elem = newElem;
	aux -> next = nullptr;
	
	if (list == nullptr) {
		list = aux;
		return;
	}
	
	Cell *cur = list;
	while (cur -> next != nullptr) {
		cur = cur -> next;
	}
	
	cur -> next = aux;
}
