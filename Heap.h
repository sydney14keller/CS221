#ifndef HEAP_H
#define HEAP_H

// Helper function prototype
template <typename ItemType>
void Swap(ItemType& one, ItemType& two);

template<typename ItemType> // template class
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements{ nullptr };   // Array to be allocated dynamically
    int numElements{ 0 };
};

// Helper function
template <typename ItemType>
void Swap(ItemType& one, ItemType& two)
{
    ItemType temp = one;
    one = two;
    two = temp;
}

template<typename ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
    if (bottom > root)  // if we haven't reached the root yet
    {
        int parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);  // parent is new bottom of subtree
        }
    }
}

template<typename ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
    int maxChild;

    // Determine left and right child indices for current root
    int leftChild = root * 2 + 1;
    int rightChild = root * 2 + 2;

    if (leftChild <= bottom)   // If this is a leaf node
    {
        // If the leftChild is the bottom of the tree, then
        // it's the max child (no right child)
        if (leftChild == bottom)
        {
            maxChild = leftChild;
        }
        else  // there is also a right child, so compare children to find max
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }

        // Compare value at root to value at maxChild and 
        // swap if root value is smaller
        if (elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}


#endif

