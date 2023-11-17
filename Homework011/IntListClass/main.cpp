/* Kyle Tranfaglia
 * 12/01/22
 * Homework#11 - Exercise 1
 * This program creates a structure that acts like an STL vector by using an IntList Class to perform tasks
 */
#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
	IntList list1, list2;
	
	list1.push_back(15);
	list1.push_back(-4);
	list1.push_back(3);
	list1.push_back(7);
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	list1.push_back(17);
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	// For loop to push back values 1 through 10 on the back of array list2 via a function call
	for (int i = 1; i <= 10; i++)
		list2.push_back(i);
		
	list2.print();
	cout << list2.get_size() << " " << list2.get_capacity() << endl;
	
	cout << list2.get(5) << endl;
	cout << list2.get(15) << endl;
	
	list2.set(5, 1234);
	list2.set(15, -5);
	list2.print();
	
	list2.push_front(3);
	list2.print();
	cout << list2.get_size() << " " << list2.get_capacity() << endl;
	
	cout << list2.pop_front() << endl;
	cout << list2.pop_front() << endl;
	cout << list2.pop_back() << endl;
	
	list2.print();
	cout << list2.get_size() << " " << list2.get_capacity() << endl;
	
	cout << endl;
	list1.print();
	list2.print();
	
	cout << endl;
	list1.concat(list2);
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	
	list2.print();
	cout << list2.get_size() << " " << list2.get_capacity() << endl;
	
	cout << endl;
	list1.push_back(101);
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	
	list1.sort();
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	
	return 0;
}
