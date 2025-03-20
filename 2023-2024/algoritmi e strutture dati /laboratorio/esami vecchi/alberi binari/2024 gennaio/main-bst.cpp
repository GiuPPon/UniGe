#include <iostream>
#include "bst.h"

int main() {
    Dictionary dict = emptyDictionary;

    insertElem(dict, "key1", "value1");
    insertElem(dict, "key2", "value2");
    insertElem(dict, "key3", "value3");

    std::cout << "Value for key2: " << search(dict, "key2") << std::endl;

    Dictionary copyDict = copy(dict);
    std::cout << "Value for key2 in copied dictionary: " << search(copyDict, "key2") << std::endl;

    deleteElem(dict, "key2");
    std::cout << "Value for key2 after deletion: " << search(dict, "key2") << std::endl;

    return 0;
}
