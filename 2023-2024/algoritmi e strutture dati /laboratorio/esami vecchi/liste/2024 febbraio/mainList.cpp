#include <iostream>
#include "list.h"

int main() {
    List myList = {nullptr};

    insert_tail(myList, 5);
    insert_tail(myList, 10);
    insert_tail(myList, 15);
    insert_tail(myList, 20);

    std::cout << "Elements between 10 and 20: " << count_between(myList, 10, 20) << std::endl;

    if (remove(myList, 1)) {
        std::cout << "Element at position 1 removed successfully." << std::endl;
    } else {
        std::cout << "Failed to remove element at position 1." << std::endl;
    }

    std::cout << "Elements between 10 and 20: " << count_between(myList, 10, 20) << std::endl;

    return 0;
}
