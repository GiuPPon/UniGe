/* Scrivere un programma che chiede all’utente un numero intero K strettamente positivo e ne stampa il
numero di cifre (in base 10). Ad esempio su 27458 stampa 5.
La richiesta deve essere esattamente questa "Inserisci un numero intero strettamente positivo: "
(notare lo spazio in fondo);
L’output è:
— se K <= 0 allora "Il numero inserito NON e' valido"
— se 1 <= K <= 9 allora "Il numero inserito e' composto da 1 cifra" (notare il singolare)
— se K >= 10 allora "Il numero inserito e' composto da N cifre" dove N è il numero di cifre di K
  (notare il plurale)
[ File numdigits.cpp ] */

#include <iostream>
using namespace std;

int main () {
    int K, N, inv;
    int count = 0;
    cout << "Inserisci un numero intero strettamente positivo: ";
    cin >> K;

    if (K <= 0) {
        cout << "Il numero inserito NON e' valido";
    } else if ((1 <= K) && (K <= 9)) {
        cout << "Il numero inserito e' composto da 1 cifra";
    } else {
        while (K > 0) {
            N = K % 10;
            inv = inv * 10 + N;
            K = K / 10;
            ++count;
        }
        cout << "Il numero inserito e' composto da " << count << " cifre" << endl;
    }
}