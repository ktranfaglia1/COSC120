/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 1
 * This program creates an IntList Class with some operators to perform tasks and manipulates the object variable in the main
 */
#include <iostream>
#include "IntList.h"

using namespace std;

void doNothing(IntList l) {
	cout << l << endl;
	l[4] = 1;
	l[0] = 1029;
}

int main() {
	IntList list1, list2, list3;
	
	list1.push_back(15);
	list1.push_back(-4);
	list1.push_back(3);
	list1.push_back(7);
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	
	list1.push_back(17);
	list1.print();
	cout << list1.get_size() << " " << list1.get_capacity() << endl;
	
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
	
	// New function testing
	
	cout << "New function testing ~~~~~~~~~~~~~~~" << endl;
	
	list1.clear();
	list1.push_back(5);
	
	list1.print();
	
	for (int i = 1; i <= 10; i++)
		list1.push_back(3 * i + 1);
		
	list1.print();
	
	list2 = list1;
	
	cout << endl;
	list1.print();
	list2.print();
	
	list1.set(3, -12);
	list1.set(7, 12345);
	cout << endl;
	list1.print();
	list2.print();
	
	cout << list1[3] << endl;
	cout << list2[3] << endl;
	cout << list2[4] << endl;
	cout << list2[7] << endl;
	
	// cout << list2[100] << endl; // Error causes program exit.
	// cout << list3[1] << endl; // Error causes program exit.
	cout << list2 << endl;
	
	list2[4] = -16;
	list2[1] = -2;
	cout << list2 << endl;
	
	list3 = list1 + list2;

	cout << endl;
	cout << list1 << endl;
	cout << list2 << endl;
	cout << list3 << endl;
	
	if (list1 == list2)
		cout << "list1 == list2" << endl;
	if (list1 != list2)
		cout << "list1 != list2" << endl;
	if (list1 == list1)
		cout << "list1 == list1" << endl;
		
	doNothing(list2);
	cout << list2 << endl;
	
	list2 += list3;
	cout << list2 << endl;
	
	return 0;
}
