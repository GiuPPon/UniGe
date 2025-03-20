#include <string>
#include <cstddef>

typedef int Elem;

struct triNode{
  Elem el;
  triNode *child1;
  triNode *child2;
  triNode *child3;
};

typedef triNode *triTree;

const triTree emptyTriTree=nullptr;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di nodi nel albero che hanno come valore
//il valore dato in primo argomento
unsigned int nbOccurrence(Elem, const triTree&);

//Es 2
//Cancella tutti i nodi con valore uguale al primo argomento
//dal albero
void deleteAll(Elem, triTree&);

//Es 3
//Ritorna una string con le valore delle foglie del albero
//Separate da spazi visitate dalla sinistra alla destra
std::string leavesToString(const triTree&);
