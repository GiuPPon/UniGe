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
        b = new Node {e, emptyTree, emptyTree};
    else if (e <= b->value)
        insert(b->left, e);
    else
        insert(b->right, e);
}


// FUNZIONI DA IMPLEMENTARE

// stampa gli elementi della bag in ordine decrescente, su un'unica linea, separati da spazi
// non è necessario andare a capo a fine linea
void bag::printInReverseOrder(const Bag b) {
    if (isEmpty(b)) {
        return;
    }

    if (b -> right != nullptr) {
        printInReverseOrder(b -> right);
    } 
    cout << b -> value << " ";  
    if (b -> left != nullptr) {
        printInReverseOrder(b -> left);
    } 
}

// restituisce vero se l'elemento v esiste in due o più copie
// NOTA: se un nodo padre ha un elemento uguale al suo nel suo sottoalbero, deve essere il suo figlio sinistro
bool bag::isDuplicate(const Bag b, Elem v) {
    if (b != nullptr) {
        // Se il valore del nodo corrente è uguale a v, dobbiamo verificare se ci sono duplicati nei sottoalberi
        if (b->value == v) {
            // Se troviamo un duplicato nel sottoalbero sinistro o destro, restituiamo true
            if ((b->left != nullptr && b->left->value == v) || (b->right != nullptr && b->right->value == v)) {
                return true;
            }
        }

        // Continuare la ricerca ricorsiva nel sottoalbero sinistro e destro
        return isDuplicate(b->left, v) || isDuplicate(b->right, v);
    }
    return false;  // Se l'albero è vuoto, non ci sono duplicati
}

// restituisce la somma di tutti gli elementi che hanno valore maggiore di v
Elem bag::sumLarger(const Bag b, Elem v)
{
     int sum = 0;
    
    if (b != nullptr) {
        sum += sumLarger(b -> left, v);

        if (b -> value > v) {
            sum += b -> value;
        }

       sum += sumLarger(b -> right, v);

    }

    return sum;
}
