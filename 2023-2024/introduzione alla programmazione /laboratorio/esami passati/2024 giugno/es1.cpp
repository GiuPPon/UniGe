#include "funz.h"

unsigned int returnLucasNumberInPos(unsigned int pos){ 
	
	if (pos == 0) {
		return 2;
	}
	if (pos == 1) {
		return 1;
	}


	int arr[pos];
	arr[0] = 2;
	arr[1] = 1;
	
	for (unsigned int i = 2; i <= pos; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	return arr[pos];
}

