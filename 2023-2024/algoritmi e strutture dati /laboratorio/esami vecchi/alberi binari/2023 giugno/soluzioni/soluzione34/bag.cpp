#include <iostream>

#include "bag.h"


using namespace bag;
using namespace std;

// DEFINIZIONE DELLA STRUTTURA DATI

const Bag emptyTree = nullptr;

struct bag::Node {
    Elem value;
    Node *left;
    Node *right;
};


// FUNZIONI FORNITE AGLI STUDENTI

// crea una nuova bag vuota
Bag bag::createEmpty()
{
    return emptyTree;
}

// dice se una bag è vuota
bool bag::isEmpty(const Bag b)
{
    return b == emptyTree;
}

// inserisce un elemento nella bag
void bag::insert(Bag &b, Elem e)
{
    if (isEmpty(b))
        // questa sintassi è equivalente a
        // b = new Node;
        // b->value = e;
        // b->left = b->right = emptyTree;
        b = new Node {e, emptyTree, emptyTree};
    else if (e == b->value)
        // garantiamo che gli elementi duplicati siano una catena di figli sinistri
        b = new Node {e, b, emptyTree};
    else if (e < b->value)
        insert(b->left, e);
    else
        insert(b->right, e);
}


// FUNZIONI CHE GLI STUDENTI DEVONO IMPLEMENTARE

// Stampa gli elementi della bag in ordine crescente, separati da spazi
// Non è necessario andare a capo a fine linea
void bag::printInOrder(const Bag b)
{

}

// Restituisce true se e solo se esiste nella bag un valore più piccolo di v
bool bag::hasLowerValue(const Bag b, Elem v)
{

}

// Restituisce il numero di elementi uguali a v
unsigned int bag::countEqual(const Bag b, Elem v)
{

}
