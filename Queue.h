// Header file for Queue ADT. 
#include <new>

class FullQueue
{};

class EmptyQueue
{};

//typedef char ItemType; 
using Item = int;

struct NodeType;

class Queue
{
public:
    Queue();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.

    Queue(int max);
    // Parameterized class constructor.

    ~Queue();
    // Class destructor.

    Queue(const Queue& anotherQue);
    // Copy constructor

    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.

    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)

    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

    void Enqueue(Item newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.

    void Dequeue(Item& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.

private:
    NodeType* front;
    NodeType* rear;
};
