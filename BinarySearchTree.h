#include <string>
#include <fstream>

//typedef int Item;
using Item = int;

struct TreeNode
{
    Item info;
    TreeNode* left;
    TreeNode* right;
};

#include "Queue.h"

enum class OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    BinarySearchTree(const BinarySearchTree& originalTree);        // copy constructor
    void operator=(const BinarySearchTree& originalTree);  // copy assignment

    void makeEmpty();
   

    int getLength() const;
    bool isEmpty() const;
    bool isFull() const;

    Item getItem(Item key, bool& found);
    void addItem(Item item);
    void removeItem(Item item);

    void buildQueue(OrderType order);
    Item getNextItem(OrderType order, bool& finished); //dequeue the chosen queue, and return that Item.

    void display(std::ofstream& out) const;
private:
    TreeNode* root;
    int length;
    Queue preQueue;
    Queue inQueue;
    Queue postQueue;
};

