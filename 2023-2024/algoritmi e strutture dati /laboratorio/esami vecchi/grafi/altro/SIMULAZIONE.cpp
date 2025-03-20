/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 2) */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo i Grafi orientati pesati implementati con le matrici di adiacenza.
// Il peso di un arco e' sempre un numero intero maggiore di zero. Il valore zero e' invece usato per rappresentare l'assenza di un arco.
//
// Ad esempio la seguente matrice di adiacenza:
// 0 2 0
// 0 0 3
// 0 0 0
//
// rappresenta il seguente grafo con tre vertici: 0 -> 1 -> 2
//
// dove l'arco tra i vertici 0 e 1 ha peso 2 e l'arco tra i vertici 1 e 2 ha peso 3

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME: 
// MATRICOLA: 

#include <iostream>
using namespace std;

/************************************************************************************/
/*      Grafo pesato orientato implementato con una matrice di adiacenza            */
/************************************************************************************/

// per semplicita' non abbiamo usato i namespace per avere information hiding

typedef int VerticeID;
const int maxNumVertici = 50; // al massimo e' possibile creare Grafi con numero di vertici uguale a maxNumVertici
const int elementoInesistente = -1;
const int arcoNonPresente = 0; // lo zero e' usato per rappresentare l'assenza di un arco
typedef int Peso;

/* Un grafo pesato e' implementato con una struct che contiene il numero di vertici del grafo (numVertici) e una matrice di adiacenza (matrice). 
   Nella matrice un valore p (> 0) in posizione 'i' e 'j' indica che il grafo ha un arco da 'i' a 'j' con peso p 
*/
typedef struct { 
  int numVertici;
  Peso matrice[maxNumVertici][maxNumVertici];
} Grafo;

typedef VerticeID Cammino[maxNumVertici]; // definiamo un cammino (di vertici) come un array di vertici


/************************************************************************************/
/*      Operazioni sui Grafi gia' implementate                                      */
/************************************************************************************/

/* Inizializza la matrice maxNumVertici x maxNumVertici associata al grafo con tutti valori uguali alla costante 'elementoInesistente'
e crea un grafo di dimensione n */
Grafo creaGrafo(const int n) {
   Grafo g;
   for(int i=0; i<maxNumVertici; ++i)     // inizializzo tutta la matrice a elementoInesistente
         for(int j=0; j<maxNumVertici; ++j)
            g.matrice[i][j] = elementoInesistente;
   g.numVertici = n;
   for(int i=0; i<g.numVertici; ++i)     // inizializzo la parte di matrice che corrisponde al grafo di dimensione n
         for(int j=0; j<g.numVertici; ++j)
            g.matrice[i][j] = arcoNonPresente;
   return g;
}

/* Aggiunge un arco tra i due vertici passati come argomento, con peso passato come quarto parametro; restituisce false nei seguenti casi: 
 1) se uno dei due vertici non ha un indice ammissibile (l'indice deve essere compreso tra 0 e il numero di vertici del grafo-1)
 2) se il peso e' negativo
 3) se i due vertici sono identici (sulla diagonale devono esserci tutti zeri) */
bool aggiungiArco(Grafo& g, VerticeID v1, VerticeID v2, Peso p) {  
  if (0<=v1 && v1<g.numVertici && 0<=v2 && v2<g.numVertici && p>=0 && v1 != v2) {
    g.matrice[v1][v2] = p; 
    return true;
  }
  else
   return false;
} 

/* Ritorna il peso dell'arco (i, j)*/
int ritornaPeso(Grafo g, int i, int j) {
    return g.matrice[i][j];
}

/* Stampa il grafo sotto forma di matrice di adiacenza*/
void stampaGrafo(Grafo g) {
  for(int i=0; i<g.numVertici; ++i) {
      for(int j=0; j<g.numVertici; ++j)
         cout << g.matrice[i][j] << "\t";
      cout << endl;
  }
} 

/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

/* Sviluppare le tre seguenti funzioni C/C++:

   1) ritornaVerticeAventeGradoMin(const Grafo& g)
      
   2) camminoNelGrafoDecrescente(const Grafo& g, const int& l, const Cammino C)
   
   3) contaSink(Grafo& g)
   
   La cui specifica testuale e' data sotto forma di commento direttamente sopra alla loro definizione
*/

/* Calcola e restituisce il vertice (o un vertice nel caso ce ne siano diversi con valore uguale) avente grado uscente minimo 
(ossia il vertice avente minimo numero di archi uscenti) */
int ritornaVerticeAventeGradoMin(const Grafo& g) {

}


/*  Verifica se nel grafo g esiste un cammino di nodi C monotono decrescente, ovvero se � possibile
 attraversare il grafo seguendo il cammino C ed incontrando pesi sempre via via (strettamente) decrescenti.
 In caso questo avviene la funzione restituisce true, altrimenti false
 Se il grafo e' vuoto la funzione deve restituire false */
bool camminoNelGrafoDecrescente(const Grafo& g, const int& l, const Cammino C) {
    
}

/* Conta e restituisce il numero dei sink presenti nel grafo g
 Un sink in un grafo � un vertice che non ha archi uscenti (cioe' un vertice senza outgoing edges)*/
int contaSink(Grafo& g) { 
    
}

int main() {   
  Grafo g;
  // creo un grafo di dimensione 5
  g = creaGrafo(5);
  aggiungiArco(g, 0, 1, 1);
  aggiungiArco(g, 1, 2, 4);
  aggiungiArco(g, 1, 3, 6);
  aggiungiArco(g, 2, 1, 8);
  aggiungiArco(g, 3, 0, 2);
  aggiungiArco(g, 3, 4, 1);
  
  cout << "E' stato inserito il seguente grafo:" << endl;
  stampaGrafo(g);
  cout << endl;
  
  cout << "*** PRIMA FUNZIONE *** " << endl;
  if (ritornaVerticeAventeGradoMin(g)==4) cout << "TEST ritornaVerticeAventeGradoMin PASSATO" << endl;
  else cout << "TEST ritornaVerticeAventeGradoMin FALLITO" << endl;
  cout << endl;
  
  cout << "*** SECONDA FUNZIONE *** " << endl;
  Cammino C1 = {1, 3, 0, 2};
  Cammino C2 = {0, 1, 3, 4};
  bool b3 = camminoNelGrafoDecrescente(g, 3, C1);
  if(b3)
        cout << "TEST 1 camminoNelGrafoDecrescente PASSATO" << endl;
  else
        cout << "TEST 1 camminoNelGrafoDecrescente FALLITO" << endl;
  bool b4 = camminoNelGrafoDecrescente(g, 4, C2);
  if(!b4)
        cout << "TEST 2 camminoNelGrafoDecrescente PASSATO" << endl;
   else
        cout << "TEST 2 camminoNelGrafoDecrescente FALLITO" << endl;
  cout << endl;
  
  cout << "*** TERZA FUNZIONE *** " << endl;
  if (contaSink(g) == 1) cout << "TEST contaSink PASSATO" << endl;
  else cout << "TEST contaSink FALLITO" << endl;
  cout << endl;

  return 0;
}