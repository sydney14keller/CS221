// PASS-Bill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream> 
using std::cout; using std::endl;
using std::string;



int main()
{













	//std::string* list;//dynamic array
	//list = new std::string;//dynamic array
	Bill starbucks;
	starbucks.addItem(10.99);
	starbucks.addItem(9.99);
	starbucks.addItem(8.99);
	starbucks.addItem(10.99);
	starbucks.addItem(9.99);
	starbucks.addItem(8.99);
	starbucks.addItem(10.99);
	starbucks.addItem(9.99);
	starbucks.addItem(8.99);
	starbucks.addItem(10.99);
	
	std::string inFileName;
    std::cout << "What is the name of the file?" << std::endl;
	std::cin >> inFileName;
	std::string line;
	std::ifstream inFile;
	inFile.open(inFileName);

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			starbucks.addItem(stod(line));
		}
	}

	std::string outFileName;
    std::cout << "Outfile name?" << std::endl;
	std::cin >> outFileName;
	std::ofstream outFile;
	outFile.open(outFileName);
	outFile << " Hello " << std::endl;
	starbucks.print(outFile);
	starbucks.print(std::cout);
	inFile.clear();
	inFile.close();











}



//create an item class 
//think about attributes and methods it might have and try to implement them