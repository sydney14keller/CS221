#include "Bill.h"
#include<string>
#include<iostream>

Bill::Bill()
{
	
	m_subtotal = 0;
	m_location = 0;
	m_signature = "";
	m_prices;//array
	m_total;
	m_tip;
	m_first = NULL;
}void Bill::print(std::ostream& out)	{		out << "Hello! Test!" << std::endl;	}

double Bill::getSubtotal()//in this cpp file, you actually implement the body of code
{
	return m_subtotal;
}

void Bill::addItem(const Item& i)
{

	Node* newNode = new Node(i);//create dynamically and the node contains i

	//start at m_first, iterate until the "next" pointer is null. The last node has to have a NULL pointer. Let us call the last node temp
	Node* temp = m_first;//temp now points to the very first thing


	if (temp != NULL) {
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		//we have reached the end, and temp points to the final node that exists alredy
		temp->next = newNode;
		m_counter++; //counter to ow many nodes you have
	}
}