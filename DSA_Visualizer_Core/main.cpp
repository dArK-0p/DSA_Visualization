#include "Array.h"
#include "Helper.h"
#include <iostream>

int main() {
    Array array(getLength());

    cout << "Choose:\n1. Sorting\n2. Searching\n";
    int choice; cin >> choice;

    if (choice == 1) {
        char sortingTechniqueAndOrder[2];
        getSortTechniqueAndOrder(sortingTechniqueAndOrder);

        array.sortArray(sortingTechniqueAndOrder[0], sortingTechniqueAndOrder[1]);
    }
    else {
        int ele;
        bool useLinear = getSearchTechniqueAndValue(&ele);

        std::cout << array.searchArray(ele, useLinear);
    }
    return 0;
}