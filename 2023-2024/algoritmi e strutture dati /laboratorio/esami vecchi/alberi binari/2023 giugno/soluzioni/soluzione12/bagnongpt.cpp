// SOSTITUIRE CON Nome Cognome Matricola

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


// crea una nuova bag vuota
Bag bag::createEmpty()
{
    return emptyTree;
}

// ci dice se una bag è vuota
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

// stampa gli elementi della bag in ordine decrescente, su un'unica linea, separati da spazi
// non è necessario andare a capo a fine linea
void bag::printInReverseOrder(const Bag b)
{
    if (isEmpty(b))
        return;
    printInReverseOrder(b->right);
    cout << b->value << " ";
    printInReverseOrder(b->left);
}

// restituisce vero se l'elemento v esiste in due o più copie
// NOTA: se un nodo padre ha un elemento uguale al suo nel suo sottoalbero, deve essere il suo figlio sinistro
bool bag::isDuplicate(const Bag b, Elem v)
{
    if (isEmpty(b))
        return false;
    if (v == b->value)
        // errore molto frequente: non controllare il figlio che il figlio sinistro non sia vuoto
        return (!isEmpty(b->left) && b->left->value == v);
    if (v < b->value)
        return isDuplicate(b->left, v);
    // se arriviamo qui, v > b->value
    return isDuplicate(b->right, v);
}

// funzione ausiliaria che calcola la somma di un sottoalbero:
// non strettamente necessaria in quanto sumLarger va bene, fa solo controlli superflui su b->value
Elem sum(const Bag b)
{
    if (isEmpty(b))
        return 0;
    return sum(b->left) + b->value + sum(b->right);
}

// restituisce la somma di tutti gli elementi che hanno valore maggiore di v
Elem bag::sumLarger(const Bag b, Elem v)
{
    if (isEmpty(b))
        return 0;
    if (b->value > v)
        // versione più semplice e solo minimamente meno efficiente:
        // sostituire sum(b->right) con sumLarger(b->right, v)
        return sumLarger(b->left, v) + b->value + sum(b->right);
    return sumLarger(b->right, v);
}
