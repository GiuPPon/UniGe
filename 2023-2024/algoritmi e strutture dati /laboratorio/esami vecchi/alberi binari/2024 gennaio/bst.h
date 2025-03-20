#ifndef DICTIONARY_BST_H
#define DICTIONARY_BST_H

#include <string>

typedef std::string Key;
typedef std::string Value;

struct Elem {
    Key key;
    Value value;
};

struct bstNode {
    Elem elem;
    bstNode* leftChild;
    bstNode* rightChild;
};

typedef bstNode* Dictionary;

const Dictionary emptyDictionary = nullptr;

bool insertElem(Dictionary& d, const Key k, const Value v);
Value search(const Dictionary& d, const Key k);
Dictionary copy(const Dictionary& d);
void deleteElem(Dictionary& d, const Key k);

#endif // DICTIONARY_BST_H
