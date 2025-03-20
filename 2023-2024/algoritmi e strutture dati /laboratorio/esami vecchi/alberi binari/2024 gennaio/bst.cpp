#include "bst.h"
#include <iostream>

bool insertElem(Dictionary& d, const Key k, const Value v) {
    if (d == emptyDictionary) {
        bstNode *node = new bstNode;
        node -> elem.value = v;
        node -> elem.key = k;
        node -> leftChild = nullptr;
        node -> rightChild = nullptr;
        d = node;
        return true;
    }

    if (d -> elem.key == k) {
        d -> elem.value = v;
        return true;
    }

    if (d -> elem.key > k) {
        return insertElem((d -> leftChild), k, v);
    } else {
        return insertElem((d -> rightChild), k, v);
    }

    return false;
}

// 29 dicembre

bool insertElem(Dictionary& d, const Key k, const Value v) {
    if (d == emptyDictionary) {
        bstNode *aux = new bstNode;
        aux -> elem.key = k;
        aux -> elem.value = v;
        aux -> leftChild == nullptr;
        aux -> rightChild == nullptr;
        return true;
    }

    if (d -> elem.key == k) {
        d -> elem.value = v;
        return true;
    }

    if (d -> elem.value > v) {
        insertElem(d -> leftChild, k, v);
    } else {
        insertElem(d -> rightChild, k, v);
    }

    return false;
}

Value search(const Dictionary& d, const Key k) {
    if (d == emptyDictionary) {
        return nullptr;
    }

    if (d -> elem.key == k) {
        return d -> elem.value;
    }

    if (d -> elem.key > k) {
        return search((d -> leftChild), k);
    } else {
        return search((d -> rightChild), k);
    }
}

Dictionary copy(const Dictionary& d) {
    if (d == emptyDictionary) {
        return nullptr;
    }

    Dictionary aux = new bstNode;
    aux -> elem = d -> elem;

    aux -> leftChild = copy(d -> leftChild);
    aux -> rightChild = copy(d -> rightChild);

    return aux;
}

// funzione ausiliare per delete elem, viene usata solo per il caso in cui il nodo ha due figli, mi sposto nel sottoalbero destro
Elem deleteMin(Dictionary& d) {
    if (d -> leftChild == nullptr) {
        Elem temp = d -> elem;
        Dictionary tempChild = d -> rightChild;
        delete d;
        d = tempChild;
        return temp;
    } else {
        return deleteMin (d -> leftChild);
    }

}

void deleteElem(Dictionary& d, const Key k) {
    // presupporre che d non è vuoto

    if (d -> elem.key == k) {
        // senza figli
        if (d -> leftChild == nullptr && d -> rightChild == nullptr) {
            delete d;
            d = nullptr;
        } else if (d -> leftChild != nullptr && d -> rightChild == nullptr) { // solo figlio sinistro
            Dictionary temp = d -> leftChild;
            delete d;
            d = temp;
        } else if (d -> leftChild == nullptr && d -> rightChild != nullptr) { // solo figlio sinistro
            Dictionary temp = d -> rightChild;
            delete d;
            d = temp;
        } else { // entrambi i figli
            d -> elem = deleteMin(d ->rightChild);
        }
    }

    if (d -> elem.key > k) {
        return deleteElem(d -> leftChild, k);
    } else {
        return deleteElem(d ->rightChild, k);
    }
}
