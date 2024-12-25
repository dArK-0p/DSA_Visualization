#pragma once
#include "Logger.h"
class Array {

private:
	std::vector<int> arr;
	bool isAscending;
	bool isSorted;
	Logger logger;

public:
	void bubbleSort();
	void selectionSort();
	void insertionSort();

	void mergeSort(int, int);
	void quickSort(int, int, bool);

	int linearSearch(int);
	int binarySearch(int, int, int);

	Array (int);

	void mergeHelper(int, int, int);
	int  lomutoPartition(int, int);
	int  hoarePartition(int, int);
	void randomizePivot(int, int, bool);

	void sortArray(char, char);
	int searchArray(int, bool);
};