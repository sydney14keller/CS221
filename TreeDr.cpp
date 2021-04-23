// Test driver
#include <iostream>
#include <fstream>
#include <string>

#include "TreeType.h"

// Specify the names we're using from the std namespace, so
// they can be used without the std:: before them
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::cin;

int main()
{ 
    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    string inFileName;     // input file external name
    cin  >> inFileName;
    ifstream inFile{ inFileName };  // file containing operations

    cout << "Enter name of output file; press return." << endl;
    string outFileName;    // output file external name
    cin  >> outFileName;
    ofstream outFile{ outFileName };

    cout << "Enter name of test run; press return." << endl;
    string outputLabel;
    cin  >> outputLabel;
    outFile << outputLabel << endl;

    string command;    // operation to be executed
    inFile >> command;

    TreeType tree;     // Create an empty tree

    // Set up variables to use in the loop
    string orderItem;
    OrderType order;
    char item;
    int numCommands = 0;

    while (command != "Quit")
    { 
        cout << command;
        if (command == "PutItem") {

            inFile >> item; 
            tree.addItem(item);
            outFile << item;
            outFile << " is inserted" << endl;
        }
        else if (command == "DeleteItem") {

            inFile >> item;
            tree.DeleteItem(item);
            outFile << item;
            outFile << " is deleted" << endl;
        }
        else if (command == "GetItem") {

            inFile >> item;

            bool found;
            item = tree.GetItem(item, found);
            if (found) {
                outFile << item << " found in list." << endl;
            }
            else { outFile << item << " not in list." << endl; }
        } 
        else if (command == "GetLength") {

            outFile << "Number of nodes is " << tree.GetLength() << endl;
        }
        else if (command == "IsEmpty") {

            if (tree.IsEmpty()) {
                outFile << "Tree is empty." << endl;
            }
            else { outFile << "Tree is not empty." << endl; }
        }
        else if (command == "PrintTree") {

            tree.Print(outFile);
            outFile << endl;
        }  
        else if (command == "ResetTree") {

            inFile >> orderItem;
            if (orderItem == "PRE_ORDER") {
                order = OrderType::PRE_ORDER;
            }
            else if (orderItem == "IN_ORDER") {
                order = OrderType::IN_ORDER;
            }
            else { order = OrderType::POST_ORDER; }
         
            tree.ResetTree(order);
        }
        else if (command == "GetNextItem") {

            inFile >> orderItem;
            if (orderItem == "PRE_ORDER") {
                order = OrderType::PRE_ORDER;
            }
            else if (orderItem == "IN_ORDER") {
                order = OrderType::IN_ORDER;
            }
            else { order = OrderType::POST_ORDER; }

            bool finished = false;
            item = tree.GetNextItem(order, finished);
            outFile << "Next item is: " << item << endl;
            if (finished) {
                outFile << orderItem << " traversal is complete." << endl;
            }
        }     
        else if (command == "IsFull") {

            if (tree.IsFull()) {
                outFile << "Tree is full." << endl;
            }
            else { outFile << "Tree is not full." << endl; }
        }
        else if (command == "MakeEmpty") {

            tree.MakeEmpty();
            outFile << "Tree has been made empty." << endl;
        }  
        else {
            cout << " Command not recognized." << endl;
        }
        numCommands++;
        cout <<  " Command is completed."  << endl;
        inFile >> command;
    }
 
    cout << "Testing completed."  << endl;
    inFile.close();
    outFile.close();
    return 0;
}




