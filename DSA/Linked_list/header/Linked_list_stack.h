#pragma once
#include "Stack.h"

class LinkedStack : protected Stack
{
protected:
    Linked_list stack;

public:
    void push(int);
    int pop();
    int Top();
    bool IsEmpty();
    void clear();
    void print();
};