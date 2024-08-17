/* Scrivere una funzione countDigitsInArray che preso un array v di N elementi (dove N è una costante 
positiva a vostra scelta) di tipo char restituisce il numero di cifre, cioè caratteri nell’intervallo 
['0','9'], presenti in v, usando l’aritmetica dei puntatori per scorrere v. Ad esempio su 
{'f','4','c','r','5','R'} ritorna 2.
[ File countDigitsInArray_funct.h ] e [ File countDigitsInArray_funct.cpp ] per dichiarazione e 
definizione della funzione e [ File countDigitsInArray_main.cpp ] per i test. */

int countDigitsInArray(char* v, int N) {
    int count = 0; 

    for (int i = 0; i < N; ++i) {
        if (v[i] >= '0' && v[i] <= '9') {
            count++;
        }
    }
    return count;
}