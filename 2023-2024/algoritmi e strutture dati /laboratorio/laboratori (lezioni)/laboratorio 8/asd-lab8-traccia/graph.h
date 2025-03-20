#include <cstddef>
#include <string>         

#include "list-array.h"

using namespace std; 

namespace graph {
  typedef string Label; //etichetta dei vertici
  typedef unsigned int Weight; //peso degli archi

  struct vertexNode; // da definire nel file graph.cpp

  typedef vertexNode* Graph; // un grafo e' identificato dal puntatore al primo vertice inserito

  const Graph emptyGraph = nullptr;

  /**********************************************************************/
  /*               Funzione da implementare                             */
  /**********************************************************************/
  // Restituisce il grafo vuoto 
  Graph createEmptyGraph();

  // Aggiunge nuovo vertice con etichetta la stringa.
  // Se non e gia presente, ritorna true, altrimenti fallisce e ritorna false 
  bool addVertex(Label, Graph&);

  // Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
  // l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
  // tra i due e' gia' presente. Se fallisce ritorna false,
  // altrimenti ritorna true
  bool addEdge(Label, Label, Weight, Graph&);

  // Restituisce true se il grafo e' vuoto, false altrimenti
  bool isEmpty(const Graph&);

  // Ritorna il numero di vertici del grafo
  unsigned int numVertices(const Graph&);

  // Ritorna il numero di archi del grafo
  unsigned int numEdges(const Graph&);

  // Calcola e ritorna (nel secondo parametro) il grado del vertice.
  // Restituisce un valore falso se il vertice non esiste,
  // altrimenti ritorna true
  bool nodeDegree(Label, unsigned int&, const Graph&);

  // Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
  bool areAdjacent(Label, Label, const Graph&); 

  // Ritorna la lista di adiacenza di un vertice
  // corrispondente alla lista dei label dei vertici adiacenti
  list::List adjacentList(Label, const Graph&);

  // Calcola, se esiste, un cammino tra due vertici
  // Il primo argomento e il vertice di partenza
  // Il secondo argomento e il vertice di arrivo
  // Il terzo argomento sara la lista delle etichette degli
  // vertici visitati sul cammino (senza il vertice di partenza,
  // ma con il vertice di arrivo)
  // Si assume che il chiamante fornisca inizialmente una lista vuota.
  // Il quarto argomento e il peso del cammino
  // La funziona ritorna false se non c'e un cammino tra i due vertici
  // Se il vertice di partenza e uguale al vertice di arrivo, la funzione
  // ritorna true, e il peso e 0 e la lista e' vuota
  bool findPath(Label, Label, list::List&, Weight&, const Graph& g);

  // Svuota un grafo
  void clear(Graph&);

  // Stampa il grafo
  // Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
  // poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
  // separate da virgole
  void printGraph(const Graph&);
}

