#pragma once
#include "binary_tree.h"
struct ArrayNode
{
    int data;
};

class ArrayBinarySearchTree : public BinarySearchTree
{
    ArrayNode **data_user = nullptr;
    int nodeCount{};
    int size{};
    int depth{};
    bool resize();
    bool resize(int newSize);
    bool isFull();
    void heapify(int index);

public:
    ArrayBinarySearchTree()
    {
        resize();
    }
    ~ArrayBinarySearchTree()
    {
        for (int i = 0; i < size; i++)
        {
            delete data_user[i];
        }
        delete[] data_user;
        data_user = nullptr;
    }
    bool isEmpty();
    void addBST(int data);
    void removeBST(int key);
    int searchBST(int key);
};
