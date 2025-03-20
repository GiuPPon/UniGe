#include <string>

using namespace std;

namespace bag {
    typedef int Elem;
    struct Node;
    typedef Node *Bag;

    // crea una nuova bag vuota
    Bag createEmpty();

    // dice se una bag è vuota
    bool isEmpty(const Bag);

    // inserisce un elemento nella bag
    void insert(Bag &, Elem);

    // stampa gli elementi della bag in ordine crescente, separati da spazi
    // non è necessario andare a capo a fine linea
    void printInOrder(const Bag);

    // restituisce true se e solo se esiste nella bag un valore più piccolo di v
    bool hasLowerValue(const Bag, Elem v);

    // restituisce il numero di elementi uguali a v
    unsigned int countEqual(const Bag, Elem v);
}