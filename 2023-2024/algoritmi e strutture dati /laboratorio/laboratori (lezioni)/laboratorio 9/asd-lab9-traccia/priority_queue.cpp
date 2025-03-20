/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "priority_queue.h"


// Funzioni ausiliarie che non appartengono al TDD 

// tra i due indici, restituisce quello che corrisponde al timestamp inferiore
int minTimeStamp(priorityQueue::PriorityQueue pq, int index1, int index2)
{
  if (index1 >= pq.size && index2 >= pq.size)
    // entrambi gli indici sono fuori dal limite dello heap
    return -1; 
  if (index1 >= pq.size)
    // il primo e' fuori, restituisco il secondo
    return index2;
  if (index2 >= pq.size)
    // il secondo e' fuori, restituisco il primo
    return index1;
      
  // entrambi sono dentro lo heap, scelgo quello con timestamp inferiore
  if (pq.data[index1].timeStamp < pq.data[index2].timeStamp)
    return index1; 
    else return index2;
}

void swap(priorityQueue::PriorityQueue &pq, int pos1, int pos2) {
  priorityQueue::Elem aux = pq.data[pos1];
  pq.data[pos1] = pq.data[pos2];
  pq.data[pos2] = aux;
}

void moveUp(priorityQueue::PriorityQueue &pq, int index) {
  while (index > 0) {
    int parentIndex = (index - 1) / 2;      // formula data
    if (pq.data[index].timeStamp >= pq.data[parentIndex].timeStamp) {      // pq.data[index] >= pq.data[parentIndex]
      break;                               // esce perche non deve swappare
    }
    swap(pq, index, parentIndex);          
    index = parentIndex;                   // index diventa il padre e ricomincia il ciclo
  }  
}

void moveDown(priorityQueue::PriorityQueue &pq, int index) {
  int leftChild = 2 * index + 1;        // formula data
  int rightChild = 2 * index + 2;       // formula data
  int smallest = index;             // partiamo con radice come smallest [0]

  // leftChild < pq.size (l'elemento esiste) e leftchild è minore dello smallest
  if (leftChild < pq.size && pq.data[leftChild].timeStamp < pq.data[smallest].timeStamp) { 
    smallest = leftChild;                   // il nuovo smallest è leftChild
  }

  // rightChild < pq.size (l'elemento esiste) e rightchild è minore dello smallest
  if (rightChild < pq.size && pq.data[rightChild].timeStamp < pq.data[smallest].timeStamp) {
    smallest = rightChild;                 // il nuovo smallest è rightChild
  }

  if (smallest != index) {
    swap (pq, index, smallest);
    moveDown(pq, smallest);         // controllo di nuovo partendo da smallest
  }
}

// Funzioni del TDD PriorityQueue

// crea una PriorityQueue di dimensione dim
priorityQueue::PriorityQueue priorityQueue::createEmptyPQ(int dim) {
  PriorityQueue pq;
  pq.size = 0;
  pq.maxsize = dim;
  pq.data = new Elem[pq.maxsize];
  return pq;
}

// verifica se una PriorityQueue e' vuota
bool priorityQueue::isEmpty(const PriorityQueue &pq) {
  return (pq.size == 0);
} 

// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna TRUE
// nel caso in cui la PriorityQueue sia piena ritorna FALSE
// suggerimento: inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::insert(PriorityQueue &pq, const Elem &elem) {
  if (pq.size == pq.maxsize) {
    return false;
  }

  ++pq.size;
  pq.data[pq.size - 1] = elem;
  moveUp(pq, pq.size);
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool priorityQueue::findMin(const PriorityQueue &pq, Elem &res) {
  if (isEmpty(pq)) {
    return false;
  }
  res = pq.data[0];    // ritorna la radice
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::deleteMin(PriorityQueue &pq) {  
  if (isEmpty(pq)) {
    return false;
  }
  pq.data[0] = pq.data[pq.size - 1];    // sovrascrivo la radice con l'ultimo elemento inserito
  --pq.size;                            // elimino l'ultimo elemento decrementando la size
  moveDown(pq, 0);
  return true;
}