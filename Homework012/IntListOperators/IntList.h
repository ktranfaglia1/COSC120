/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 1
 * IntList Object Declarartion
 */
#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

using namespace std;

class IntList {
private:
	// Defaulted member variables
	int size = 0;
	int capacity = 0;
	int *list = nullptr;
public:
	IntList(); // Constructor
	~IntList(); // Destructor
	// Functions
	void set(int, int);
	int get(int);
	int get_size();
	int get_capacity();
	void push_back(int);
	void push_front(int);
	int pop_back();
	int pop_front();
	void concat(const IntList&);
	void increase_capacity();
	void sort();
	void print();
	
	// New Functions
	void clear();
	IntList(const IntList&); // Copy Constructor
	const IntList operator=(const IntList&);
	
	int& operator[](const int&);
	
	IntList operator+(const IntList&);
	void operator +=(const IntList&);
	
	bool operator ==(const IntList&);
	bool operator !=(const IntList&);
	
	friend ostream& operator <<(ostream&, const IntList&);
};

#endif
