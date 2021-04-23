#include <string>
#include <fstream>

//typedef char ItemType;
using ItemType=char;

struct TreeNode;

#include "QueueType.h"

enum class OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
    TreeType();                    // default constructor
   ~TreeType();                    // destructor
    TreeType(const TreeType& originalTree);        // copy constructor
    void operator=(const TreeType& originalTree);  // copy assignment
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLength() const; 
    ItemType GetItem(ItemType item, bool& found);
    void addItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order); 
    ItemType GetNextItem(OrderType order, bool& finished);
    void Print(std::ofstream& outFile) const;

private:
    TreeNode* root; // type TreeType object node that points to a TreeNode
    QueueType preQueue;
    QueueType inQueue;
    QueueType postQueue;
};

