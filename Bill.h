#pragma once

#include "Item.h"

class Node		//this class is used by the List to hold Items.
{				//because it is so small, it is okay being included in this Bill.h file
public:			//however, it would also work in its own class files, provided you #include "Node.h" here
	Item item;
	Node* next;
	Node(const Item& i)
	{
		next = NULL;
		item = i;
	}
};

class Bill
{
private:							//this private declaration isn't needed, but it's good habit
	Node* m_first;					//this is a pointer to the beginning of the List.
	Node* m_last;					//this is a pointer to the end of the List.
	Node* m_current;				//this is a pointer to the Node in the List that is currently being assessed
	int m_length;					//this stores the number of Nodes/Items currently in the List

	//the following variables are used to make this List resemble a Bill. They aren't necessary for a simple List.
	double m_subtotal;				//this will store the sum of all of the Item's prices in the List.
	string m_signature;				//this will store the customer's signature
	double m_tip;					//this will store the customer's tip paid, if any
	//double m_total;				//this is not used, because we'll create a function that calculates the total whenever it's needed.

public:
	Bill();							//constructor. defaults values to zero/NULL
	~Bill();						//deconstructor. this function will clean up our pointers (because C++ makes us do it manually)
									//  the deconstructor runs automatically whenever you use 'delete' on a Bill object
	bool addItem(const Item& i);	//this function adds an Item to the list, returns true if succeeded or false if failed.
									// by default, this won't ever fail, but its standard to make this a bool incase your
									// requirements change
									//  additionally, adds the price of the item to the subtotal.
	bool removeItem(const Item& i);	//this function removes an Item from the list by scanning the Nodes until the specified
									// item is found. If it is not found, it returns false.
									//   additionally, adjusts subtotal as needed
	void clearList();				//this function will delete everything in the List (and should reset subtotal to zero in the process)
	void print(ostream& out);		//this will output a representation of the List/Bill
	int getLength();				//this will return the variable m_length (the number of elements in the list)
	bool isFull();					//this will return true if the List is full. Generally, a linked list doesn't ever need to be full,
									//but you could add a limit if you want.
	bool isEmpty();					//this will tell you if the List has any Nodes in it
	void resetIterator();			//this resets the iterator by setting m_current back to m_first;
	bool hasNext();					//this can be used to determine if you're at the end of the List or not.
	Item getNext();					//this can be used to copy an Item out of the List. contrary to the name of the function,
									//  this will be used to get the Item at the location of m_current, not "the next" one.
									//  I have a feeling this is NOT what the function is supposed to do, but it's what I'm deciding on :)

	//the following functions are used to make this List resemble a Bill. They aren't necessary for a simple List.
	void setTip(double tip);
	void setSignature(string sign);
	double getTotal();				//this function returns the sum of m_subtotal and m_tip
};

