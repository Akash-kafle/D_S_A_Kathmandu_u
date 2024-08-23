#pragma once
#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int a) : data(a), next(NULL) {}
    Node(int a, Node *next_) : data(a), next(next_) {}
};

class Linked_list
{
    Node *Head = nullptr;
    Node *Tail = nullptr;

public:
    bool add(int index, int data);
    bool addToHead(int data);
    bool addToTail(int data);

    bool remove(int data);
    bool removeFromHead(int &data);
    bool removeFromTail(int &data);

    bool IsEmpty();
    bool search(int);

    void retrive(int &, Node *&);

    void print();
    Node *getHead()
    {
        return Head;
    }
    Node *getTail()
    {
        return Tail;
    }
    ~Linked_list();
};