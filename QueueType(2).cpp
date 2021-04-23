#include <new>                     // For bad_alloc
#include "QueueType(2).h"


// we have the queue to make it easier to display the output of the tree  FIFO ONLY FOR DEMONSTRATION 
struct NodeType
{
    ItemType info;
    NodeType* next;
};


QueueType::QueueType()          // Class constructor.
// Post:  front and rear are set to NULL.
{
    front = nullptr;
    rear = nullptr;
}


void QueueType::MakeEmpty()
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
QueueType::~QueueType()
{
    MakeEmpty();
}


bool QueueType::IsFull() const
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
    catch(std::bad_alloc)
    {
        return true;
    }
}


bool QueueType::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    return (front == nullptr);
}


void QueueType::Enqueue(ItemType newItem)
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

void QueueType::Dequeue(ItemType& item)
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

QueueType::QueueType(const QueueType& anotherQueue)
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
