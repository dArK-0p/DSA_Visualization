#include "Array.h"
#include <iostream>
#include <ctime>

using namespace std;

Array::Array(int size) {
	this->size = size;
	arr = new int[size];
	generateRandom();
}

Array::~Array() {
	delete[] arr;
	arr = NULL;
}

void Array::generateRandom() {
	srand(time(0));
	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 500 + 1);
}

void Array::printArray() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Array::sortArray(char sort_type, char order) {
	cout << "Before Sort: "; printArray();
    switch (sort_type) {
    case 'b': bubbleSort(order);    break;
    case 's': selectionSort(order); break;
    case 'i': insertionSort(order); break;
    case 'm': mergeSort(order);     break;
    case 'q': quickSort(order);     break;
    default:  cerr << "Invalid sort type!" << endl;
    }
	cout << "After Sort: "; printArray();
}

void Array::bubbleSort(char order) {
	bool swapFlag;

	for (int i = 0; i < size - 1; i++) 
	{
		swapFlag = false;
		for (int j = 0; j < size - (i + 1); j++) {
			if ( ((order == 'a') ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1])) ) {
				swapFlag = true;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (!swapFlag) break;
		printArray();
	}
}

void Array::selectionSort(char order) {
	int targetIndex;

	for (int i = 0; i < size - 1; i++)
	{
		targetIndex = i;
		for (int j = i + 1; j < size ; j++) {
			if ( ((order == 'a') ? (arr[j] < arr[targetIndex]) : (arr[j] > arr[targetIndex])) )
				targetIndex = j;
		}
		swap(arr[targetIndex], arr[i]);
		printArray();
	}
}

void Array::insertionSort(char order) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while ( j >= 0 && ((order == 'a') ? (arr[j] > key) : (arr[j] < key)) ) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		printArray();
	}
}

void Array::mergeSort(char order) {
	cerr << "Merge Sort not implemented yet!" << endl;
}

void Array::quickSort(char order) {
	cerr << "Quick Sort not implemented yet!" << endl;
}
