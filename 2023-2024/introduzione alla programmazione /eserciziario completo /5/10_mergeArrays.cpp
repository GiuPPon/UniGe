/* Scrivere un programma che dichiara tre array di interi s1, s2 e d, il terzo dei quali di dimensioni
pari alla somma delle dimensioni degli altri due (ad esempio se s1 ha dimensione N=9, e s2 ha 
dimensione M=10, d dovrà avere dimensione N+M cioè 19).
Il programma deve popolare sia s1 che s2 in modo random con interi nell’intervallo [ 0 , 255 ] (vedi
Parte 3, Es. 9 per la generazione di numeri random). A questo punto, stampare il contenuto di s1 e s2
(vedi Parte 4, Es. 6 per la stampa su singola riga).
Poi, il programma deve ordinare s1 e s2 in maniera crescente ([HINT: utilizzate il codice sviluppato 
negli esercizi precedenti in questa sezione! esempio selectionSort.cpp]).
Infine riempire d in modo che contenga tutti gli elementi dei due array s1 e s2 ordinati tra loro in 
modo crescente. Alla fine il programma deve stampare s1 e s2 ordinati e l’array d.
[ File mergeArrays.cpp ]
Attenzione: nel costruire il contenuto di d tenete conto del fatto che i due array di partenza sono 
stati precedentemente ordinati. Se il merge dei due array s1 e s2 viene effettuato in modo sensato 
NON è necessario eseguire un ordinamento di d.
Esempio di output:
Array s1 (generato) = { 103, 136, 48, 74, 180, 37, 142, 0, 2 }
Array s2 (generato) = { 167, 196, 204, 93, 66, 95, 49, 139, 222, 49 }
Array s1 (ordinato) = { 0, 2, 37, 48, 74, 103, 136, 142, 180 }
Array s2 (ordinato) = { 49, 49, 66, 93, 95, 139, 167, 196, 204, 222 }
Array d = { 0, 2, 37, 48, 49, 49, 66, 74, 93, 95, 103, 136, 139, 142, 167, 180, 196, 204, 222 } */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    int N = 9;
    int M = 10;
    int s1[N];
    int s2[M];
    int d[N + M];
    srand(time(NULL));

    // array s1
    for (int i = 0; i < N; i++) {
        s1[i] = rand() % 255;
    }
    cout<<"Array s1 : {";
        for  (int i = 0; i < N; i++ ) {
            cout << s1[i];
            if (i != (N - 1)){
                cout<<", ";
            }
        }
    cout << "}" << endl;

    // array s2
    for (int i = 0; i < M; i++) {
        s2[i] = rand() % 255;
    }
    cout<<"Array s2 : {";
        for  (int i = 0; i < M; i++ ) {
            cout << s2[i];
            if (i != (M - 1)){
                cout<<", ";
            }
        }
    cout << "}" << endl;

    // ordinamento array s1 e s2
    int greatestIndexs1, greatestIndexs2;

    for (int i = 0; i < N; ++i) {
        greatestIndexs1 = i;
        for (int j = i + 1; j < N; ++j) {
            if (s1[j] < s1[greatestIndexs1]) {
                greatestIndexs1 = j;
            }
        }
        int aux = s1[i];
        s1[i] = s1[greatestIndexs1];
        s1[greatestIndexs1] = aux;
    }

    for (int i = 0; i < N; ++i) {
        greatestIndexs2 = i;
        for (int j = i + 1; j < N; ++j) {
            if (s2[j] < s2[greatestIndexs2]) {
                greatestIndexs2 = j;
            }
        }
        int aux = s2[i];
        s2[i] = s2[greatestIndexs2];
        s2[greatestIndexs2] = aux;
    }

    // array s1 e s2 ordinati 
    cout << "Array s1 ordinato = { ";
    for (int i = 0; i < N; i++) {
        cout << s1[i];
        if (i != (N - 1)) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    cout << "Array s2 ordinato = { ";
    for (int i = 0; i < M; i++) {
        cout << s2[i];
        if (i != (M - 1)) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    //unione ordinata degli array s1 e s2 
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < N && j < M) {
        if (s1[i] <= s2[j]) {
            d[k++] = s1[i++];
        } else {
            d[k++] = s2[j++];
        }
    }
    while (i < N) {
        d[k++] = s1[i++];
    }
    while (j < M) {
        d[k++] = s2[j++];
    }
    //array d 
    cout << "Array d: { ";  
        for (int i = 0; i < N + M; i++) { 
            cout << d[i];  
            if (i != (N + M - 1)) {
                cout << ", ";
            } 
        }
    cout << " }" << endl;
}