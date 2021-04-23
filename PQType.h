// Definition of class PQType, which represents the Priority Queue ADT

#ifndef PQ_TYPE_H
#define PQ_TYPE_H

// Exception Handlers
class FullPQ {}; // classes that catch errors if we try to add something and we cannot, then we know it is full
class EmptyPQ {}; // try to remove and it is empty throw this

#include "heap.h"

template<typename ItemType>  // can also use template<class ItemType>
class PQType
{
public:
	// priority Queue Class constructors
    PQType(int);          // parameterized class constructor
    ~PQType();            // class destructor

    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.

    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)

    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: if (the priority queue is full) exception FullPQ is thrown;
    //       else newItem is in the queue.

    void Dequeue(ItemType& item);
    // Function: Removes element with highest priority from the queue
    // and returns it in item.
    // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
    //       else highest priority element has been removed from queue.
    //       item is a copy of removed element.
private:
    int length;
    int maxItems;
    HeapType<ItemType> items;
};

template<typename ItemType>
PQType<ItemType>::PQType(int max) : length{ 0 }, 
                                    maxItems{ max }, 
                                    items{ new ItemType[max], 0 }   // the colon allows us to define things outside of our brackets
{
}

template<typename ItemType>
void PQType<ItemType>::MakeEmpty()
{
    length = 0;
}

template<typename ItemType>
PQType<ItemType>::~PQType()
{
    delete[] items.elements;
}

template<typename ItemType>
void PQType<ItemType>::Dequeue(ItemType& item) // item is the key
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
    if (length == 0)
        throw EmptyPQ();
    else
    {
        item = items.elements[0];
        items.elements[0] = items.elements[length - 1];
        length--;
        items.ReheapDown(0, length - 1);
    }
}

template<typename ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is in the queue.
{
    if (length == maxItems)
        throw FullPQ();
    else
    {
        length++;
        items.elements[length - 1] = newItem;
        items.ReheapUp(0, length - 1);
    }
}

template<typename ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
    return length == maxItems;
}

template<typename ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
    return length == 0;
}

#endif
