#pragma once
#include "linked_list.h"

class Stack
{

public:
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual int Top() = 0;
    virtual bool IsEmpty() = 0;
};