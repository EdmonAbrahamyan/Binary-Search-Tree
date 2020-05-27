#include "SearchTree.h"
#include <iostream>
using namespace std;

int main()
{
	SearchTree s;
	cout << endl << "*****   INSERTIONS: 4, 2, 3, 7, 6, 1, 5, 8   *****" << endl << endl;
	s.insert(4);
	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(6);
	s.insert(1);
	s.insert(5);
	s.insert(8);
	s.print();

	cout << endl << "*****   DELETE: 7	*****" << endl << endl;
	s.remove(7);
	s.print();

	cout << endl << "*****   DELETE: 4	*****" << endl << endl;
	s.remove(4);
	s.print();

	cout << endl << "*****   DELETE: 2	*****" << endl << endl;
	s.remove(2);
	s.print();


	cout << endl << "*****   DELETE: 1	*****" << endl << endl;
	s.remove(1);
	s.print();

	cout << endl << "*****   DELETE: 3	*****" << endl << endl;
	s.remove(3);
	s.print();

	cout << endl << "*****   DELETE: 8	*****" << endl << endl;
	s.remove(8);
	s.print();

	cout << endl << "*****   DELETE: 6	*****" << endl << endl;
	s.remove(6);
	s.print();

	cout << endl << "*****   DELETE: 5	*****" << endl << endl;
	s.remove(5);
	s.print();
	
	system("pause");
	return 0;
}



