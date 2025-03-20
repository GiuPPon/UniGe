#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "tragitto.h"  // serve per associare un tragitto a ciascun veicolo
using namespace tragitto;

namespace priorityQueue {

// Ciascun veicolo e' descritto con una serie di info
struct InfoVeicolo {
  string plate = "";                        // targa
  tragitto::Tragitto path = tragittoVuoto;  // tragitto da compiere
  float speed = 0;                          // velocita' media in km/h
  string location = "";                     // dove si trova attualmente
};

struct PQVeicoloElem {
  // nel dominio del problema affrontato, un elemento di una priority queue 
  // e' dato dalle informazioni del veicolo e dal tempo corrente
  InfoVeicolo *veicolo;     // informazioni sul veicolo
  float timeStamp;          // tempo attuale in minuti
};

typedef PQVeicoloElem Elem;      
// il tipo Elem coincide con PQVeicoloElem (la natura dell'elemento della priority
// queue potrebbe cambiare in altre implementazioni e in altri domini; 
// in questo modo le definizioni continueranno a fare riferimento a Elem) 

struct dynamicArray {   
    // struct "standard" per la rappresentazione
	// del TDD lista mediante array dinamico
    Elem* data;
    int size;
    int maxsize;
};

typedef dynamicArray PriorityQueue;  
// una coda con priorita' realizzata con uno heap si implementa con un array dinamico,
// ma possiamo per semplicita' trascurare il problema di allocazione e deallocazione: 
// assumiamo che lo heap venga creato con una certa dimensione passata come argomento 
// a createEmptyHeap e quella rimanga per tutta l'esecuzione del programma

// crea una PriorityQueue di dimensione dim
PriorityQueue createEmptyPQ(int);

// verifica se una PriorityQueue e' vuota
bool isEmpty(const PriorityQueue&);

// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna TRUE
// nel caso in cui la PriorityQueue sia piena ritorna FALSE
// suggerimento: inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool insert(PriorityQueue&, const Elem&);

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool findMin(const PriorityQueue&, Elem&);

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool deleteMin(PriorityQueue&);
}