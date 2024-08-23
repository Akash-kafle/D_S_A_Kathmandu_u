#include "..\header\linked_list.h"

// this is a simple implementation of a basic linked list

// this function adds to the provided index if the index exists otherwise adds to tail or head as necessary
bool Linked_list::add(int index, int data)
{
    if (this->IsEmpty()) // Checking if list is empty
    {
        std::cout << "The list is empty and added at head" << std::endl;
        addToHead(data); // Adding to head if list is empty
    }
    Node *temp = Head;
    int i = 0;
    while (temp != nullptr) // a loop for traversing the list
    {
        if (i == index) // Checking if current index matches the provided index
        {
            Node *temp = new Node; // Creating a new node
            temp->data = data;     // Assigning data to the new node
            temp->next = Head;     // Setting the next pointer of the new node to the current head
            Head = temp;           // Updating the head to point to the new node
            std::cout << "Success" << std::endl;
            return true;
        }
        temp = temp->next; // Moving to the next node
        i++;               // Incrementing the index counter
    }
    std::cout << "The list only goes up to " << i << " therefore added at tail" << std::endl;
    if (addToTail(data)) // Adding to tail if index is greater than the list size
    {
        return true;
    }
    std::cout << "Failed to add" << std::endl;
    return false;
}

// this function adds a new node with the provided data at the head of the linked list
bool Linked_list::addToHead(int data)
{

    if (this->IsEmpty()) // Checking if list is empty
    {
        Node *temp = new Node; // Creating a new node
        temp->data = data;     // Assigning data to the new node
        temp->next = nullptr;  // Setting the next pointer of the new node to nullptr
        Head = temp;           // Updating the head to point to the new node
        Tail = temp;           // Updating the tail to point to the new node
        std::cout << "Success" << std::endl;
        return true;
    }
    else
    {
        Node *temp = new Node; // Creating a new node
        temp->data = data;     // Assigning data to the new node
        temp->next = Head;     // Setting the next pointer of the new node to the current head
        Head = temp;           // Updating the head to point to the new node
        std::cout << "Success" << std::endl;
        return true;
    }
    return false;
}

// this function adds a new node with the provided data at the tail of the linked list
bool Linked_list::addToTail(int data)
{
    if (this->IsEmpty()) // Checking if list is empty
    {
        Node *temp = new Node; // Creating a new node
        temp->data = data;     // Assigning data to the new node
        temp->next = nullptr;  // Setting the next pointer of the new node to nullptr
        Head = temp;           // Updating the head to point to the new node
        Tail = temp;           // Updating the tail to point to the new node
        std::cout << "Success" << std::endl;
        return true;
    }
    else
    {
        Node *temp = new Node; // Creating a new node
        temp->data = data;     // Assigning data to the new node
        temp->next = nullptr;  // Setting the next pointer of the new node to nullptr
        Tail->next = temp;     // Setting the next pointer of the current tail to the new node
        Tail = temp;           // Updating the tail to point to the new node
        std::cout << "Success" << std::endl;
        return true;
    }
    return false;
}

// this function removes the first occurrence of the node with the provided data from the linked list
bool Linked_list::remove(int data)
{
    Node *temp = Head;
    if (!this->IsEmpty()) // Checking if list is not empty
    {
        while (temp != nullptr && temp->next->data != data) // Searching for the node with the provided data
        {
            temp = temp->next; // Moving to the next node
        }
        if (nullptr != temp) // Checking if the node with the provided data is found
        {
            Node *node_to_delete = temp->next; // Storing the node to be deleted
            temp->next = node_to_delete->next; // Updating the next pointer of the previous node
            try
            {
                delete node_to_delete; // Deleting the node
                return true;
            }
            catch (std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return false;
            }
        }
    }
    else
    {
        std::cout << "The list is empty" << std::endl;
        return false;
    }
    std::cout << "There is no such data " << std::endl;
    return false;
}

// this function removes the node at the head of the linked list and returns its data
bool Linked_list::removeFromHead(int &data)
{
    if (!this->IsEmpty()) // Checking if list is not empty
    {
        Node *temp = Head;   // Storing the current head
        Head = Head->next;   // Updating the head to point to the next node
        data = temp->data;   // Storing the data of the to be removed node
        if (Head == nullptr) // Checking if the list becomes empty after removal
        {
            Tail = nullptr; // Updating the tail to nullptr
        }
        try
        {
            delete temp; // Deleting the node
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return false;
        }
        return true;
    }
    return false;
}

// this function removes the node at the tail of the linked list and returns its data
bool Linked_list::removeFromTail(int &data)
{
    if (!this->IsEmpty()) // Checking if list is not empty
    {
        Node *temp = Head;            // Storing the current head
        Node *node_to_delete = Tail;  // Storing the current tail
        data = Tail->data;            // Storing the data of the to be removed node
        while (temp->next != nullptr) // Traversing the list to find the previous node of the tail
        {
            temp = temp->next; // Moving to the next node
        }
        Tail = temp;      // Updating the tail to point to the previous node
        if (Head == temp) // Checking if the list becomes empty after removal
        {
            Tail = nullptr; // Updating the tail to nullptr
            Head = nullptr; // Updating the head to nullptr
        }
        else
        {
            temp->next = nullptr; // Updating the next pointer of the previous node to nullptr
        }

        try
        {
            delete node_to_delete; // Deleting the node
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return false;
        }

        return true;
    }
    return false;
}

// this function checks if the linked list is empty
bool Linked_list::IsEmpty()
{
    return (Head == nullptr && Tail == nullptr); // Checking if both head and tail are nullptr and returning the result of the comparison
}

// this function searches for the node with the provided data

bool Linked_list::search(int data)
{
    // Traversing the list to search for the node with the provided data
    Node *temp = Head;
    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            return true; // Node with the provided data found
        }
        temp = temp->next; // Moving to the next node
    }
    return false; // Node with the provided data not found
}

// this function retrieves the pointer to the node with the provided data

void Linked_list::retrive(int &data, Node *&OutPointer)
{
    if (!this->IsEmpty()) // Checking if list is not empty
    {
        Node *temp = Head;                            // Storing the current head
        while (temp != nullptr && temp->data != data) // Searching for the node with the provided data
        {
            temp = temp->next; // Moving to the next node
        }
        if (nullptr != temp) // Checking if the node with the provided data is found
        {
            OutPointer = temp; // Storing the pointer to the node with the provided data
            return;            // Returning after finding the node
        }
    }
    OutPointer = nullptr; // Setting the pointer to nullptr if the node with the provided data is not found
}

// this function prints the data of each node in the linked list
void Linked_list::print()
{
    if (this->IsEmpty()) // Checking if list is empty
    {
        std::cout << "Empty" << std::endl;
    }
    Node *temp = this->Head;
    while (temp != nullptr) // Traversing the list
    {
        std::cout << "data : " << temp->data << std::endl; // Printing the data of each node
        temp = temp->next;                                 // Moving to the next node
    }
}

// destructor for the Linked_list class
Linked_list::~Linked_list()
{
    int data;
    int counter{};
    if (this->IsEmpty()) // Checking if list is empty
    {
        return;
    }
    this->removeFromHead(data); // Removing nodes from head until the list becomes empty
    this->~Linked_list();       // Calling the destructor recursively
}