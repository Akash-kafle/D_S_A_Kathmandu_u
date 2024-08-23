#include "../header/ArrayQueue.h"

void ArrayQueue::resize(int newSize)
{
    int *temp = new int[newSize];
    if (newSize == size)
    {
        return;
    }
    if (newSize < size)
    {
        rear = newSize - 1;
        size = newSize;
    }
    for (int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    size = newSize;
}

ArrayQueue::ArrayQueue()
{
    list = new int[size];
}

ArrayQueue::~ArrayQueue()
{
    delete[] list;
}

void ArrayQueue::enqueue(int data)
{
    if (isFull())
    {
        resize();
    }
    list[++rear] = data;
}

int ArrayQueue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw "Queue is empty";
    }
    return list[++front];
}

bool ArrayQueue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

void ArrayQueue::print()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    for (int i = front + 1; i <= rear; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int ArrayQueue::Front()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw "Queue is empty";
    }
    return list[front + 1];
}

int ArrayQueue::Rear()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        throw "Queue is empty";
    }
    return list[rear];
}

void ArrayQueue::clear()
{
    front = rear = -1;
    delete list;
}

bool ArrayQueue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void ArrayQueue::resize()
{
    int *temp = new int[size * 2];
    for (int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
    size *= 2;
}
