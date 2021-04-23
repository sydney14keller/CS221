#pragma once
#pragma once
#include <iostream>
#include <string>
using std::cout; using std::endl;
using std::string;
using std::ostream;
//using namespace std;                  //we could use this, but this does cause some unnecessary bloat in the program

class Item
{
private:
	double m_weight;                    //the price of the item
	string m_name;                      //the name of the item

public:
	Item();                             //default constructor. defaults values to zero. we don't need it, but the compiler does.
	Item(string name, double weight);   //constructor. uses the values passed in
	double getWeight();                 //returns the weight of the item
	string getName();                   //returns the name of the item



	int compareTo(const Item& other);
	void print(ostream& out);           //prints out "NAME --> WEIGHT" to the out stream provided
};

