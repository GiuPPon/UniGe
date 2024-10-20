#include "array.h"

bool ascendingSequenceEvenOdd(const int* arr, unsigned int dim){
	if (dim == 0 || dim == 1) {
		return true;
	}
	
	
	unsigned int pari = 0;
	unsigned int dispari = 0;
	
	for (unsigned int i = 0; i < dim; ++i) {
		if (arr[i] % 2 == 0) {
			++ pari;
		} else {
			++dispari;
		}
	}
	
	int arrPari[pari];
	int arrDispari[dispari];
	
	unsigned int iPari = 0;
	unsigned int iDispari = 0;
	for (unsigned int i = 0; i < dim; ++i) {
		if (arr[i] % 2 == 0) {
			arrPari[iPari] = arr[i];
			++iPari;
		} else {
			arrDispari[iDispari] = arr[i];
			++iDispari;
		}
	}
	
	
	if (pari > 0) {
		for (unsigned int j = 0; j < pari - 1; ++j) {
			if (arrPari[j]>arrPari[j+ 1]){
				return false;
			}
		}
	}
	
	if (dispari > 0) { 
		for (unsigned int g = 0; g < dispari - 1; ++g) {
			if (arrDispari[g]>arrDispari[g+1]) {
				return false;
			}
		}
	}
	
	return true;

}
