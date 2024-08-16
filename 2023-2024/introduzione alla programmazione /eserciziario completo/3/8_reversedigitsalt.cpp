/* modificare il programma in modo che se l’utente inserisce un numero negativo invece di uscire dal
programma
(a) si ripeta la richiesta di inserimento (e la lettura) finchè non viene dato un numero positivo.
(b) si stampi il numero ottenuto leggendo il numero dato da destra verso sinistra. Ad esempio su -56 
    si stampi -65. 
[ File reversedigitsneg.cpp ] */

#include <iostream> 
using namespace std;

int main () {
    int k; 

    do {
        cout << "Inserire un numero intero: ";
        cin >> k;

        if (k < 0) {
            cout << "Numero negativo inserito. Riprova con un numero positivo." << endl;
        }
    } while (k < 0);

    cout << "Rovesciando " << k;
    int inv = 0;
    
    while (k != 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10;
        inv = inv + mod;
    }
    
    cout << " si ottiene " << inv << endl;
}