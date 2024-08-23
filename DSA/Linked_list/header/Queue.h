class Queue
{
public:
    virtual void enqueue(int data) = 0;
    virtual int dequeue() = 0;
    virtual int Front() = 0;
    virtual int Rear() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
    virtual void clear() = 0;
};