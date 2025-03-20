#include <iostream>

#include "graph.h"

using namespace graph;

struct halfEdgeVertex {
  Label label;              // etichetta del vertice destinazione
  vertexNode *vertPrt;      // puntatore al vertice
  Weight weight;            // peso dell'arco
  halfEdgeVertex *next;     // puntatore al mezzo arco successivo
};

struct graph::vertexNode {
  Label label;              // etichetta del vertice
  halfEdgeVertex *adjList;  // puntatore alla lista dei mezzi archi adiacenti
  vertexNode *next;         // puntatore al prossimo vertice nella lista dei vertici
  bool isVisited;           // booleano per verificare se il vertice è stato visitato
};

/**********************************************************************/
/*               Funzione da implementare                             */
/**********************************************************************/
// Restituisce il grafo vuoto
Graph graph::createEmptyGraph(){
  return emptyGraph;
}

// Aggiunge nuovo vertice con etichetta la stringa.
// Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false 
bool graph::addVertex(Label l, Graph& g){
  vertexNode *aux = new vertexNode;
  aux -> label = l;
  aux -> adjList = nullptr;
  aux -> next = nullptr;
  aux -> isVisited = false;

  if (isEmpty(g)) {                    // caso base
    g = aux;
    return true;
  }

  vertexNode *cur = g;                // controllo di non essere nel caso label già presente
  while (cur != nullptr) { 
    if (cur -> label == l) {
      return false;
    }
    cur = cur -> next;
  }

  cur = g;
  while (cur -> next != nullptr) {
    cur = cur -> next;
  }
  cur -> next = aux;
  return true;
}

// Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente. Se fallisce ritorna false,
// altrimenti ritorna true
bool graph::addEdge(Label from, Label to, Weight w, Graph& g){
  vertexNode *nodo1 = nullptr;
  vertexNode *nodo2 = nullptr;

  vertexNode *cur = g;

  while (cur != nullptr) {
    if (cur -> label == from) {
      nodo1 = cur;
    }
    if (cur -> label == to) {
      nodo2 = cur;
    }
    cur = cur -> next;
  }

  if (nodo1 == nullptr || nodo2 == nullptr) {
    return false;
  }

  // controllo se esiste gia un arco
  // puntatore alla lista di adiacenza del nodo1
  halfEdgeVertex *arco = nodo1 -> adjList;

  while (arco != nullptr) {
    if (arco -> label == nodo2 -> label) {
      return false;
    }
    arco = arco -> next;
  }

  halfEdgeVertex *arco1 = new halfEdgeVertex;
  arco1 -> label = nodo2 -> label;    // assegno nodo2 perchè è quello di destinazione
  arco1 -> vertPrt = nodo2;           // vertice di destinazione
  arco1 -> weight = w;
  arco1 -> next = nodo1 -> adjList;
  nodo1 -> adjList = arco1;

  halfEdgeVertex *arco2 = new halfEdgeVertex;
  arco2 -> label = nodo1 -> label;
  arco2 -> vertPrt = nodo1;
  arco2 -> weight = w;
  arco2 -> next = nodo2 -> adjList;
  nodo2 -> adjList = arco2;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g){
  return g == emptyGraph;
}

// Ritorna il numero di vertici del grafo
unsigned int graph::numVertices(const Graph& g){
  unsigned int count = 0;
  if (isEmpty(g)) {
    return count;
  }

  vertexNode *cur = g;
  while (cur != nullptr) {
    ++count;
    cur = cur -> next;
  }
  return count;
}

// Ritorna il numero di archi del grafo
unsigned int graph::numEdges(const Graph& g){
  unsigned int count = 0;
  vertexNode *cur = g;
  while (cur != nullptr) {
    halfEdgeVertex *arco = cur -> adjList;
    while (arco != nullptr) {
      ++count;
      arco = arco -> next;
    }
    cur = cur -> next;
  }
  return count / 2;
}

// Calcola e ritorna (nel secondo parametro) il grado del vertice.
// Restituisce un valore falso se il vertice non esiste,
// altrimenti ritorna true
bool graph::nodeDegree(Label l, unsigned int& degree, const Graph& g) {
  vertexNode *cur = g;

  while (cur != nullptr) {
    if (cur -> label == l) {
      unsigned int count = 0;
      halfEdgeVertex *arco = cur -> adjList;
      while (arco != nullptr) {
        ++count;
        arco = arco -> next;
      }
      degree = count;
      return true;
    }
    cur = cur -> next;
  }
  degree = 0;
  return false;
}

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
  vertexNode *cur = g;
  while (cur != nullptr) {
    if (cur -> label == v1) {
      halfEdgeVertex *arco = cur -> adjList;
      while (arco != nullptr) {
        if (arco -> label == v2) {
          return true;
        }
        arco = arco -> next; 
      }
    }
    cur = cur -> next;
  }
  return false;
}

