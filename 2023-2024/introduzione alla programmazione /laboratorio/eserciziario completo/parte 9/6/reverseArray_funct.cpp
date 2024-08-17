/* (Puntatori Array + Compilazione Separata) Riprendete la vostra implementazione della programma 
reverse dell’Esercizio 11 in Sezione 4 e creare una funzione reverseArray che presi in input due array 
di interi source e dest copia nel secondo array gli elementi del primo in ordine inverso. Poi provate 
a modificare il programma di test utilizzando source nel main per instanziare entrambi i parametri di 
reverseArray. Se avete implementato reverseArray nel modo ovvio, non otterrete il risultato atteso, 
perché copiando gli elementi dalla testa di source nella coda di dest in realtà state modificando la 
coda di source stesso. Per evitare questo problema, vogliamo premettere al corpo della funzione 
reverseArray il controllo che i due parametri corrispondano ad aree di memoria distinte e se invece 
coincidono sollevare un’eccezione.
Nota. In questo specifico caso si potrebbe evitare il problema usando la stessa tecnica suggerita per 
l’esercizio 20 in sezione 4. Però, in situazioni più complesse potrebbe essere impossibile risolvere 
i problemi in caso di aliasing fra i parametri.
[ File reverseArray_funct.h ] e [ File reverseArray_funct.cpp ] per dichiarazione e definizione delle 
funzioni reverseArray e printArray (vedi esercizio precedente). [ File reverseArray_main.cpp ] per i 
test. */

#include <iostream>
#include <string>
#include "reverseArray_funct.h"
using namespace std;

void reverseArray(int* source, int* dest, int size) {
    //void reverseArray(int source[], int dest[], int size) { // alternativa
    // se indirizzo di source uguale a indirizzo di dest sollevare eccezione di tipo a vostra scelta
    if (&source == &dest) {
        string err = "Errore: source uguale a dest";
        throw err;
    }
    for (int i = 0; i < size; ++i) {
        // copio l'i-esimo elemento da source a dest nella posizione corretta
        dest[i] = source[size - 1 - i];
    }
}


void printArray(int* s, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *s;
        if (i < size - 1) {
            cout << ", ";
        }
        ++s;
    }
}