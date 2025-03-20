#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 1
//Ritorna il numero di coppie nel albero
unsigned int nbPairs(const pairBstTree& pbst){

    // Se l'albero è vuoto (nullptr), ritorna 0
    if (pbst == nullptr) {
        return 0;
    }

    // Altrimenti, conta il nodo corrente (1) + il numero di nodi nel sottoalbero sinistro e destro
    return 1 + nbPairs(pbst->left1) + nbPairs(pbst->right1);

}
