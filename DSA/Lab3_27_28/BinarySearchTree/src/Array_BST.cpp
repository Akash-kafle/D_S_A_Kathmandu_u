#include "../header/Array_BST.h"
#include <math.h>

// Check if the tree is empty
bool ArrayBinarySearchTree::isEmpty()
{
    if (data_user == nullptr || nodeCount == 0)
    {
        return true;
    }
    return false;
}

// Check if the tree is full
bool ArrayBinarySearchTree::isFull()
{
    if (nodeCount == size - 1)
    {
        return true;
    }
    return false;
}

// Add the given element to the tree
void ArrayBinarySearchTree::addBST(int data)
{
    if (data_user == nullptr || isFull())
    {
        if (!resize())
        {
            throw "Error allocating space";
        }
    }
    nodeCount++;
    if (nodeCount == 0)
    {
        data_user[0] = new ArrayNode;
        data_user[0]->data = data;
        depth = 0;
        return;
    }
    depth = static_cast<int>(log2(nodeCount));

    int i{1};
    while (i <= size)
    {
        int left = 2 * i;
        int right = left + 1;
        if (left >= size)
        {
            resize();
        }
        if (data_user[left] == nullptr)
        {
            data_user[left] = new ArrayNode;
            data_user[left]->data = data;
            std::cout << "Added to " << left << std::endl;
            return;
        }
        if (right >= size)
        {
            resize();
        }
        if (data_user[right] == nullptr)
        {
            data_user[right] = new ArrayNode;
            data_user[right]->data = data;
            std::cout << "Added to " << right << std::endl;
            return;
        }
        i++;
    }
}

// Remove the given element from the tree
void ArrayBinarySearchTree::removeBST(int key)
{
    if (isEmpty())
    {
        throw "Empty tree cannot be removed";
    }
    int i;
    // Find the index of the node with the given key
    for (i = 0; i < size; i++)
    {
        if (data_user[i] && data_user[i]->data == key)
        {
            break;
        }
    }

    if (i < size && data_user[i])
    {
        // Replace the node to be removed with the last node
        auto temp = data_user[size - 1];
        data_user[size - 1] = data_user[i];
        data_user[i] = temp;

        // Delete the last node
        delete data_user[size - 1];
        data_user[size - 1] = nullptr;
        nodeCount--;

        // Re-balance the tree
        heapify(i);
        return;
    }
    throw "Key not found";
}

// Search for the given element in the tree
int ArrayBinarySearchTree::searchBST(int key)
{
    if (isEmpty())
    {
        throw "Empty tree cannot be searched";
    }
    int left = 0;
    int right = size - 1;
    // Binary search using iterative approach
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (data_user[mid] != nullptr && data_user[mid]->data == key) // Key found
        {
            return mid;
        }
        else if (data_user[mid] != nullptr && data_user[mid]->data < key) // Search in the right subtree
        {
            left = mid + 1;
        }
        else // Search in the left subtree
        {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

// Helper function to resize the array
bool ArrayBinarySearchTree::resize()
{
    return resize(0);
}

// main function to resize the array
bool ArrayBinarySearchTree::resize(int temp_size)
{
    try
    {
        if (data_user == nullptr)
        {
            data_user = new ArrayNode *[10]; // Initial size of the array
            size = 10;                       // Storing size of the array
            for (int i = 0; i < 10; i++)
            {
                data_user[i] = nullptr; // Initialize all the pointers to nullptr
            }
            return true;
        }
        if (temp_size == 0) // If the size is not specified
        {
            temp_size = (1 << (depth + 1)) + 1; // Calculate the size of the array
            depth++;                            // Increase the depth
        }

        ArrayNode **temp = new ArrayNode *[temp_size]; // Allocate new array
        for (int i = 0; i < temp_size; i++)
        {
            temp[i] = nullptr; // Initialize all the pointers to nullptr
        }

        for (int i = 0; i < size; i++)
        {
            temp[i] = data_user[i]; // Copy the data to the temporary pointer array
        }

        delete[] data_user; // Delete the old array
        data_user = temp;   // Assign the new array to data_user
        size = temp_size;   // Update the size

        return true;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }
}

void ArrayBinarySearchTree::heapify(int index)
{

    // Implement heapify to maintain the binary search tree property
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && data_user[left] && data_user[smallest] && data_user[left]->data < data_user[smallest]->data)
    {
        smallest = left;
    }

    if (right < size && data_user[right] && data_user[smallest] && data_user[right]->data < data_user[smallest]->data)
    {
        smallest = right;
    }

    if (smallest != index)
    {
        auto temp = data_user[index];
        data_user[index] = data_user[smallest];
        data_user[smallest] = temp;
        heapify(smallest);
    }
}