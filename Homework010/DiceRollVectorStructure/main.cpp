/* Kyle Tranfaglia
 * 11/17/22
 * Homework#10 - Exercise 3
 * This program creates uses structure that acts like an STL vector and rolls two dice per user 
 * selected times and displays number of each roll sum and the probabilities of that sum
 */
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Struct for list of integers
struct IntList {
	int size = 0;
	int capacity = 0;
	int *list = nullptr;
};
// Prototypes
void set(IntList&, int, int);
int get(const IntList&, int);
int get_size(const IntList&);
int get_capacity(const IntList&);
void push_back(IntList&, int);
void push_front(IntList&, int);
int pop_back(IntList&);
int pop_front(IntList&);
void concat(IntList&, const IntList&);
void increase_capacity(IntList&);
void destroy(IntList&);
void sort(IntList&);
void CountRolls(const IntList&, IntList&);
void printCount(IntList&);
void printProbability(IntList&, int rolls);

int main() {
	
	srand(time(0));
	// Variables
	IntList list1, list2;
	int rollSum = 0, rolls = 0;
	
	cout << "Input the number of rolls: ";
	cin >> rolls;
	while (rolls <= 0) {
		cout << "Invalid input! Please enter an integer value greater than 0";
		cout << "Input the number of rolls: ";
		cin >> rolls;
	}
	for (int i = 0; i < rolls; i++) {
		rollSum = (rand() % 6 + 1) + (rand() % 6 + 1);
		push_back(list1, rollSum);
	}
	for (int i = 0; i <= 10; i++) {
		push_back(list2, 0);
	}
	CountRolls(list1, list2);
	printCount(list2);
	printProbability(list2, rolls);
	
	destroy(list1);
	destroy(list2);
	
	return 0;
}
// Function to set the incoming paramter value element to value at array memory location of position index
void set(IntList &list, int position, int element) {
	// Bound Checker. If position is out of possible range 0 to size, the user is informed this is a bound error
	if (position < 0 || position > list.size) {
		cout << "List bounds error" << endl;
	}
	*(list.list + position) = element;
}
// Function to take in list and a position and return the value at that index in the array
int get(const IntList &list, int position) {
	// Bound Checker. If position is not in range 0 to size, the user is informed this is a bound error and returns 0
	if (position < 0 || position > list.size) {
		cout << "List bounds error, returning 0" << endl;
		return 0 ;
	}
	return *(list.list + position);
}
// Function to get the size of the referenced parameter list by accessing the struct
int get_size(const IntList &list) {
	return list.size;
}
// Function to get the capacity of the referenced parameter list by accessing the struct
int get_capacity(const IntList &list) {
	return list.capacity;
}
// Function to add the incoming parameter value of insert to the last index of the array and if the capacity is not 
// big enough to accept another index, a function is called to increase the capacity of the array
void push_back(IntList &list, int insert) {
	// Statement to call the increase capacity function if list capacity
	// and size are equal, meaning there is no capacity to store an incremented size
	if (list.capacity == list.size) {
		increase_capacity(list);
	}
	*(list.list + list.size) = insert;
	list.size++;
}
// Function to add the incoming parameter value of insert to the first index of the array and push the current indexes over 1 
// if the capacity is not big enough to accept another index, a function is called to increase the capacity of the array
void push_front(IntList &list, int insert) {
	// Statement to call the increase capacity function if list capacity
	// and size are equal, meaning there is no capacity to store an incremented size
	if (list.capacity == list.size) {
		increase_capacity(list);
	}
	// Loop to move all of the indexes of the array to the incremented element, meaning index 1 of the array is replaced by index 0
	for (int i = list.size + 1; i > 0; i--) {
		*(list.list + i) = *(list.list + i - 1);
	}
	*(list.list) = insert; // Sets first index as paramter value
	list.size++;
}
// Function to remove an index from the back of an array by subtracting 1 from the size of the array
int pop_back(IntList &list) {
	
	int removed = *(list.list + list.size - 1);
	list.size--;
	return removed;
}
// Function to remove an index from the back of an array by using a for loop to set index - 1 as index,
int pop_front(IntList &list) {
	
	int removed = *(list.list);
	// Loop that sets the index - 1 as index, meaning index at 0 is replaced by index at 1 and continues for size
	for (int i = 1; i < list.size; i++) {
		*(list.list + i - 1) = *(list.list + i);
	}
	list.size--;
	return removed;
}
// Function to concatenate the two arrays sent by referenced pointers within a struct, and create a new heap
// memory location for array with updated capacity that will then update pointer for origional array
void concat(IntList &list, const IntList &list2) {
	
	list.capacity = list.size + list2.size;
	int *concatList = new int[list.capacity]; // Creates dynamic memory array to store concatenated lists with capacity of the sum of the two list sizes
	// Loop to concatenate the two arrays by using an if statment to first store all the list1 values, then all the list2 values, with each array having its own iterator
	for (int i = 0, j = 0, k = 0; i < list.capacity; i++) {
		if (i < list.size) {
			*(concatList + i) = *(list.list + j++);
		}
		else {
			*(concatList + i) = *(list2.list + k++);
		}
	}
	delete [] list.list; // Deletes the list array stored in heap
	list.list = concatList; // Redirectes the .list pointer to the new concatenate array
	list.size = list.capacity; // Updates list size to be same as capacity
}
// Function to increase the capacity of the dynamic array by doubling its size and creating a new array with that size, and then transfering the elments to
// the new aray, delete the old array, and then chnage the pointer to the new array
void increase_capacity(IntList &list) {
	// If statement used to check if capacity is 0, if so capicty is set to 1 and an array is dynamically created, otherwise capacity is doubled and 
	// a new array is created with a size of the doubled capacity and the old array elements are transfered to the new array, with the rest set to 0
	if (list.capacity == 0) {
		list.capacity = 1;
		list.list = new int[1]; // Creates dynamic memory array
	}
	else {
		list.capacity *= 2;
		int *biggerList = new int[list.capacity]; // Creates dynamic memory array
		// For loop to transfer the old array to the new array by coping the elements until old array size and then filling the rest of the new array with 0s
		for (int i = 0; i < list.capacity; i++) {
			if (i < list.size) {
				*(biggerList + i) = *(list.list + i);
			}
			else {
				*(biggerList + i) = 0;
			}
		} 
		delete [] list.list; // Frees to memeory set aside in heap for array to prevent memeory leak as the pointer will be moved away from this array
		list.list = biggerList; // Moves pointer for .list to the newly created array of double the capacity
	}
}
// Function to delete a dynamically created array, or in other words, frees to memeory set aside in heap for the array and resets the pointer to that array
void destroy(IntList &list) {
	delete [] list.list;
	list.list = nullptr;
}
// Function to sort the array list of integers in ascending order using an insertion sort
void sort(IntList &list) {
	// For loop to sort the array by going through each element and while the value at one index ahead of another index is greater, that the
	// element is moved to the next larger index and this continues until the the element is no longer larger than the next index
	for (int i = 1; i < list.size; i++) {
		int temp = *(list.list + i);
		int loc = i - 1;
		while (loc >= 0 && *(list.list + loc) > temp) {
			*(list.list + loc + 1) = *(list.list + loc);
			loc--;
		}
		*(list.list + loc + 1) = temp;
	}
}
// Function to count the number of each sum of rolls and increment the corresponding index for that count in another list
void CountRolls(const IntList& list1, IntList& list2) {
	// For loop to go through each index of pointer to list1 array, dereference it, subtract two (2 count is stored in index 0),
	// and increment the beggining of the list 2 array plus that position to keep a count of that dice sum. 
	for (int i = 0; i < list1.size; i++) {
		*(list2.list + *(list1.list + i)- 2) += 1;
	}
}
// Function to print the elements in an array accessed by a reference to a struct containing the integer pointer
void printCount(IntList &list) {
	cout << "Counts" << endl << "------" << endl;
	// For loop to print array elements from the first index until the last index by dereferencing a pointer
	for (int i = 0; i < list.size; i++) {
		cout << i + 2 << ": " << *(list.list + i) << endl;
	}
	cout << endl;
}
// Function to print the elements in an array accessed by a reference to a struct containing the integer pointer
void printProbability(IntList &list, int rolls) {
	cout << "Probabilities" << endl << "-------------" << endl;
	// For loop to print array elements from the first index until the last index by dereferencing a pointer
	for (int i = 0; i < list.size; i++) {
		cout << i + 2 << ": " << *(list.list + i) / (rolls*1.0) << endl;
	}
	cout << endl;
}