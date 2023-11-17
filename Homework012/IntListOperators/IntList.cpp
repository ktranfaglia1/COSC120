/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 1
 * IntList Object Implimentation
 */
#include <iostream>

#include "IntList.h"

using namespace std;
// Constructor
IntList::IntList() {
}
// Copy Constructor
IntList::IntList(const IntList& obj) {
	size = obj.size;
	capacity = obj.capacity;
	list = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		list[i] = obj.list[i];
	}
}
// Destructor
IntList::~IntList() {
	delete[] list; 
}
// Function to set the incoming paramter value element to value at array memory location of position index
void IntList::set(int position, int element) {
	// Bound Checker. If position is out of possible range 0 to size, the user is informed this is a bound error
	if (position < 0 || position >= size) {
		cout << "List bounds error" << endl;
	}
	else {
		*(list + position) = element;
	}
}
// Function to take in list and a position and return the value at that index in the array
int IntList::get(int position) {
	// Bound Checker. If position is not in range 0 to size, the user is informed this is a bound error and returns 0
	if (position < 0 || position >= size) {
		cout << "List bounds error, returning 0" << endl;
		return 0;
	}
	return *(list + position);
}
// Function to get the size of the array by returning the size class member
int IntList::get_size() {
	return size;
}
// Function to get the capacity of the array by returning the capacity class member
int IntList::get_capacity() {
	return capacity;
}
// Function to add the incoming parameter value of insert to the last index of the array and if the capacity is not 
// big enough to accept another index, a function is called to increase the capacity of the array
void IntList::push_back(int insert) {
	// Statement to call the increase capacity function if list capacity
	// and size are equal, meaning there is no capacity to store an incremented size
	if (capacity == size) {
		increase_capacity();
	}
	size++;
	*(list + size - 1) = insert;
}
// Function to add the incoming parameter value of insert to the first index of the array and push the current indexes over 1 
// if the capacity is not big enough to accept another index, a function is called to increase the capacity of the array
void IntList::push_front(int insert) {
	// Statement to call the increase capacity function if list capacity
	// and size are equal, meaning there is no capacity to store an incremented size
	if (capacity == size) {
		increase_capacity();
	}
	size++;
	// Loop to move all of the indexes of the array to the incremented element, meaning index 1 of the array is replaced by index 0
	for (int i = size - 1; i > 0; i--) {
		*(list + i) = *(list + i - 1);
	}
	*list = insert; // Sets first index as paramter value
}
// Function to remove an index from the back of an array by subtracting 1 from the size of the array
int IntList::pop_back() {
	
	int removed = *(list + size - 1);
	size--;
	return removed;
}
// Function to remove an index from the front of an array by using a for loop to set index - 1 as index
int IntList::pop_front() {
	
	int removed = *(list);
	// Loop that sets the index - 1 as index, meaning index at 0 is replaced by index at 1 and continues for size
	for (int i = 1; i < size; i++) {
		*(list + i - 1) = *(list + i);
	}
	size--;
	return removed;
}
// Function to concatenate the two arrays, one sent by referenced pointer, and another accessed as an object and create a new heap
// memory location for array with updated capacity that will then update pointer for origional array
void IntList::concat(const IntList& obj) {
	
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
}
// Function to increase the capacity of the dynamic array by doubling its size and creating a new array with that size, and then transfering the elments to
// the new aray, delete the old array, and then change the pointer to the new array
void IntList::increase_capacity() {
	// Sets capacity to 1 if 0, otherwise, doubles capacity and trasnfers array to new array of that capacity
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
// Function to sort the array list of integers in ascending order using an insertion sort
void IntList::sort() {
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
// Function to print the elements in an array using an object
void IntList::print() {
	// For loop to print array elements from the first index until the last index by dereferencing a pointer
	for (int i = 0; i < size; i++) {
		cout << *(list + i) << " ";
	}
	cout << endl;
}
// Function to clear the array pointer to by list memeber by settign size and capacity to 0
void IntList::clear() {
	capacity = size = 0;
	delete[] list;
	list = nullptr;
}
// Fucntion to set an object equal to another object my assigning size and capacity and then copying the array
const IntList IntList::operator=(const IntList& obj) {
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
// Function to find the value of the array at an index and return that value or display an error and exit if the element is out of the bounds
int& IntList::operator[](const int& num) {
	// Checks if the parameter is out of bounds and exits if true. Otherwise, value of array at index is returned
	if (num < 0 || num >= size) {
		cout << "This is not a valid index";
		exit(1);
	}
	else {
		return list[num];
	}
}
// Function to concatenate two arrays by determing how the + operator is used with the object, and returns a new object variable of the concatenation
IntList IntList::operator+(const IntList& obj) {
	
	IntList concatenate;
	
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
	return concatenate;
}
// Function to concatenate the two arrays and store the results in left object
void IntList::operator +=(const IntList& obj) {
	
	int start = size;
	size += obj.size;
	capacity = size;
	int *newList = new int[capacity]; // Creates dynamic memory array to store concatenated lists with capacity of the sum of the two list sizes
	// Loop to concatenate the two arrays and store the results in left object variable by adding onto the left array member
	//cout << obj;
	for (int i = 0, j = 0, k = 0; i < capacity; i++) {
		if (i < start) {
			*(newList + i) = *(list + j++);
		}
		else {
			*(newList + i) = *(obj.list + k++);
		}
	}
	delete[] list;
	list = newList;
}
// Function to compare two object variables and return true if the arrays are the same size and contain the same elements
bool IntList::operator ==(const IntList& obj) {
	
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
bool IntList::operator !=(const IntList& obj) {
		
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
// Function to allow a cout of object by returning an out ostream that contains a looped print instructions to display each element of object array
ostream& operator <<(ostream& out, const IntList& obj) {
	// Loop to display the cout structure for each element of the array sepearted by a space
	for (int i = 0; i < obj.size; i++) {
		out << obj.list[i] << "  ";
	}
	return out;
}