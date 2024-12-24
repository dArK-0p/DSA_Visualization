#pragma once
class Array {

private:
	int* arr;
	int size;
	bool sortAscending;
	void generateRandom();
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void mergeSort(int, int);
	void quickSort(int, int, bool);
	
public:
	Array (int);
	~Array();

	void mergeHelper(int, int, int);
	int  lomutoPartition(int, int);
	int  hoarePartition(int, int);
	void randomizePivot(int, int, bool);
	void printArray();
	void sortArray(char, char);

};