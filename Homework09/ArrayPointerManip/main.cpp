/* Kyle Tranfaglia
 * 11/14/22
 * Homework#9
 * This program contains several array manipulation functions that use pointers
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Prototypes
void PopulateArray(int *p, int size);
void PrintArray(const int *p, int size);
int* ReverseCopy (const int *array, int size);
int* DoubleCopy (const int *array, int size);
int* BegAddZero(const int *array, int size);
int* FirstToLast(const int *array, int size);
int* CombineArrays(const int *array, const int *array2, int size, int randSize);

int main() {
	srand(time(0));
	// Variables
	int size = 0;
	int randSize = 0;
	
	cout << "Enter the array size: ";
	cin >> size;
	// Input validation for user size input. If size is not greater than 0, the user must enter a new size until it is a valid input
	while (size <= 0) {
		cout << "Invalid input! Please enter a size greater than 0";
		cout << "Enter the array size: ";
		cin >> size;
	}
	// 5 array manipulation functions are called and set to a dynamically created array and then compared to origionally array
	cout << "Array Manipulations" << endl << "-------------------" << endl;
	int *array = new int[size];
	PopulateArray(array, size);
	PrintArray(array, size);
	
	int *arrayReversed = ReverseCopy(array, size);
	PrintArray(arrayReversed, size);
	cout << endl;
	
	int *arrayDouble = DoubleCopy(array, size);
	PrintArray(array, size);
	PrintArray(arrayDouble, size*2);
	cout << endl;
	
	int *arrayAddZero = BegAddZero(array, size);
	PrintArray(array, size);
	PrintArray(arrayAddZero, size + 1);
	cout << endl;
	
	int *arrayFirstToLast = FirstToLast(array, size);
	PrintArray(array, size);
	PrintArray(arrayFirstToLast, size);
	cout << endl;
	
	randSize = (rand() % 20) + 1; // Sets a random size between 1 and 20 for the second array size
	int *array2 = new int[randSize];
	PopulateArray(array2, randSize);
	int *arrayCombination = CombineArrays(array, array2, size, randSize);
	PrintArray(array, size);
	PrintArray(array2, randSize);
	PrintArray(arrayCombination, size + randSize);
	
	// Clears all memory in heap dedicated to dynamically created arrays and resets the pointers to the arrays to nothing
	delete[] array;
	delete[] arrayReversed;
	delete[] arrayDouble;
	delete[] arrayAddZero;
	delete[] arrayFirstToLast;
	delete[] arrayCombination;
	array = nullptr;
	arrayReversed = nullptr;
	arrayDouble = nullptr;
	arrayAddZero = nullptr;
	arrayFirstToLast = nullptr;
	arrayCombination = nullptr;
	
	return 0;
}
// Function to populate any array with random numbers between 0 and 9 using a pointer
void PopulateArray(int *p, int size) {
	// Loop to dereference the pointer to memory location of an index of the array and set the value to a random number between 1 and 9
	for (int i = 0; i < size; i++) {
		*p++ = rand () % 10;
	}
}
// Function to print any array by a pointer to the array, given the size of the array
void PrintArray(const int *p, int size) {
	// Loop to dereference the pointer to memory location of index in array and print the value at that location
	for (int i = 0; i < size; i++) {
		cout << *p++ << " ";
	}
	cout << endl;
}
// Function to dynamically create an array as a copy of a pointer to an array and reverse the order, then return the pointer to the new array
int* ReverseCopy(const int *array, int size) {
	
	int *arrayReversed = new int[size];
	// Loop to copy indexes of array into new array but in reverse order by using a dereferenced pointer and starting the
	// new array at first index, and the origional array as the last index and copying the values 
	for (int i = 0; i < size; i++) {
		*(arrayReversed + i) = *(array + (size - 1) - i);
	}
	return arrayReversed;
}
// Function to dynamically create an array as a copy of a pointer to an array, double the size and set the second half as 0s, then return the pointer to the new array
int* DoubleCopy(const int *array, int size) {
	
	int *arrayDouble = new int[size*2];
	// Loop to copy indexes of array into new array until size using a dereferenced pointer and setting the first first index
	// of new array to first index of origional array, and then when size is reached, it fills the rest of new array with 0s 
	for (int i = 0; i < size*2; i++) {
		if (i < size) {
			*(arrayDouble + i) = *(array + i);
		}
		else {
			*(arrayDouble + i) = 0;
		}
	}
	return arrayDouble;
}
// Function to dynamically create an array as a copy of a pointer to an array, but with a size of one greater and the first 
// index set to zero with element 0 of parameter array set as element 1 of new array, then return the pointer to the new array
int* BegAddZero(const int *array, int size) {
	
	int *arrayAddZero = new int[size + 1];
	*arrayAddZero = 0; // Dereferences pointer to first index of new array and sets value to 0
	// Loop to copy indexes of array into new array until size using a dereferenced pointer and
	// setting the first second index of new array to first index of origional array until size
	for (int i = 0; i < size; i++) {
		*(arrayAddZero + i + 1) = *(array + i);
	}
	return arrayAddZero;
}
// Function to dynamically create an array as a copy of a pointer to an array, and set the last index of parameter array as the first index
// in new array, with element 0 of parameter array set as element 1 of new array until size, then return the pointer to the new array 
int* FirstToLast(const int *array, int size) {
	
	int *arrayFirstToLast = new int[size];
	*arrayFirstToLast = *(array + size - 1); // Dereferences pointer to first index of new array and sets value to derenferenced pointer to array at last index
	// Loop to copy indexes of array into new array until size using a dereferenced pointer
	// and setting the first second index of new array to first index of origional array until size
	for (int i = 0; i < size; i++) {
		*(arrayFirstToLast + i + 1) = *(array + i);
	}
	return arrayFirstToLast;
}
// Function to dynamically create an array as a combined copy of a pointer to two arrays of varying sizes,
// interlacing the two arrays into a combined arrray, then return the pointer to the new array 
int* CombineArrays(const int *array, const int *array2, int size, int randSize) {
	
	//int stop = 0;
	int i = 0, k = 0, j = 0;
	int *arrayCombination = new int[size + randSize];
	// Loop to combine and interlace the two arrays into new dynamic array using dereferenced pointers. It uses nested if statements 
	// to set even indexes of new array including 0, to indexes of first array, then odd indexes of new array to indexes of first array,
	// and when one array is out of indexes, the remaining indexes of larger array, if they are not the same size, will be set to following indexes
	while (i < size + randSize) {
		if ((i % 2 == 0) && k < size) {
			*(arrayCombination + i++) = *(array + k++);
		}
		else if ((i % 2 != 0) && j < randSize && k < size) {
			*(arrayCombination + i++) = *(array2 + j++);
		}
		else if (j < randSize) {
			*(arrayCombination + i++) = *(array2 + j++);
		}
		else if (k < size) {
			*(arrayCombination + i++) = *(array + k++);
		}
	}
	return arrayCombination;
}