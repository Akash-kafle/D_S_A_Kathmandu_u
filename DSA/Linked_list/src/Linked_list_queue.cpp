#include "../header/Linked_list_queue.h"

void LinkedQueue::clear()
{
    if (isEmpty())
    {
        return;
    }

    front->~Linked_list();
    delete front;
    front = nullptr;
    rear = nullptr;
}

void LinkedQueue::enqueue(int data)
{
    front->addToTail(data);
    rear = front->getHead();
}

int LinkedQueue::dequeue()
{
    int data{};
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw "Queue is empty";
    }

    if (!front->IsEmpty())
    {
        std::cout << "Dequeue: " << front->getHead()->data << std::endl;
        if (front->removeFromHead(data))
        {

            rear = front->getHead();
            return data;
        }
        throw "Error in dequeue";
    }
    throw "Error in dequeue";
}

bool LinkedQueue::isEmpty()
{
    if (front == nullptr || front->IsEmpty())
    {
        return true;
    }
    return false;
}

void LinkedQueue::print()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    front->print();
}

int LinkedQueue::Front()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw "Queue is empty";
    }
    return front->getTail()->data;
}

int LinkedQueue::Rear()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw "Queue is empty";
    }
    return rear->data;
}