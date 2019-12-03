#include <iostream>
#include "IntSearchTree.h"
using namespace std;


int main()
{

	IntSearchTree iTree;

	iTree.add(21);
	iTree.add(13);
	iTree.add(7);
	iTree.add(16);
	iTree.add(39);
	iTree.add(36);
	iTree.add(35);
	iTree.add(18);
	iTree.add(38);
	iTree.add(40);
	iTree.add(47);
	iTree.add(49);
	iTree.add(46);
	iTree.add(24);
	iTree.add(3);
	iTree.add(28);
	iTree.add(45);
	iTree.add(23);
	iTree.add(6);
	iTree.add(27);

	

	cout << iTree.contains(38) << endl;

	return 0;
}