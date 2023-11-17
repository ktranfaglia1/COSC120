#ifndef INTLIST_H
#define INTLIST_H

class IntList {
private:
	int size = 0;
	int capacity = 0;
	int *list = nullptr;
public:
	IntList();
	~IntList();
	
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
};

#endif