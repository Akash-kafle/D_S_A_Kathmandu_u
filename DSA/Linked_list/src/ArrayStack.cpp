#include "../header/ArrayStack.h"

void ArrayStack::resize(int newSize)
{
    int *temp = new int[newSize];
    if(newSize < size){
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

void ArrayStack::resize()
{
    resize(size * 2);
}

ArrayStack::ArrayStack()
{
    size = 10;
    list = new int[size];
    top = -1;
}

ArrayStack::~ArrayStack()
{
    delete[] list;
}

void ArrayStack::push(int data)
{
    if (isFull())
    {
        resize();
    }
    list[++top] = data;
}

int ArrayStack::pop()
{
    if (IsEmpty())
    {
        throw "Stack is empty";
    }
    return list[top--];
}

int ArrayStack::Top()
{
    if (IsEmpty())
    {
        throw "Stack is empty";
    }
    return list[top];
}

bool ArrayStack::IsEmpty()
{
    return top == -1;
}

bool ArrayStack::isFull()
{
    return top == size - 1;
}

void ArrayStack::clear()
{
    top = -1;
    resize(10);
}
void ArrayStack::print()
{
    if (IsEmpty())  // if stack is empty
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    
    for (int i = 0; i <= top; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}