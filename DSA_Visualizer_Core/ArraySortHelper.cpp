#include "Array.h"
#include <iostream>
using namespace std;

void Array::mergeHelper(int l, int mid, int h) {
	vector<int> left(mid - l + 1), right(h - mid);

	for (int i = 0; i < left.size(); i++)
		left[i] = arr[l + i];

	for (int i = 0; i < right.size(); i++)
		right[i] = arr[mid + i + 1];

	int i = 0, j = 0, k = l;
	while (i < left.size() && j < right.size()) {
		if ((isAscending ? (left[i] <= right[j]) : (left[i] >= right[j])))
			arr[k] = left[i++];

		else if ((isAscending ? (right[j] <= left[i]) : (right[j] >= left[i])))
			arr[k] = right[j++];

		k++;
	}

	while (i < left.size()) arr[k++] = left[i++];
	while (j < right.size()) arr[k++] = right[j++];

	logger.logState(arr, "After Merge [" + to_string(l) + "-" + to_string(h) + "]");
}

void Array::randomizePivot(int l, int h, bool useLomuto) {
	int pivotIndex = l + rand() % (h - l + 1);

	if (useLomuto) swap(arr[h], arr[pivotIndex]);
	else swap(arr[l], arr[pivotIndex]);
}

int Array::lomutoPartition(int l, int h) {
	int pivot = arr[h];
	int i = l - 1;

	for (int j = l; j < h; j++) {
		bool condition = isAscending ? (arr[j] < pivot) : (arr[j] > pivot);
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
		do i++; while (isAscending ? (arr[i] < pivot) : (arr[i] > pivot));
		do j--; while (isAscending ? (arr[j] > pivot) : (arr[j] < pivot));

		if (i >= j) return j;
		swap(arr[i], arr[j]);
	}
}