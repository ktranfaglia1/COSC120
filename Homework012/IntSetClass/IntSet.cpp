/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 2
 * IntSet Object Implimentation
 */
#include <iostream>

#include "IntSet.h"

using namespace std;
// Defualt Constructor
IntSet::IntSet() {
}
// Copy Constructor
IntSet::IntSet(const IntSet& obj) {
	size = obj.size;
	capacity = obj.capacity;
	list = new int[capacity];
	// Loop to copy the elements of a list into another list
	for (int i = 0; i < capacity; i++) {
		list[i] = obj.list[i];
	}
}
// Destructor
IntSet::~IntSet() {
	delete[] list; 
}
// Function to remove the duplicate elements from the list by writing over the duplicate with the following element
void IntSet::removeDuplicates() {
	// Loop runs for size to remove any duplicate elements by comparing each index to all other indexes up until i
	// and decrements size, then rewrites the array in another loop up until i with non duplicate elements
	for (int checks = 0; checks < 3; checks++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				if (list[i] == list[j]) {
					size--;
					for (int k = i; k < size; k++) {
						list[k] = list[k + 1];
					}
				}
			}
		}
	}
}
// Function to increase the capacity of the dynamic array by doubling its size and creating a new array with that size, and then transfering the elments to
// the new aray, delete the old array, and then change the pointer to the new array
void IntSet::increase_capacity() {
	
	if (capacity == 0) {
		capacity = 1;
		list = new int[1]; // Creates dynamic memory array
	}
	else {
		capacity *= 2;
		int *biggerList = new int[capacity]; // Creates dynamic memory array
		// For loop to transfer the old array to the new array by coping the elements until old array size and then filling the rest of the new array with 0s
		for (int i = 0; i < capacity; i++) {
			if (i < size) {
				*(biggerList + i) = *(list + i);
			}
			else {
				*(biggerList + i) = 0;
			}
		} 
		delete [] list; // Frees to memeory set aside in heap for array to prevent memeory leak as the pointer will be moved away from this array
		list = biggerList; // Moves pointer for .list to the newly created array of double the capacity
	}
}
// Function to add the incoming parameter value of insert to the last index of the array and if the capacity is not 
// big enough to accept another index, a function is called to increase the capacity of the array
void IntSet::push_back(int insert) {
	// Statement to call the increase capacity function if list capacity
	// and size are equal, meaning there is no capacity to store an incremented size
	if (capacity == size) {
		increase_capacity();
	}
	size++;
	*(list + size - 1) = insert;
}
// Function to get the size of the array by returning the size class member
int IntSet::get_size() {
	return size;
}
// Function to concatenate the two arrays, one sent by referenced pointer, and another accessed as an object and create a new heap
// memory location for array with updated capacity that will then update pointer for origional array
void IntSet::add(const IntSet& obj) {
	
	capacity = size + obj.size;
	int *concatList = new int[capacity]; // Creates dynamic memory array to store concatenated lists with capacity of the sum of the two list sizes
	// Loop to concatenate the two arrays by using an if statment to first store all the object values, then all the parameter values, with each array having its own iterator
	for (int i = 0, j = 0, k = 0; i < capacity; i++) {
		if (i < size) {
			*(concatList + i) = *(list + j++);
		}
		else {
			*(concatList + i) = *(obj.list + k++);
		}
	}
	delete [] list; // Deletes the list array stored in heap
	list = concatList; // Redirectes the list pointer to the new concatenate array
	size = capacity; // Updates list size to be same as capacity
	removeDuplicates();
}
// Fucntion to add an element to the array
void IntSet::add(int insert) {
	push_back(insert);
	removeDuplicates();
}
// Function to check if an element is in the array
bool IntSet::in(int element) {
	
	bool status = false;
	// Linear search to compare each index to element value
	for (int i = 0; i < size; i++) {
		if (element == list[i]) {
			status = true;
		}
	}
	return status;
}
// Function to check if the array is empty
bool IntSet::isEmpty() {
	
	bool status = false;
	// Size zero must mean the array has no indexes so status is set to true
	if (size == 0) {
		status = true;
	}
	return status;
}
// Function to sort the array list of integers in ascending order using an insertion sort
void IntSet::sort() {
	// For loop to sort the array by going through each element and while the value at one index ahead of another index is greater, that the
	// element is moved to the next larger index and this continues until the the element is no longer larger than the next index
	for (int i = 1; i < size; i++) {
		int temp = *(list + i);
		int loc = i - 1;
		while (loc >= 0 && *(list + loc) > temp) {
			*(list + loc + 1) = *(list + loc);
			loc--;
		}
		*(list + loc + 1) = temp;
	}
}
// Function to print the elements in an array using an object to print the elements within the list array in a bracketed list
void IntSet::print() {
	
	cout << "{";
	for (int i = 0; i < size; i++) {
		cout << list[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}
// Fucntion to clear the array by setting size and capacity to zero
void IntSet::clear() {
	capacity = size = 0;
	delete[] list;
	list = nullptr;
}
// Fucntion to set an object equal to another object by assigning size and capacity and then copying the array
const IntSet IntSet::operator=(const IntSet& obj) {
	delete[] list;
	size = obj.size;
	capacity = obj.capacity;
	list = new int[capacity]; // Creates dynamic memory array to store concatenated lists with capacity of the sum of the two list sizes
	// For loop to go through entire array and copy the elements into array of parameter object
	for (int i = 0; i < size; i++) {
		list[i] = obj.list[i];
	}
	return *this;
}
// Function to concatenate two arrays by determing how the + operator is used with the object, and returns a new object variable of the concatenation
IntSet IntSet::operator+(const IntSet& obj) {
	
	IntSet concatenate;
	
	concatenate.size = size + obj.size;
	concatenate.capacity = concatenate.size;
	
	concatenate.list = new int[concatenate.capacity]; // Creates dynamic memory array to store concatenated lists with capacity of the sum of the two list sizes
	// Loop to concatenate the two arrays by using an if statment to first store all the object values, then all the parameter values, with each array having its own iterator
	for (int i = 0, j = 0, k = 0; i < concatenate.capacity; i++) {
		if (i < size) {
			*(concatenate.list + i) = *(list + j++);
		}
		else {
			*(concatenate.list + i) = *(obj.list + k++);
		}
	}
	concatenate.removeDuplicates();
	return concatenate;
}
// Fucntion to get the set difference by populating an array with all the unique elements of the left object list
IntSet IntSet::operator-(const IntSet& obj) {
	
	int count = 0;
	IntSet diff;
	
	diff.capacity = capacity;
	diff.list = new int[diff.capacity]; // Dynamically allocates memeory for an integer array
	// Loop to go through each element of obj array and compare to list array and if none of the elements match, it places the element in the new array
	for (int i = 0, j = 0; i < size; i++) {
		count = 0;
		for (int k = 0; k < obj.size; k++) {
			if (list[i] != obj.list[k]) {
				count++;
			}
		}
		if (count == obj.size) {
			diff.list[j++] = list[i];
			diff.size++;
		}
	}
	return diff;
}
// Fucntion to get the intersection the arrays meaning, it populates an array with only shared terms between the two arrays
IntSet IntSet::operator*(const IntSet& obj) {
	
	int count = 0;
	IntSet inter;
	
	inter.capacity = capacity;
	inter.list = new int[inter.capacity]; // Dynamically allocates memeory for an integer array
	// Loop to go through each element of obj array and compare to list array and if at least one of the elements match, it places the element in the new array
	for (int i = 0, j = 0; i < size; i++) {
		count = 0;
		for (int k = 0; k < obj.size; k++) {
			if (list[i] == obj.list[k]) {
				count++;
			}
		}
		if (count != 0) {
			inter.list[j++] = list[i];
			inter.size++;
		}
	}
	return inter;
}
// Function to compare two object variables and return true if the arrays are the same size and contain the same elements
bool IntSet::operator ==(const IntSet& obj) {
	
	bool status = false;
	// Identifies if sizes are same, and then uses nested for loop to count how many of the elements are equal, and if all of them, true is returned
	if (size == obj.size) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (list[i] == obj.list[i])
				count++;
		}
		if (count == size) {
			status = true;
		}
	}
	return status;
}
// Function to compare two object variables and return true if the arrays are the not same size and do not contain the same elements
bool IntSet::operator !=(const IntSet& obj) {
	
	bool status = true;
	// Identifies if sizes are same, and then uses nested for loop to count how many of the elements are equal, and if all of them, true is returned
	if (size == obj.size) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (list[i] == obj.list[i])
				count++;
		}
		if (count == size) {
			status = false;
		}
	}
	return status;
}
// Fucntion to determine how the > operator functions. The expression is true if the left array is a superset
bool IntSet::operator >(const IntSet& obj) {
	
	bool status = false;
	int count = 0;
	// Loop to compare every element of obj array to left array and if every element in obj list is in left list, true is returned
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < obj.size; k++) {
			if (list[i] == obj.list[k]) {
				count++;
				k = obj.size;
			}
		}
	}
	if (count == obj.size){
		status = true;
	}
	return status;
}
// Fucntion to determine how the < operator functions. The expression is true if the left array is a subset
bool IntSet::operator <(const IntSet& obj) {
	
	bool status = false;
	int count = 0;
	// Loop to compare every element of obj array to left array and if every element in left list is in obj list, true is returned
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < obj.size; k++) {
			if (list[i] == obj.list[k]) {
				count++;
				k = obj.size;
			}
		}
	}
	if (count == size){
		status = true;
	}
	return status;
}
// Function to allow a cout of object by returning an out ostream that contains a looped print instructions to display each element of object array
ostream& operator <<(ostream& out, const IntSet& obj) {
	out << "{";
	// Loop to display the cout structure for each element of the array sepearted by a comma and a space asa a bracketed list
	for (int i = 0; i < obj.size; i++) {
		out << obj.list[i];
		if (i < obj.size - 1) {
			out << ", ";
		}
	}
	out << "}";
	return out;
}