#pragma once
#include <iostream>

class BinarySearchTree
{
public:
    virtual bool isEmpty() = 0;
    virtual void addBST(int data) = 0;
    virtual void removeBST(int key) = 0;
    virtual int searchBST(int key) = 0;
};
