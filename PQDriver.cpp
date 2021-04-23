// Test driver
#include <iostream>
#include <fstream>

#include "PQType.h"

using ItemType = int;

int main()
{    
    // Prompt for file names, read file names, and prepare files
    std::cout << "Enter name of input command file; press return." << std::endl;
    std::string inFileName;
    std::cin  >> inFileName;
    std::ifstream inFile{ inFileName };

    std::cout << "Enter name of output file; press return." << std::endl;
    std::string outFileName;
    std::cin  >> outFileName;
    std::ofstream outFile{ outFileName };

    std::cout << "Enter name of test run; press return." << std::endl;
    std::string outputLabel;
    std::cin  >> outputLabel;
    outFile << outputLabel << std::endl;


    // Set up the priority queue and an item to use when processing commands
    PQType<ItemType> queue{ 5 };
    ItemType item;

    std::string command;  // operation to be executed
    inFile >> command;    // read the first command from the input file

    // Read commands from the file until you reach the command "Quit"
    int numCommands = 0;
    while (command != "Quit")
    { 
        try 
        {
            if (command == "Enqueue")
            {
                inFile >> item; 
                queue.Enqueue(item);
                outFile << item << " is enqueued." << std::endl;
            }
            else if (command == "Dequeue")
            {
                queue.Dequeue(item); 
                outFile<< item  << " is dequeued. " << std::endl;
            } 
            else if (command == "IsEmpty") 
            {
                if (queue.IsEmpty())
                    outFile << "Queue is empty." << std::endl;
                else
                    outFile << "Queue is not empty." << std::endl;
            }
            else if (command == "IsFull") 
            {
                if (queue.IsFull())
                    outFile << "Queue is full." << std::endl;
                else outFile << "Queue is not full." << std::endl;
            }
            else if (command == "MakeEmpty") 
            {
                queue.MakeEmpty();
            }
        }
        catch (FullPQ)
        {
            outFile << "FullQueue exception thrown." << std::endl;
        }
    
        catch (EmptyPQ)
        {
            outFile << "EmtpyQueue exception thrown." << std::endl;
        }    
        numCommands++;
        std::cout << " Command number " << numCommands << " completed.\n";
        inFile >> command;
    }
 
    std::cout << "Testing completed."  << std::endl;
    inFile.close();
    outFile.close();
    return 0;
}


