#include "Queue.h"
#include "linked_list.h"
#include <iostream>

class LinkedQueue : protected Queue
{
public:
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    void print();
    int Front();
    int Rear();
    void clear();
    ~LinkedQueue()
    {
        front->~Linked_list();
        delete front;
    }

private:
    Linked_list *front = new Linked_list;
    Node *rear;
};