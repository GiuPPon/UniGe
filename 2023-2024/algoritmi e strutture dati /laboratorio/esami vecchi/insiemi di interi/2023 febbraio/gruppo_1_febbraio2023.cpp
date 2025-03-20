/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia)   */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo gli Insiemi di numeri interi.
// In questa versione molto semplificata un'insieme e' implementato come un array statico di 
// dimensione massima uguale a 8 (per semplificare la prova non consideriamo il caso di overflow).
//
// Sempre per non complicare troppo, non esistono operazioni di creazione dell'insieme e di 
// inserimento di un elemento in un insieme (come ad esempio visto a lezione).
//
// Anche il fatto che un elemento non possa comparire piu' di una volta in un insieme viene 
// gestito a livello di inizializzazione, evitando di avere due volte lo stesso numero intero.

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:



#include<iostream>
using namespace std;

const int dim = 8; // dimensione massima di un insieme

/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

/* Sviluppare le tre seguenti funzioni C/C++:

   1) difference() che dati due insiemi 'a' e 'b', crea un terzo insieme 'c' che e' la differenza tra 'a' e 'b' ('a' - 'b') 
     (l'insieme differenza per definizione e' composto dagli elementi di 'a' che non appartengono a 'b'). La funzione 
	 restituisce in output la dimensione dell'insieme c. Assumiamo che 'a' e 'b' contengano entrambi 'dim' elementi 
	 (ovvero la dimensione massima di un insieme), mentre 'c' sia vuoto.
      
   2) intersection() che calcola l'intersezione tra due insiemi passati come parametri e mette il risultato 
      in un terzo parametro. La funzione deve anche restituire la dimensione dell'insieme intersezione.
   
   3) equal() che restituisce 'true' se i due insiemi passati come parametri sono uguali, e 'false' altrimenti.
      
*/

// Dati due insiemi 'a' e 'b', questa funzione crea un terzo insieme 'c' che e' la differenza tra 'a' e 'b' 
// ('insieme differenza per definizione e' composto dagli elementi di 'a' che non appartengono a 'b'). 
// La funzione restituisce in output la dimensione dell'insieme 'c'
// Assumiamo che 'a' e 'b' contengano entrambi 'dim' elementi, mentre 'c' sia vuoto
// si suppone che 'a' e 'b' non possano contenere elementi "doppi" (vincolo soddisfatto a livello di inizializzazione)
int difference(const int a[], const int b[], int c[]) {
	return 0; // istruzione inserita solo per non avere problemi di compilazione
}

// Calcola l'intersezione di 'a' e 'b' e mette il risultato in 'c'. Inoltre la funzione deve anche restituire 
// la dimensione (cioe' la size) dell'insieme 'c', ovvero l'insieme intersezione calcolato.
// Assumiamo che 'a' e 'b' contengano entrambi 'dim' elementi, mentre 'c' sia inizialmente vuoto.
// si suppone che 'a' e 'b' non possano contenere elementi "doppi" (vincolo soddisfatto a livello di inizializzazione)
int intersection(const int a[], const int b[], int c[]) {
    return 0; // istruzione inserita solo per non avere problemi di compilazione
}

// Ritorna 'true' se 'a' e 'b' sono uguali, 'false' altrimenti
// si suppone che 'a' e 'b' non possano contenere elementi "doppi" (vincolo soddisfatto a livello di inizializzazione)
bool equal(const int a[], const int b[]) {
    return true; // istruzione inserita solo per non avere problemi di compilazione
}

// Stampa l'insieme 'a' avente dimensione 'size'
// si suppone che 'a' non possa contenere elementi "doppi"
void print(const int a[], int size) {
    for (int i=0; i<size; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    // inizializzazione degli insiemi (non possono essere inseriti numeri doppi)
    int x[dim] = {1, 3, 5, 7, 90, 32, 45, 10};
    int equal_to_x[dim] = {1, 10, 7, 5, 90, 32, 45, 3};
    int xx[dim] = {0, 1, 7, 49, 90, 35, 3, 10};
    int y[dim] = {4, 5, 45, 10, 33, 6, 1, 2};
    int diff[dim]; // insieme nel quale verra' inserito il risultato della differenza tra xx e x
    int z[dim]; // insieme nel quale verra' inserito il risultato dell'intersezione tra x e y
    
    
    cout << "*** PRIMA FUNZIONE *** " << endl;
    cout << "IL TEST DIFFERENZA E' CORRETTO SE LE DUE STAMPE SONO UGUALI (A MENO DI PERMUTAZIONI DEI NUMERI INTERI)" << endl;
    cout << "--- Test 1: risultato corretto" << endl;
    cout << "0 49 35 Dimensione 3" << endl;
    cout << "--- Test 1: stampa della vostra funzione" << endl;
    int newdim = difference(xx, x, diff);
    print(diff, newdim);
    cout << "Dimensione " << newdim << endl << endl;
    cout << endl;
    
    cout << "*** SECONDA FUNZIONE *** " << endl;
    cout << "IL TEST INTERSEZIONE E' CORRETTO SE LE DUE STAMPE SONO UGUALI (A MENO DI PERMUTAZIONI DEI NUMERI INTERI)" << endl;
    cout << "--- Test 1: risultato corretto" << endl;
    cout << "1 5 45 10 Dimensione 4" << endl;
    cout << "--- Test 1: stampa della vostra funzione" << endl;
    newdim = intersection(x, y, z);
    print(z, newdim);
    cout << "Dimensione " << newdim << endl << endl;
    cout << endl;
    
    cout << "*** TERZA FUNZIONE *** " << endl;
    if (!equal(x, y)) cout << "TEST 1 UGUALE PASSATO" << endl;
    else cout << "TEST 1 UGUALE FALLITO" << endl; 
    if (equal(x, equal_to_x)) cout << "TEST 2 UGUALE PASSATO" << endl;
    else cout << "TEST 2 UGUALE FALLITO" << endl;
    return 0;
}

