#include "Array.h"
#include <iostream>
using namespace std;

void Array::bubbleSort() {
	bool swapFlag;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		swapFlag = false;
		for (int j = 0; j < arr.size() - (i + 1); j++) {
			if ((isAscending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]))) {
				swapFlag = true;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (!swapFlag) break;
		logger.logState(arr, "After Pass " + to_string(i + 1));
	}
}

void Array::selectionSort() {
	int targetIndex;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		targetIndex = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if ((isAscending ? (arr[j] < arr[targetIndex]) : (arr[j] > arr[targetIndex])))
				targetIndex = j;
		}
		swap(arr[targetIndex], arr[i]);
		logger.logState(arr, "After Pass " + to_string(i + 1));
	}
}

void Array::insertionSort() {
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && (isAscending ? (arr[j] > key) : (arr[j] < key))) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		logger.logState(arr, "After Pass " + to_string(i + 1));
	}
}

void Array::mergeSort(int l, int h) {
	if (h <= l) return;

	int mid = l + (h - l) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, h);

	vector<int> currentSubarray(arr.begin() + l, arr.begin() + h + 1);
	logger.logState(currentSubarray, "Current Subarray [" + to_string(l) + "-" + to_string(h) + "]");

	mergeHelper(l, mid, h);
}

void Array::quickSort(int l, int h, bool useLomuto) {
	if (l >= h) return;

	if(arr.size() > 2) randomizePivot(l, h, useLomuto);

	vector<int> currentPartition(arr.begin() + l, arr.begin() + h + 1);
	logger.logState(currentPartition, "Current Partition [" + to_string(l) + "-" + to_string(h) + "]");

	int partitionPoint = (useLomuto) ? lomutoPartition(l, h) : hoarePartition(l, h);

	logger.logState(arr, "After Partition [" + to_string(l) + "-" + to_string(h) + "]");

	if (useLomuto) quickSort(l, partitionPoint - 1, useLomuto);
	else quickSort(l, partitionPoint, useLomuto);

	quickSort(partitionPoint + 1, h, useLomuto);
}