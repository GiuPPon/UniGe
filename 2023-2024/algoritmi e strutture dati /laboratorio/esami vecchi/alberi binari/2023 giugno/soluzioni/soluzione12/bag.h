namespace bag {
    typedef int Elem;
    struct Node;
    typedef Node *Bag;

    // crea una nuova bag vuota
    Bag createEmpty();

    // ci dice se una bag è vuota
    bool isEmpty(const Bag);

    // inserisce un elemento nella bag
    void insert(Bag &, Elem);

    // stampa gli elementi della bag in ordine decrescente, separati da spazi
    // non è necessario andare a capo a fine linea
    void printInReverseOrder(const Bag);

    // restituisce vero se l'elemento v esiste in due o più copie
    bool isDuplicate(const Bag, Elem v);

    // restituisce la somma di tutti gli elementi che hanno valore maggiore di v
    Elem sumLarger(const Bag, Elem v);

}