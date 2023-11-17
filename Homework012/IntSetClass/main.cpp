/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 2
 * This program creates an IntSet Class with some operators to perform tasks and manipulates the object variable in the main
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IntSet.h"

using namespace std;

int main() {
	srand(time(0));
	
	IntSet set1, set2, set3;
	
	cout << set1 << endl;
	
	for (int i = 1; i <= 10; i++)
		set1.add(i);
		
	cout << set1 << endl;
	
	for (int i = 5; i <= 15; i++)
		set1.add(i);
		
	cout << set1 << endl;
	
	set1.add(-5);
	cout << set1 << endl;
	set1.sort();
	cout << set1 << endl;
	
	set1.clear();
	cout << set1 << endl;
	
	if (set1.isEmpty())
		cout << "set1 is empty." << endl;
		
	cout << endl;
	
	for (int i = 1; i <= 10; i++)
		set1.add(i);
		
	for (int i = 5; i <= 15; i++)
		set2.add(i);
		
	for (int i = -15; i <= -7; i++)
		set2.add(i);
		
	cout << set1 << endl;
	cout << set2 << endl;
	
	set3 = set1 + set2;
	cout << set3 << endl;
	
	set3 = set1 * set2;
	cout << set3 << endl;
	
	set3 = set1 - set2;
	cout << set3 << endl;
	
	set3 = set2 - set1;
	cout << set3 << endl;
	
	set3 = set2 - set2;
	cout << set3 << endl;
	
	cout << endl;
	if (set2.in(8))
		cout << "8 is in set 2." << endl;
		
	if (set2.in(100))
		cout << "100 is in set 2." << endl;
		
	cout << endl;
	set1.clear();
	
	for (int i = 1; i <= 10; i++)
		set1.add(i);
		
	set2 = set1;
	
	for (int i = 100; i <= 110; i++)
		set2.add(i);
		
	cout << set1 << endl;
	cout << set2 << endl;
	
	cout << (set1 < set2) << endl;
	cout << (set1 > set2) << endl;
	cout << (set1 == set2) << endl;
	cout << (set1 != set2) << endl;
	cout << (set2 == set2) << endl;
	set1.clear();
	set2.clear();
	
	cout << endl;
	
	for (int i = 0; i < 10; i++)
		set1.add(rand() % 100 + 1);
		
	for (int i = 0; i < 10; i++)
		set2.add(rand() % 100 + 1);
		
	cout << set1 << endl;
	cout << set2 << endl;
	
	set1.add(set2);
	
	cout << endl;
	cout << set1 << endl;
	cout << set2 << endl;
	
	return 0;
}
