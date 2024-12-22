#pragma once
class Array {

private:
	int* arr;
	int size;
	void generateRandom();
	void bubbleSort(char);
	void selectionSort(char);
	void insertionSort(char);
	void mergeSort(char);
	void quickSort(char);
public:
	Array (int);
	~Array();

	void printArray();
	void sortArray(char, char);

};