// Ritorna la lista di adiacenza di un vertice
// corrispondente alla lista dei label dei vertici adiacenti
list::List graph::adjacentList(Label v1, const Graph& g) {
  list::List auxList = list::createEmpty();
  vertexNode *cur = g;
  while (cur != nullptr) {
    if (cur -> label == v1) {
      halfEdgeVertex *arco = cur -> adjList;
      while (arco != nullptr) {
        list::addFront(arco -> label, auxList);
        arco = arco -> next;
      }
      return auxList;
    }
    cur = cur -> next;
  }
  return auxList;     // empty
}

// Calcola, se esiste, un cammino tra due vertici
// Il primo argomento e il vertice di partenza
// Il secondo argomento e il vertice di arrivo
// Il terzo argomento conterrà la lista delle etichette degli
// vertici visitati sul cammino (senza il vertice di partenza, ne il vertice
// di arrivo)
// Si assume che il chiamante fornisca inizialmente una lista vuota.
// Il quarto argomento è il peso del cammino
// La funziona ritorna false, se il vertice di partenza e uguale al vertice
// di arrivo, o se non c'e un cammino tra i due vertici, altrimenti
// ritorna true

// Funzione per trovare un vertice dato la sua etichetta
    vertexNode* getVertexNode(Label label, const Graph& g) {
        vertexNode* currentVertex = g;
        while (currentVertex != nullptr) {
            if (currentVertex->label == label) {
                return currentVertex;
            }
            currentVertex = currentVertex->next;
        }
        return nullptr;
    }

bool DFS(vertexNode* vertex, Label v2, list::List& path, Weight& weight, const Graph& g) {
    if (vertex == nullptr) {
        return false;
    }
    vertex->isVisited = true;
    if (vertex->label == v2) {
        return true;
    }
    halfEdgeVertex* adjEdge = vertex->adjList;
    while (adjEdge != nullptr) {
        vertexNode* adjVertex = getVertexNode(adjEdge->label, g);
        if (adjVertex != nullptr && !adjVertex->isVisited) {
            if (DFS(adjVertex, v2, path, weight, g))   {
                list::addFront(adjEdge->label, path);
                weight += adjEdge->weight;
                return true;
            }
        }
        adjEdge = adjEdge->next;
    }
    return false;
}

bool graph::findPath(Label v1, Label v2, list::List& path, Weight& weight, const Graph& g) {
  if (v1 == v2) {
        weight = 0;
        return true;
    }
    for (Graph aux = g; aux != emptyGraph; aux = aux->next) {
        aux->isVisited = false;
    }
    weight = 0;
    vertexNode* startVertex = getVertexNode(v1, g);
    if (startVertex == nullptr) {
        return false;
    }
    if (DFS(startVertex, v2, path, weight, g)) {
        return true;
    }
    return false;
}

// Svuota un grafo
void graph::clear(graph::Graph& g){
  while (g != nullptr) {
    vertexNode* temp = g;
    g = g -> next;

    // Libera la lista di adiacenza del vertice corrente
    halfEdgeVertex *adj = temp -> adjList;
    while (adj != nullptr) {
      halfEdgeVertex* tempAdj = adj;
      adj = adj -> next;
      delete tempAdj;
    }
    // Libera il vertice corrente
    delete temp;
  }
  // alla fine di tutto per evitare segmentation fault assegniamo g a emptyGraph
  g = emptyGraph;
}

// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void graph::printGraph(const graph::Graph& g) {
  vertexNode *cur = g;
  while (cur != nullptr) {
    cout << cur -> label << ":";
    halfEdgeVertex *adj = cur -> adjList;
    bool first = true;    // variabile per verificare se si tratta della testa del vertice
    while(adj != nullptr) {
      if (!first) {  // se non è la testa allora separiamo con la virgola
        cout << ", ";
      }
      cout << " " << adj -> label << "(" << adj -> weight << ")";
      first = false;
      adj = adj -> next;
    }
    cout << endl;
    cur = cur -> next;
  }
}
