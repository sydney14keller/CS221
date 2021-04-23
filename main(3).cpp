// Test driver
#include <iostream>
#include <fstream>
#include <string>

#include "BinarySearchTree.h"

// Specify the names we're using from the std namespace, so
// they can be used without the std:: before them
using std::string;
using std::ifstream; using std::ofstream;
using std::endl; using std::cout;
using std::cin;

int main()
{

    BinarySearchTree tree;     // Create an empty tree

    string orderItem;
    OrderType order;

    Item item = 10;

    tree.addItem(item);


    
    return 0;
}




