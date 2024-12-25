#include "Array.h"

int Array::linearSearch(int value) {
	int index = -99;

	for (int i = 0; i < arr.size(); i++)
	{
		logger.logState(arr, "Checking index " + std::to_string(i));

		if (arr[i] == value) {
			index = i;
			break;
		}
	}

	if (index == -99) {
		logger.logState(arr, "Value not found");
		return -1;
	}

	logger.logState(arr, "Value found at index " + std::to_string(index));
	return index;
}

int Array::binarySearch(int l, int h, int value) {
	if (l > h) {
		logger.logState(arr, "Value not found in range [" + std::to_string(l) + "-" + std::to_string(h) + "]");
		return -1;
	}

	int mid = (l + h) / 2;

	std::vector<int> currentSubarray(arr.begin() + l, arr.begin() + h + 1);
	logger.logState(currentSubarray, "Checking middle index " + std::to_string(mid));

	bool condition = (isAscending) ? arr[mid] > value : arr[mid] < value;

	if (arr[mid] == value) {
		logger.logState(arr, "Value found at index " + std::to_string(mid));
		return mid;
	}
	else if (condition) return binarySearch(l, mid - 1, value);
	else return binarySearch(mid + 1, h, value);
}