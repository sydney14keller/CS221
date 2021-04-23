
#include <string>
#include <iostream> 
using std::cout; using std::endl;
using std::string;

#include "Item.h"
#include "List.h"

int main()
{
	Item i1("example", 10.00);
	Item i2("example2", 80);
	Item i3("example3", 3.00);
	Item i4("example4", 10.00);
	Item i5("example5", 80);
	Item i6("example6", 3.00);

	List list1;
	list1.addItem(i1);
	list1.addItem(i2);
	list1.addItem(i3);
	list1.addItem(i4);
	list1.addItem(i5);
	list1.addItem(i6);

	list1.display(cout);

	list1.removeItem(i2);
	cout << endl;
	list1.display(cout);
}