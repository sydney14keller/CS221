#include "TreeType.h"

struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};


bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
    TreeNode* location;
    try
    {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
    return root == nullptr;
}

int CountNodes(TreeNode* tree);

int TreeType::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
    return CountNodes(root);
}

int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
    if (!tree) {  //tree == nullptr
        return 0;
    }
    else {
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
    }
}

void Retrieve(TreeNode* tree, ItemType& item, bool& found);

ItemType TreeType::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
    Retrieve(root, item, found);
    return item;
}


void Retrieve(TreeNode* tree, ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
    if (!tree) {  // tree == nullptr
        found = false;                     // item is not found.
    }
    else if (item < tree->info) {
        Retrieve(tree->left, item, found); // Search left subtree.
    }
    else if (item > tree->info) {
        Retrieve(tree->right, item, found);// Search right subtree.
    }
    else {
        item = tree->info;                 // item is found.
        found = true;
    }
} 

void Insert(TreeNode*& tree, ItemType item);

void TreeType::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
    Insert(root, item);
}


void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
    if (!tree)  // tree == nullptr
    {// Insertion place found.
        tree = new TreeNode;
        tree->right = nullptr;
        tree->left = nullptr;
        tree->info = item;
    }
    else if (item < tree->info) {
        Insert(tree->left, item);    // Insert in left subtree.
    }
    else {
        Insert(tree->right, item);   // Insert in right subtree.
    }
} 

void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
    Delete(root, item);
}


void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
    if (item < tree->info) {
        Delete(tree->left, item);   // Look in left subtree.
    }
    else if (item > tree->info) {
        Delete(tree->right, item);  // Look in right subtree.
    }
    else {
        DeleteNode(tree);           // Node found; call DeleteNode.
    }
}   

void GetPredecessor(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
    ItemType data;
    TreeNode* tempPtr;

    tempPtr = tree;
    if (!tree->left) // tree->left == nullptr
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (!tree->right) // tree->right == nullptr
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);  // Delete predecessor node.
    }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
    while (tree->right) { // tree->right != nullptr
        tree = tree->right;
    }
    data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile) 
// Prints info member of items in tree in sorted order on outFile.
{
    if (tree) // tree != nullptr
    {
        PrintTree(tree->left, outFile);   // Print left subtree.
        outFile << tree->info;
        PrintTree(tree->right, outFile);  // Print right subtree.
    }
}

void TreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
    PrintTree(root, outFile);
}

TreeType::TreeType() : root{ nullptr }
{
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
    Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
    if (tree) // tree != nullptr
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

void TreeType::MakeEmpty()
{
    Destroy(root);
    root = nullptr;
}


void CopyTree(TreeNode*& copy, const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
    CopyTree(root, originalTree.root);
}

void TreeType::operator=(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{

    if (&originalTree == this) {
        return;             // Ignore assigning self to self
    }
    Destroy(root);      // Deallocate existing tree nodes
    CopyTree(root, originalTree.root);

}
void CopyTree(TreeNode*& copy, const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
    if (!originalTree) { // originalTree == nullptr
        copy = nullptr;
    }
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueueType&);
// Enqueues tree items in preorder.

void InOrder(TreeNode*, QueueType&);
// Enqueues tree items in inorder.

void PostOrder(TreeNode*, QueueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
    switch (order)
    {
    case OrderType::PRE_ORDER : PreOrder(root, preQueue);
                                break;
    case OrderType::IN_ORDER  : InOrder(root, inQueue);
                                break;
    case OrderType::POST_ORDER: PostOrder(root, postQueue);
                                break;
    }
}


void PreOrder(TreeNode* tree, QueueType& preQue)
// Post: preQue contains the tree items in preorder.
{
    if (tree) // tree != nullptr
    {
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}


void InOrder(TreeNode* tree, QueueType& inQueue)
// Post: inQueue contains the tree items in inorder.
{
    if (tree) // tree != nullptr
    {
        InOrder(tree->left, inQueue);
        inQueue.Enqueue(tree->info);
        InOrder(tree->right, inQueue);
    }
}


void PostOrder(TreeNode* tree, QueueType& postQueue)
// Post: postQueue contains the tree items in postorder.
{
    if (tree) // tree != nullptr
    {
        PostOrder(tree->left, postQueue);
        PostOrder(tree->right, postQueue);
        postQueue.Enqueue(tree->info);
  }
}


ItemType TreeType::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
    finished = false;
    ItemType item;
    QueueType queue;
    switch (order)
    {
    case OrderType::PRE_ORDER : 
            preQueue.Dequeue(item);
            if (preQueue.IsEmpty())
                finished = true;
            break;
    case OrderType::IN_ORDER : 
            inQueue.Dequeue(item);
            if (inQueue.IsEmpty())
                finished = true;
            break;
    case  OrderType::POST_ORDER : 
            postQueue.Dequeue(item);
            if (postQueue.IsEmpty())
                finished = true;
            break;
    }
    return item;
}



