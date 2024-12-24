#include "Array.h"
#include <iostream>
#include <ctime>

using namespace std;

Array::Array(int size) {
	this->size = size;
	arr = new int[size];
	generateRandom();
	srand(time(0));
}

Array::~Array() {
	delete[] arr;
	arr = NULL;
}

void Array::generateRandom() {
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

	sortAscending = (order == 'a') ? true : false;

    switch (sort_type) {
    case 'b': bubbleSort();					break;
    case 's': selectionSort();				break;
    case 'i': insertionSort();				break;
    case 'm': mergeSort(0, size - 1);		break;
    case 'q': quickSort(0, size - 1, false); break;
    default:  cerr << "Invalid sort type!" << endl;
    }
	printArray();
}

void Array::bubbleSort() {
	bool swapFlag;

	for (int i = 0; i < size - 1; i++) 
	{
		swapFlag = false;
		for (int j = 0; j < size - (i + 1); j++) {
			if ( (sortAscending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1])) ) {
				swapFlag = true;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (!swapFlag) break;
		printArray();
	}
}

void Array::selectionSort() {
	int targetIndex;

	for (int i = 0; i < size - 1; i++)
	{
		targetIndex = i;
		for (int j = i + 1; j < size ; j++) {
			if ( (sortAscending ? (arr[j] < arr[targetIndex]) : (arr[j] > arr[targetIndex])) )
				targetIndex = j;
		}
		swap(arr[targetIndex], arr[i]);
		printArray();
	}
}

void Array::insertionSort() {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while ( j >= 0 && (sortAscending ? (arr[j] > key) : (arr[j] < key)) ) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		printArray();
	}
}

void Array::mergeHelper(int low, int mid, int high) {
	int llen = mid - low + 1, rlen = high - mid;
	int *left = new int[llen], *right = new int[rlen];

	for (int i = 0; i < llen; i++)
		left[i] = arr[low + i];

	for (int i = 0; i < rlen; i++)
		right[i] = arr[mid + i + 1];

	int i = 0, j = 0, k = low;
	while (i < llen && j < rlen) {
		if ( (sortAscending ? (left[i] <= right[j]) : (left[i] >= right[j])) ) 
			arr[k] = left[i++];

		else if ( (sortAscending ? (right[j] <= left[i]) : (right[j] >= left[i])) )
			arr[k] = right[j++];

		k++;
	}

	while (i < llen) arr[k++] = left[i++];
	while (j < rlen) arr[k++] = right[j++];

	delete[] left;
	delete[] right;
}

void Array::mergeSort(int left, int right) {
	if (right > left) {
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		mergeHelper(left, mid, right);
		printArray();
	}
}

void Array::randomizePivot(int l, int h, bool useLomuto) {
	int pivotIndex = l + rand() % (h - l + 1);
	if(useLomuto) swap(arr[h], arr[pivotIndex]);
	else swap(arr[h], arr[pivotIndex]);
}

int Array::lomutoPartition(int l, int h) {
	int pivot = arr[h];
	int i = l - 1;

	for (int j = l; j < h; j++) {
		bool condition = sortAscending ? (arr[j] < pivot) : (arr[j] > pivot);
		if (condition) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return i + 1;
}

int Array::hoarePartition(int l, int h) {
	int pivot = arr[l];
	int i = l - 1, j = h + 1;

	while (true) {
		do i++; while (sortAscending ? (arr[i] < pivot) : (arr[i] > pivot));
		do j--; while (sortAscending ? (arr[j] > pivot) : (arr[j] < pivot));

		if (i >= j) return j;
		swap(arr[i], arr[j]);
	}
}

void Array::quickSort(int l, int h, bool useLomuto) {
	if (l >= h) return;

	randomizePivot(l, h, useLomuto);

	int partitionPoint = (useLomuto) ? lomutoPartition(l, h) : hoarePartition(l, h);
	
	printArray();

	if(useLomuto) quickSort(l, partitionPoint - 1, useLomuto);
	else quickSort(l, partitionPoint, useLomuto);

	quickSort(partitionPoint + 1, h, useLomuto);
}
