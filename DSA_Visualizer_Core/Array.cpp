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
	printArray();
    switch (sort_type) {
    case 'b': bubbleSort(order);			 break;
    case 's': selectionSort(order);			 break;
    case 'i': insertionSort(order);			 break;
    case 'm': mergeSort(0, size - 1, order); break;
    case 'q': quickSort(order);				 break;
    default:  cerr << "Invalid sort type!" << endl;
    }
	printArray();
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

void Array::mergeHelper(int low, int mid, int high, char order) {
	int llen = mid - low + 1, rlen = high - mid;
	int left[llen], right[rlen];

	for (int i = 0; i < llen; i++)
		left[i] = arr[low + i];

	for (int i = 0; i < rlen; i++)
		right[i] = arr[mid + i + 1];

	int i = 0, j = 0, k = low;
	while (i < llen && j < rlen) {
		if ( ((order == 'a') ? (left[i] <= right[j]) : (left[i] >= right[j])) ) 
			arr[k++] = left[i++];

		else if ( ((order == 'a') ? (right[j] <= left[i]) : (right[j] >= left[i])) )
			arr[k++] = right[j++];
	}

	while (i < llen) arr[k++] = left[i++];

	while (j < rlen) arr[k++] = right[j++];
}

void Array::mergeSort(int left, int right, char order) {
	if (right > left) {
		int mid = left + (right - left) / 2;
		mergeSort(left, mid, order);
		mergeSort(mid + 1, right, order);
		mergeHelper(left, mid, right, order);
		printArray();
	}
}

void Array::quickSort(char order) {
	cerr << "Quick Sort not implemented yet!" << endl;
}
