struct dyn_array{
    unsigned int *A;
    unsigned int D;
};

bool ascendingSequence(const int* arr,unsigned int dim);

dyn_array indexOfInArray(int v,const int* arr,unsigned int dim);
