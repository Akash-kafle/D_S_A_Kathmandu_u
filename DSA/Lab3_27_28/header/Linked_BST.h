#pragma once
#include "binary_tree.h"

class Node
{
   int data;
   int depth;
   Node *right;
   Node *left;

public:
   void setData(int data)
   {
      this->data = data;
   }
   void setDepth(int depth)
   {
      this->depth = depth;
   }
   void setRight(Node *right)
   {
      this->right = right;
   }
   void setLeft(Node *left)
   {
      this->left = left;
   }

   Node *getRight()
   {
      return right;
   }
   Node *getLeft()
   {
      return left;
   }

   int getData()
   {
      return data;
   }
   int getDepth()
   {
      return depth;
   }
};

class Linked_BST : public BinarySearchTree
{

   Node *root;
   void heapify(Node *node);
   void deleteTree(Node *node)
   {
      if (node == nullptr)
         return;

      deleteTree(node->getLeft());
      deleteTree(node->getRight());
      delete node;
   }
   Node *getSuccessor(Node *node);

public:
   Linked_BST()
   {
      root = nullptr;
   }
   ~Linked_BST()
   {
      deleteTree(root);
      root = nullptr;
   }

   bool isEmpty();
   void addBST(int data);
   void removeBST(int key);
   int searchBST(int key);
};