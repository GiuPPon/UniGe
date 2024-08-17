/* Scrivere un programma che legge un array di interi positivi, lo scorre dall’inizio alla fine, e di
tutti gli elementi che sono ripetuti in sequenza contigua cancella tutte le occorrenze tranne una, 
trasformando le ripetizioni in elementi unici (vedi esempi qui sotto).
Al termine del procedimento, i valori che non sono stati eliminati devono essere contenuti in elementi
consecutivi dello stesso array, e gli elementi rimanenti devono essere azzerati. Il programma infine 
stampa tutti gli elementi non zero. [ File unique.cpp ] */

#include <iostream>
using namespace std;

int main() {
const int N = 5; // Definisci la dimensione massima dell'array
    int array[N];
    int aux[N]; 
    
    cout << "Inserisci gli elementi dell'array:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // Copia del primo elemento di ogni sequenza ripetuta nell'array ausiliario
    int curr = 0;
    aux[curr++] = array[0]; // Copia sempre il primo elemento
    for (int i = 1; i < N; ++i) {
        // Se l'elemento corrente è diverso dall'elemento precedente
        if (array[i] != array[i - 1]) {
            aux[curr++] = array[i]; // Copia l'elemento corrente
        }
    }

    // Copia del contenuto dell'array ausiliario nell'array originale
    for (int i = 0; i < curr; ++i) {
        array[i] = aux[i];
    }

    // Azzeramento degli elementi rimanenti nell'array originale
    for (int i = curr; i < N; ++i) {
        array[i] = 0;
    }

    // Stampa gli elementi non zero dell'array originale
    cout << "Risultato finale:" << endl;
    for (int i = 0; i < curr; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
