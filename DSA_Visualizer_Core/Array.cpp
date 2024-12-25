#include "Array.h"
#include <ctime>
#include "Logger.h"
#include <iostream>


Array::Array(int size) : arr(size), logger() {
	for (int& i : arr)
		i = rand() % 500 + 1;

	logger.logInitialMetadata(arr, size);
}

void Array::sortArray(char sortType, char order) {
	
	logger.logState(arr, "Initial Array");

	isAscending = (order == 'a');
	isSorted = true;

	string opName;

    switch (sortType) {
	case 'b': opName = "Bubble Sort"; bubbleSort();					break;
    case 's': opName = "Selection Sort"; selectionSort();				break;
    case 'i': opName = "Insertion Sort"; insertionSort();				break;
    case 'm': opName = "Merge Sort"; mergeSort(0, arr.size() - 1);		break;
    case 'q': opName = "Quick Sort"; quickSort(0, arr.size() - 1, false); break;
	default: opName = "N/A"; isSorted = false;
    }
	logger.logOperationMetadata(opName, (isAscending ? "Ascending" : "Descending"));
	logger.logState(arr, "Final Array");
	
}

int Array::searchArray(int val, bool useLinear) {
	int foundAt;
	string opName;

	if (useLinear) {
		opName = "Linear Search";
		logger.logState(arr, "Performing Linear Search for value " + std::to_string(val));
		foundAt = linearSearch(val);
	}
	else {
		opName = "Binary Search";
		if (!isSorted) {
			logger.logState(arr, "Array not sorted, sorting first using Quick Sort");
			logger.setLoggingEnabled(false); sortArray('q', 'a'); logger.setLoggingEnabled(true);
		}
		logger.logState(arr, "Performing Binary Search for value " + std::to_string(val));
		foundAt = binarySearch(0, arr.size() - 1, val);
	}

	logger.logOperationMetadata(opName);
	return foundAt;
}
