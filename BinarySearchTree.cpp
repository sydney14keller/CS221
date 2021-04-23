#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
    length = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    destroy(root);
}

void destroy(TreeNode*& tree)
{
    if (tree) //tree != nullptr
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

void BinarySearchTree::makeEmpty()
{
    destroy(root);
    root = nullptr;
    length = 0;
}

int BinarySearchTree::getLength() const
{
    return length;
}


bool BinarySearchTree::isEmpty() const
{
    if (root == nullptr) // if length == 0
    {
        return true;
    }
}
bool BinarySearchTree::isFull() const
{
    TreeNode* location;
    try
    {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

// must mention preOrder, inOrder, postOrder 
// function definitions
// helper functions
void preOrder(TreeNode* tree, Queue& que);
void inOrder(TreeNode* tree, Queue& que);
void postOrder(TreeNode* tree, Queue& que);
void remove(TreeNode*& node, Item& item);

void BinarySearchTree::buildQueue(OrderType order)
{
    switch (order)
    {
    case OrderType::PRE_ORDER: preOrder(root, preQueue);
        break;
    case OrderType::IN_ORDER: inOrder(root, inQueue);
        break;
    case OrderType::POST_ORDER: postOrder(root, postQueue);
        break;
    }
}


void preOrder(TreeNode* tree, Queue& que)
{
    if (tree) //tree != nullptr
    {
        que.Enqueue(tree->info);
        preOrder(tree->left, que);
        preOrder(tree->right, que);
    }
}

void inOrder(TreeNode* tree, Queue& que)
{
    if (tree) //tree != nullptr
    {
        inOrder(tree->left, que);
        que.Enqueue(tree->info);
        inOrder(tree->right, que);
    }
}
void postOrder(TreeNode* tree, Queue& que)
{
    if (tree) //tree != nullptr
    {
        postOrder(tree->left, que);
        postOrder(tree->right, que);
        que.Enqueue(tree->info);
    }
}

void BinarySearchTree::display(std::ofstream& out) const	// wrapper function
{
    printTree(root, out); // trying to manipulate private variables bc te root is hidden so it won't be messed up
						  // root is passed in bc it is the starting point
}

void printTree(TreeNode* tree, std::ofstream& out)  // tree is the tree node(root)
// Prints info member of items in tree in sorted order on outFile.
{
    if (tree) // tree != nullptr    if(the tree / root exists)
    {
        printTree(tree->left, out);   // Print left subtree.
        out << tree->info;            // Print middle subtree
        printTree(tree->right, out);  // Print right subtree.
    }
}

void printTree(TreeNode* tree, std::ofstream& out, OrderType order)
// Prints info member of items in tree in sorted order on outFile.
{
    if (tree) // tree != nullptr
    {
        printTree(tree->left, out);   // Print left subtree.
        out << tree->info;
        printTree(tree->right, out);  // Print right subtree.
    }
}

void insert(TreeNode*& node, Item& item) // node is the same as our root 
{
	// base case when the empty spot to put the newItem into is null

	if (node == nullptr) // we've found the insertion place
	{
		node = new TreeNode;
		node->right = nullptr;
		node->left = nullptr;
		node->info = item; // set the root to item
	}

	else if (item < node->info)
	{
		insert(node->left, item); // now node our root and we go to the left side of the root and keep checking recursively since the item is less than root
	}

	else // item = node->info
	{
		insert(node->right, item); // item is places automatically to the right if all the other tests fail
	}

}


void remove(Tree*& node, Item& item)
{
	// how do we know how to do this IMPORTANT

}