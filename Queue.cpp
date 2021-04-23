#include <new>                     // For bad_alloc
#include "Queue.h"

struct NodeType
{
    Item info;
    NodeType* next;
};


Queue::Queue()          // Class constructor.
// Post:  front and rear are set to NULL.
{
    front = nullptr;
    rear = nullptr;
}


void Queue::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
    NodeType* tempPtr;

    while (front)  // front != nullptr
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = nullptr;
}

// Class destructor.
Queue::~Queue()
{
    MakeEmpty();
}


bool Queue::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }
}


bool Queue::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    return (front == nullptr);
}


void Queue::Enqueue(Item newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
    if (IsFull()) {
        throw FullQueue();
    }
    else
    {
        NodeType* newNode;

        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = nullptr;
        if (!rear) { // rear == nullptr
            front = newNode;
        }
        else {
            rear->next = newNode;
        }
        rear = newNode;
    }
}

void Queue::Dequeue(Item& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty()) {
        throw EmptyQueue();
    }
    else
    {
        NodeType* tempPtr;

        tempPtr = front;
        item = front->info;
        front = front->next;
        if (!front) { // front == nullptr
            rear = nullptr;
        }
        delete tempPtr;
    }
}

Queue::Queue(const Queue& anotherQueue)
// Copy Constructor
{
    NodeType* ptr1 = nullptr;
    NodeType* ptr2 = nullptr;

    front = nullptr;
    rear = nullptr;

    //if (!(anotherQueue.front)) {
    //    front = nullptr;
    //    rear = nullptr;
    //}
    //else
    if (anotherQueue.front)
    {
        front = new NodeType;
        front->info = anotherQueue.front->info;
        ptr1 = anotherQueue.front->next;
        ptr2 = front;
        while (ptr1)  // ptr1 != nullptr
        {
            ptr2->next = new NodeType;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = nullptr;
        rear = ptr2;
    }
}
