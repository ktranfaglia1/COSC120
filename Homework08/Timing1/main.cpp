#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);

void CopyArray(const int[], int[], int);
void printArray(int *array, int size, bool newline = false);

int main() {
	srand(time(0));
	int size = 0;

	cout << "Input array size: ";
	cin >> size;

	int A[size];
	int B[size];
	for (int i = 0; i < size; i++) {
		A[i] = rand();    //  Average
		//A[i] = i;         //  Best
		//A[i] = size - i;  //  Worst
	}

	CopyArray(A, B, size);

	auto start = high_resolution_clock::now();
	bubbleSort(A, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Bubble sort =     " << duration.count() / 1000000.0 << " seconds"
			<< endl;

	CopyArray(B, A, size);

	start = high_resolution_clock::now();
	selectionSort(A, size);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);

	cout << "Selection sort =  " << duration.count() / 1000000.0 << " seconds"
			<< endl;

	CopyArray(B, A, size);

	start = high_resolution_clock::now();
	insertionSort(A, size);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);

	cout << "Insertion sort =  " << duration.count() / 1000000.0 << " seconds"
			<< endl;

	CopyArray(B, A, size);

	start = high_resolution_clock::now();
	sort(A, A + size);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);

	cout << "Algorithm sort =  " << duration.count() / 1000000.0 << " seconds"
			<< endl;

	return 0;
}

void CopyArray(const int A[], int B[], int size) {
	for (int i = 0; i < size; i++)
		B[i] = A[i];
}

void bubbleSort(int array[], int size) {
	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement > 0; maxElement--)
		for (index = 0; index < maxElement; index++)
			if (array[index] > array[index + 1])
				swap(array[index], array[index + 1]);
}

void selectionSort(int array[], int size) {
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++) {
			if (array[index] < minValue) {
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void insertionSort(int array[], int size) {
	for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
		int temp = array[itemsSorted];
		int loc = itemsSorted - 1;
		while (loc >= 0 && array[loc] > temp) {
			array[loc + 1] = array[loc];
			loc = loc - 1;
		}
		array[loc + 1] = temp;
	}
}

void printArray(int array[], int size, bool newline) {
	for (int i = 0; i < size; i++) {
		cout << array[i];
		if (newline)
			cout << endl;
		else
			cout << "  ";
	}
	cout << endl;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

