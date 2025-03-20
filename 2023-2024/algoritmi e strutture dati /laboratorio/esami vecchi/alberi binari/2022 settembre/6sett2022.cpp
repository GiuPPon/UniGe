/******************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD  (06/09/2022) */
/******************************************************/

// Descrizione:
// In questo laboratorio si considera il tipo di dato Albero binario dove i nodi sono numeri interi positivi.
// Un'albero binario e' un albero con radice dove ogni nodo ha al piu' due figli

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:
    
#include <iostream>
#include <string>

using namespace std;

// Implementa Albero binario con strutture collegate (Nodo) mediante puntatori e Label dotata di ordinamento
namespace tree {

    typedef int Label;
    struct Nodo;
    typedef Nodo* Tree; // un albero e' identificato dal puntatore alla sua radice
    const Tree alberoVuoto = NULL;
  
    // Costruisce albero vuoto
    Tree creaAlberoVuoto();
    
    // Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
    bool vuoto(const Tree& t);
    
    // Aggiunge nodo radice, fallisce se l'albero e' non vuoto
    bool inserisciRadice(const Label l, Tree& t);
    
    // Aggiunge nuovo nodo sinistro di un nodo esistente. Ritorna false se non esiste il nodo 'questo' nell'albero o se la label 'nome_figlio_sx' e' gia' presente nell'albero
    bool inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t);
    
    // Aggiunge nuovo nodo destro di un nodo esistente. Ritorna false se non esiste il nodo 'questo' nell'albero o se la label 'nome_figlio_dx' e' gia' presente nell'albero
    bool inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t);
  
    // Restituisce il massimo tra i valori delle etichette presenti nell'albero. Se l'albero e' vuoto restituisce -1
    int getMaxLabel(const Tree& t);

    // Stampa il contenuto dell'albero usando visita in profondita' simmetrica. Se l'albero e' vuoto stampa la stringa 'Albero vuoto'
    void stampaDFS(const Tree& t);

    // Inserisce un nodo con etichetta 'nome_figlio_sx' come figlio sinistro del nodo che ha etichetta massima nell'albero. Se l'albero e' vuoto restituisce false
    bool inserisciFiglioSXMax(Label nome_figlio_sx, Tree& t);
}

using namespace tree;

// il nodo di un albero e' caratterizzato dall'etichetta (in questo caso un intero),
// il puntatore al figlio sinistro e il puntatore al figlio destro
struct tree::Nodo {
    Label label;
    Nodo *sinistro;
    Nodo *destro;
};

/*******************************************************************************************************/
// Funzioni ausiliarie
/*******************************************************************************************************/

// Data un'etichetta l crea il nodo con quella etichetta e ne restituisce il puntatore
Nodo* createNode(const Label l) {
    Nodo* t = new Nodo;
    t->label = l;
    t->sinistro = t->destro = NULL;
    return t;
}

// Data un'etichetta l e un albero t (ovvero, un albero la cui radice
// e' il nodo puntato da t), restituisce il puntatore al nodo dell'albero t che ha quell'etichetta
// (NULL se nessun nodo ha quell'etichetta)
Nodo* getNode(const Label l, const Tree& t) {
    // se l'albero e' vuoto restituisco il nodo vuoto
    if (vuoto(t))
        return alberoVuoto;
  
    // se l'etichetta dell'albero e' quella cercata, restituisco t
    if (t->label == l)
        return t;
        
    // cerca nei figli
    Nodo* aux = alberoVuoto;
 
    if (!vuoto(t->sinistro)) aux = getNode(l, t->sinistro);
    if (!vuoto(aux)) return aux;
    if (!vuoto(t->destro)) aux = getNode(l, t->destro);
    if (!vuoto(aux)) return aux;
    // non trovato!
    return NULL;
}


// INSERIRE QUI EVENTUALI VOSTRE FUNZIONI AUSILIARIE



/*******************************************************************************************************/
// Funzioni relative all'albero binario
/*******************************************************************************************************/

// Costruisce l'albero vuoto
Tree tree::creaAlberoVuoto() {
   return alberoVuoto;
}

// Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
bool tree::vuoto(const Tree& t) {
   return (t==alberoVuoto);
}

// Aggiunge il nodo radice, fallisce se l'albero e' non vuoto o se l'etichetta e' minore di zero
bool tree::inserisciRadice(const Label l, Tree& t) {
    if(l < 0)
        return false;
    
    if (!vuoto(t)) return false;
    t = createNode(l);  // crea il nodo; t che era vuoto diventa l'albero con il solo nodo appena creato
    return true;
}

// Aggiunge nuovo nodo sinistro di un nodo esistente
// Ritorna false se non esiste il nodo 'questo' nell'albero, se la label 'nome_figlio_sx' e' gia' presente nell'albero o se e' minore di zero
bool tree::inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t) {
    if(nome_figlio_sx < 0)
        return false;
    Tree q = getNode(questo, t);
    if (vuoto(q)) return false;
    Tree sx = getNode(nome_figlio_sx, t);
    if (!vuoto(sx)) return false;
    Tree nuovo = createNode(nome_figlio_sx);
    q->sinistro = nuovo;
    return true;
}

