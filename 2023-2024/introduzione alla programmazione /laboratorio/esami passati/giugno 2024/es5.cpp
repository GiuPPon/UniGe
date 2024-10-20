#include "list.h"

unsigned int elementIstancesCount(List list, Elem toFind) {
	if (list == nullptr) {
		return 0;
	}
	
	unsigned int count = 0;
	Cell *cur = list;
	while (cur != nullptr) {
		if (cur -> elem == toFind) {
			++count;
		}
		cur = cur -> next;
	}
	return count;
}
