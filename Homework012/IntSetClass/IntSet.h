/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 2
 * IntSet Object Declarartion
 */
#ifndef INTSET_H
#define INTSET_H

#include <iostream>

using namespace std;

class IntSet {
private:
// Defaulted member variables
	int size = 0;
	int capacity = 0;
	int *list = nullptr;
	// Functions not seen by main
	void removeDuplicates();
	void increase_capacity();
	void push_back(int);
public:
	IntSet(); // Defualt Constructor
	IntSet(const IntSet&); // Copy Constructor
	~IntSet(); // Destructor
	// Functions
	int get_size();
	void add(const IntSet&);
	void add(int);
	bool in(int);
	bool isEmpty();
	void sort();
	void print();
	
	void clear();
	const IntSet operator=(const IntSet&);
	
	IntSet operator+(const IntSet&);
	IntSet operator-(const IntSet&);
	IntSet operator*(const IntSet&);
	
	bool operator ==(const IntSet&);
	bool operator !=(const IntSet&);
	bool operator >(const IntSet&);
	bool operator <(const IntSet&);
	
	friend ostream& operator <<(ostream&, const IntSet&);
};

#endif // INTSET_H