// Aggiunge nuovo nodo destro di un nodo esistente
// Ritorna false se non esiste il nodo 'questo' nell'albero, se la label 'nome_figlio_dx' e' gia' presente nell'albero o se e' minore di zero
bool tree::inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t) {
    if(nome_figlio_dx < 0)
        return false;
    Tree q = getNode(questo, t);
    if (vuoto(q)) return false;
    Tree dx = getNode(nome_figlio_dx, t);
    if (!vuoto(dx)) return false;
    Tree nuovo = createNode(nome_figlio_dx);
    q->destro = nuovo;
    return true;
}


/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE */

/* Sviluppare le TRE seguenti funzioni C/C++:

   1) stampaDFS() Stampa il contenuto dell'albero usando visita in profondita' simmetrica. Se l'albero e'
      vuoto stampa 'Albero vuoto'
      Ad esempio un'albero formato da 4 nodi in cui abbiamo alla radice '1' con i figli '2' (figlio sinistro) e '3' 
      (figlio destro) e di cui '4' e' figlio sinistro di '2' sara' stampato nel seguente modo:
        
      4 2 1 3
    
      Se l'albero e' vuoto questa funzione deve stampare la stringa 'Albero vuoto'. Si suggerisce di 
      implementare una funziona ricorsiva.
      
   2) getMaxLabel() Restituisce il massimo tra i valori delle etichette presenti nell'albero. Se l'albero e' 
      vuoto restituisce -1
      
   3) inserisciFiglioSXMax() che inserisce un nodo nell'albero come figlio SINISTRO del nodo con etichetta MASSIMA. 
      L'eventuale nodo o sottoalbero presente a sinistra del nodo con etichetta massima, prima della chiamata della 
      funzione, sara' cancellato. 
      Nel caso l'albero sia vuoto la funzione deve ritornare false (altrimenti true).
     
      Ad esempio: per un albero formato da 3 nodi in cui abbiamo alla radice '1' con i figli '2' (figlio sinistro) 
      e '3' (figlio destro), la chiamata della funzione inserisciFiglioSXMax per inserire il nodo con etichetta 5 
      avra' come effetto l'inserimento del figlio sinistro nel nodo di etichetta 3
      
*/

// Stampa l'albero usando visita in profondita' simmetrica. Se l'albero e' vuoto stampa 'Albero vuoto'

void tree::stampaDFS(const Tree& t) {
    if (t == nullptr) {
        cout << "Albero vuoto" << endl;
        return;
    }
    
    if (t -> sinistro) {
        stampaDFS(t -> sinistro);
    }
    cout << t -> label << " "; 
    if (t -> destro) {
        stampaDFS(t -> destro);
    }
}

// Restituisce il massimo tra i valori delle etichette presenti nell'albero. Se l'albero e' vuoto restituisce -1

int tree::getMaxLabel(const Tree& t) {
    if (vuoto(t)) {
        return -1;
    }

    int max = 0;

    if (t -> label < t -> destro -> label) {
        max = t -> destro -> label;
        getMaxLabel(t -> destro);
    } else {
        max = t -> label;
    }

    return max;
}

// Inserisce un nodo con etichetta 'nome_figlio_sx' come figlio sinistro del nodo che ha etichetta 
// massima nell'albero e in questo caso restituisce true. Se l'albero e' vuoto restituisce false
bool tree::inserisciFiglioSXMax(Label nome_figlio_sx, Tree& t) {
    if (vuoto(t)) {
        return false;
    }

    int maxLabel = getMaxLabel(t); 
    
    
}


int main() {
    // creazione albero binario
    Tree t = creaAlberoVuoto();
    // inserimento di nodi in un albero binario
    inserisciRadice(10, t); // inseriamo la radice
    inserisciFiglioSX(10, 8, t);
    inserisciFiglioDX(10, 7, t);
    inserisciFiglioSX(8, 3, t);
    inserisciFiglioDX(8, 5, t);
    inserisciFiglioSX(7, 1, t);
    
    cout << "***** PROVA DI ESAME DI LABORATORIO DI ASD" << endl;
    cout << endl;
    cout << "*** PRIMA FUNZIONE *** " << endl;
    cout << "IL TEST E' CORRETTO SE LE DUE STAMPE SONO UGUALI" << endl;
    cout << "--- risultato corretto" << endl;
    cout << "3 8 5 10 1 7" << endl;
    
    cout << "--- stampa della funzione implementata da te" << endl;
    stampaDFS(t);
    cout << endl << endl;
    
    cout << "*** SECONDA FUNZIONE *** " << endl;
    int maxval = getMaxLabel(t);
    cout << "valore massimo calcolato dalla tua funzione (dovrebbe essere 10) = " << maxval << endl;
    if (maxval == 10)
        cout << "TEST PASSATO" << endl;
    else
        cout << "TEST FALLITO" << endl;
    cout << endl;
     
    cout << "*** TERZA FUNZIONE *** " << endl;
    inserisciFiglioSXMax(2, t);
    maxval=10;
    if(getNode(maxval, t)->sinistro->label == 2)
        cout << "TEST PASSATO" << endl;
    else
        cout << "TEST FALLITO" << endl;
    cout << "risultato dopo l'esecuzione di inserisciFiglioSXMax() " << endl;
    stampaDFS(t);
    cout << endl;
}
