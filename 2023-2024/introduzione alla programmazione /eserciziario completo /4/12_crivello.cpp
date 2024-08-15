/* Scrivere un programma che, usando l’algoritmo “crivello di Eratostene”, trova i numeri primi minori
di 1000. Verificare i risultati ottenuti con la vostra implementazione confrontandoli con la lista di
primi. [ File crivello.cpp ]
CRIVELLO DI ERATOSTENE (n)
1) Creare un array di bool chiamato isprime di lunghezza n, inizializzandolo a tutti valori true.
Al termine dell'algoritmo, l'elemento i-esimo di isprime varrà true se i e' primo, false altrimenti
2) Inizialmente, sia p pari a 2, il numero primo più piccolo (quindi 0 e 1 non sono primi).
3) Partendo da p escluso, marcare come NON PRIMI tutti i numeri multipli di p (2p, 3p, 4p...).
Ovvero impostare a false ogni elemento isprime[2*p], isprime[3*p], ...
4) Partire da p=p+1 e scorrere in avanti l'array isprime finché non si trova il primo numero
NON marcato (isprime[p] è true), oppure finché non è finita la lista
5) Se la lista è finita, stop. Altrimenti p diventa pari al numero trovato e si ricomincia dal punto 3)
(la prima volta sarà per p=3)
All'uscita dell'algoritmo, tutti i numeri non marcati (tali che il corrispondente elemento di isprime
vale ancora true) sono tutti i numeri primi < n
Stampare tutti i numeri tali che il corrispondente elemento di isprime è true.
Per capire meglio il funzionamento dell’algoritmo è possibile osservare l’animazione presente nella
pagina Wikipedia che mostra graficamente l’esecuzione di una variante molto simile sui numeri compresi
tra 0 e 120
[SUGGERIMENTO: per implementare una versione base (senza ottimizzazioni) del crivello si può procedere
in questo modo:
(a) Ciclare su tutti gli N elementi di isprime per impostarli a true
(b) Impostare gli elementi di isprime con indice 0 e 1 a false
(c) Ciclare sugli elementi di isprime con p che va da 2 a N-1.
i. Se in isprime si trova un elemento true in posizione p
ii. Ciclare su tutti i multipli di p per marcarli false
(d) Ciclare su tutti gli N elementi di isprime è stampare l’indice di quelli pari a true
Ricordate il criterio per scegliere tra for, while e do ... while (ripassare parte sui cicli). ] */

#include <iostream>
using namespace std;

int main() {
    const int N = 1000;
    bool isprime[N];

    for (int i = 0; i < N; ++i) {
        isprime[i] = true;
    }

    isprime[0] = false;
    isprime[1] = false;

    for (int p = 2; p < N; ++p) {
        if (isprime[p]) {
            for (int i = p * p; i < N; i = i + p) {
                isprime[i] = false;
            }
        }
    }

    cout << "Numeri primi minori di 1000: ";
    for (int i = 0; i < N; ++i) {
        if (isprime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
