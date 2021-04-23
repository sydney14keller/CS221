#pragma once
#pragma once
#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;
using std::ostream;
//using namespace std;                  //we could use this, but this does cause some unnecessary bloat in the program

class ItemSL
{
private:
	double m_weight;                    //the price of the item
	string m_name;                      //the name of the item

public:
	ItemSL();                             //default constructor. defaults values to zero. we don't need it, but the compiler does.
	ItemSL(string name, double weight);   //constructor. uses the values passed in
	double getWeight();                 //returns the weight of the item
	string getName();                   //returns the name of the item
	int compareTo(ItemSL& other);
	bool operator<(ItemSL& rhs);
	bool operator>(ItemSL& rhs);


	void display(ostream& out);         //prints out "NAME --> WEIGHT" to the out stream provided
	ItemSL operator+ (const ItemSL& rhs);   //adds two items togethers. concatenates name, adds weight, and returns the sum.
};

