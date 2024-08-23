#include "Stack.h"

class ArrayStack : public Stack
{
private:
    int *list;
    int size{10};
    int top{-1};

    void resize();
    void resize(int newSize);

public:
    ArrayStack();
    ~ArrayStack();
    void push(int data);
    int pop();
    int Top();
    bool IsEmpty();
    bool isFull();
    void clear();
    void print();
};
