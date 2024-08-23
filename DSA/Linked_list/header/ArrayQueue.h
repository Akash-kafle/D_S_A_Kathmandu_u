#pragma once

#include <iostream>
#include "Queue.h"

class ArrayQueue : protected Queue
{
private:
    int *list;
    int size{10};
    int front{-1};
    int rear{-1};

    void resize();
    void resize(int newSize);

    bool isFull();

public:
    ArrayQueue();
    ~ArrayQueue();
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    void print();
    int Front();
    int Rear();
    void clear();
};
