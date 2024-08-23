#include "../header/Linked_list_stack.h"
#include "../header/Stack.h"
#include <iostream>

void LinkedStack::push(int data)
{
    stack.addToHead(data);
}

int LinkedStack::pop()
{
    if (!stack.IsEmpty())
    {
        int data{};
        stack.removeFromHead(data);
        return data;
    }
    throw "Empty";
}

int LinkedStack::Top()
{
    if (!stack.IsEmpty())
    {
        Node *Head = stack.getHead();
        return Head->data;
    }
    throw "Empty";
}

bool LinkedStack::IsEmpty()
{
    return stack.IsEmpty();
}

void LinkedStack::clear()
{
    stack.~Linked_list();
}

void LinkedStack::print()
{
    stack.print();
}