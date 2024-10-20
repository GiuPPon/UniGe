#include "list.h"
#include <iostream>

// uso l'esercizio scorso come funzione ausiliaria
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


std::string lessFrequentFind(List list) {
   	std::string result;
   	Cell *cur = list;
   	
   	if (list == nullptr) {
   		return "";
   	}
   	
   	if (cur -> next == nullptr) {
   		return cur -> elem;
   	}
   	
   	
   	
   	Cell *temp = cur -> next;
  
   	while (cur != nullptr) { 	
   		if (elementIstancesCount(list, cur -> elem) == 1) {
   			return cur -> elem;
   		}
   		
		if (cur -> elem != temp -> elem) {
	   		if (elementIstancesCount(list, cur -> elem) < elementIstancesCount(list, temp -> elem)) {
	   			result = cur -> elem;
	   		} else if (elementIstancesCount(list, cur -> elem) == elementIstancesCount(list, temp -> elem)) {
	   			result = list -> elem;
	   		} else {
	   			result = temp -> elem;
	   		}
	   	}
   		cur = cur -> next;		
   	}  
   	
    	return result;
}


