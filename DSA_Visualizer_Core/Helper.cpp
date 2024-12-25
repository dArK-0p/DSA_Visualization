#include "Helper.h"
#include <iostream>
using namespace std;

int getLength() {
    int choice;
    cout << "Choose length:\n";
    cout << "1: 10\n2: 50\n3: 100\n4: 500\n5: 1000\n";
    cin >> choice;
    switch (choice) {
    case 1: return 10;
    case 2: return 50;
    case 3: return 100;
    case 4: return 500;
    case 5: return 1000;
    default: return 50;
    }
}

void getSortTechniqueAndOrder(char* sortTechniqueAndOrder) {
    int choice;
    cout << "Choose sorting technique:\n";
    cout << "1: Bubble Sort\n2: Selection Sort\n3: Insertion Sort\n";
    cout << "4: Merge Sort\n5: Quick Sort\n";
    cin >> choice;
    switch (choice) {
    case 1: sortTechniqueAndOrder[0] = 'b'; break;
    case 2: sortTechniqueAndOrder[0] = 's'; break;
    case 3: sortTechniqueAndOrder[0] = 'i'; break;
    case 4: sortTechniqueAndOrder[0] = 'm'; break;
    case 5: sortTechniqueAndOrder[0] = 'q'; break;
    default: sortTechniqueAndOrder[0] = 'b';
    }

    cout << "Choose order: 1: Ascending, 2: Descending\n";
    cin >> choice;
    switch (choice) {
    case 1: sortTechniqueAndOrder[1] = 'a'; break;
    case 2: sortTechniqueAndOrder[1] = 'd'; break;
    default: sortTechniqueAndOrder[1] = 'a';
    }
}

bool getSearchTechniqueAndValue(int* val) {
    int choice;
    cout << "Choose Search Technique:\n";
    cout << "1. Linear Search\n2. Binary Search\n";
    cin >> choice;

    cout << "Enter element to Search: "; cin >> *val;

    return (choice == 1);
}