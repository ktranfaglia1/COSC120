#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int&, int&);

void CopyArray(const int*, int*, int);
void printArray(int *array, int size, bool newline = false);

int main() {
	srand(time(0));
	int size = 0;

	cout << "Input array size: ";
	cin >> size;

	// Don't worry about the change in the way the array is created
	// at this point.
	// This puts the array in the heap so we can use larger arrays.

	int *A = new int[size];
	int *B = new int[size];
	for (int i = 0; i < size; i++) {
		A[i] = rand();    //  Average
		//A[i] = i;         //  Best
		//A[i] = size - i;  //  Worst
	}

	CopyArray(A, B, size);

	auto start = high_resolution_clock::now();
	quickSort(A, 0, size - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Quick sort = " << duration.count() / 1000000.0 << " seconds"
			<< endl;

	CopyArray(B, A, size);

	start = high_resolution_clock::now();
	sort(A, A + size);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);

	cout << "Algorithm sort = " << duration.count() / 1000000.0 << " seconds"
			<< endl;

	delete[] A;
	delete[] B;

	return 0;
}

void CopyArray(const int *A, int *B, int size) {
	for (int i = 0; i < size; i++)
		B[i] = A[i];
}

void printArray(int *array, int size, bool newline) {
	for (int i = 0; i < size; i++) {
		cout << array[i];
		if (newline)
			cout << endl;
		else
			cout << "  ";
	}
	cout << endl;
}

void quickSort(int *set, int start, int end) {
	int pivotPoint;
	if (start < end) {
		// Get the pivot point.
		pivotPoint = partition(set, start, end);
		// Sort the first sublist.
		quickSort(set, start, pivotPoint - 1);
		// Sort the second sublist.
		quickSort(set, pivotPoint + 1, end);
	}
}

int partition(int *set, int start, int end) {
	int pivotValue, pivotIndex, mid;
	mid = (start + end) / 2;
	swap(set[start], set[mid]);
	pivotIndex = start;
	pivotValue = set[start];
	for (int scan = start + 1; scan <= end; scan++) {
		if (set[scan] < pivotValue) {
			pivotIndex++;
			swap(set[pivotIndex], set[scan]);
		}
	}
	swap(set[start], set[pivotIndex]);
	return pivotIndex;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
