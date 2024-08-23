#include <iostream>

template <typename T>
class Node
{
    int key;
    T data;
    Node *right = nullptr;
    Node *left = nullptr;

public:
    T getData() { return data; }
    Node<T> *getRight() { return right; }
    Node<T> *getLeft() { return left; }
    void setRight(Node<T> *node) { right = node; }
    void setLeft(Node<T> *node) { left = node; }
    void setData(T a) { data = a; }
    void setKey(int a) { key = a; }
};

template <typename D>
class binarytree
{
    Node<D> *Tree = nullptr;

public:
    void reHeap(Node<D> *);
    Node<D> *smallest(Node<D> *);
    Node<D> *largest(Node<D> *);
};

template <typename D>
Node<D> *binarytree<D>::smallest(Node<D> *root)
{
    if (root->getLeft() != nullptr)
    {
        return smallest(root->getLeft());
    }
    return root;
}

template <typename D>
Node<D> *binarytree<D>::largest(Node<D> *root)
{
    if (root->getRight() != nullptr)
    {
        return largest(root->getRight());
    }
    return root;
}
template <typename D>
void binarytree<D>::reHeap(Node<D> *root)
{
    Node<D> *small = smallest(root);
    // small->setLeft(root->getLeft());
    // small->setRight(root->getLeft());
    root->setData(small->getData());
    if (root->getLeft() == nullptr && root->getRight() == nullptr)
    {
        return;
    }
    if (root->getLeft() != nullptr && root->getData() < root->getLeft()->getData())
    {
        D temp = root->getData();
        root->setData(root->getLeft()->getData());
        root->getLeft()->setData(temp);
        reHeap(root->getLeft());
    }
    else if (root->getRight() != nullptr && root->getData() > root->getRight()->getData())
    {
        D temp = root->getData();
        root->setData(root->getRight()->getData());
        root->getRight()->setData(temp);
        reHeap(root->getRight());
    }
}
