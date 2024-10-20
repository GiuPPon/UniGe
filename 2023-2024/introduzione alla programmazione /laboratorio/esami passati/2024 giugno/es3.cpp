#include "array.h"

dyn_array indexOfEvenInArray(const int* arr,unsigned int dim){
	dyn_array ret;
	ret.D = 0;
	
	if (dim == 0) {
		return ret;
	}
	
	unsigned int count = 0;
	for (unsigned int i = 0; i < dim; ++i) {
		if (arr[i] % 2 == 0) {
			++count;
		}
	}
	
	if (count == 0) {
		return ret;
	}
	
	ret.D = count;
	ret.A = new unsigned int[count];
	
	
	unsigned int index = 0;
	for (unsigned int k = 0; k < dim; ++k) {
		if (arr[k] % 2 == 0) {
			ret.A[index] = k;
			++index;
		}
	}
	
 	return ret;
}
