/* Modificare shiftLeft.cpp e rotateRight.cpp in modo da ottenere programmi che leggano un numero 
intero N, positivo o negativo, ed eseguano rispettivamente la traslazione e la rotazione verso 
sinistra (se N negativo) o verso destra (se N positivo) di |N| posizioni.
[ File shiftN.cpp ] [ File rotateN.cpp ]
NOTA. Se |N| ≥ lunghezza array, shift creerà un vettore vuoto. Se |N| > lunghezza array, rotate si 
comporterà come se |N| fosse sostituito da |N % lunghezza array|. In particolare, se 
|N| == k×lunghezza array (k intero), rotate creerà un vettore uguale a quello dato, ovvero nessuna
modifica. */

// rotateN.cpp
#include <iostream>
using namespace std;

int main() {
    int D = 5;
    int a[D];
    int N;

    // Input dei valori per il vettore
    for (int i = 0; i < D; ++i) {
        cout << "valore " << i + 1 << " dell'array: ";
        cin >> a[i];
    }

    cout << "Inserisci la posizione da cui eseguire la traslazione: ";
    cin >> N;

    // Calcola il numero effettivo di posizioni da ruotare
    int rotation = N % D;
    if (rotation < 0) {
        rotation = rotation + D;
    }

    // Rotazione dell'array
    int aux[D];
    for (int i = 0; i < D; ++i) {
        aux[(i + rotation) % D] = a[i];
    }

    // Copia l'array ruotato nell'array originale
    for (int i = 0; i < D; ++i) {
        a[i] = aux[i];
    }

    cout << "Array dopo la rotazione: ";
    for (int i = 0; i < D; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}