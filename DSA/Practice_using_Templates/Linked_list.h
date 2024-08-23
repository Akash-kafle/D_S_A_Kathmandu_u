#include <iostream>
#include <algorithm>
template <typename D>
class Node
{
    D data;
    Node *next;
};

template <typename T>
class Linked_list
{
    Node<T> *List;

public:
    Linked_list()
    {
    }
    ~Linked_list()
    {
        while (List != nullptr)
        {
            auto node_to_delete = List;
            List = List->next;
            delete node_to_delete;
        }
    }
    void addToHead(T);
    void addToTail(T);
    void add(Node<T> *, T);
    int remove(T);
    void removeFromTail();
    void removeFromHead();
    bool search(T);
    Node<T> *retrive(T);
    void traverse();
};

// Add to the front of the list
template <typename T>
void Linked_list<T>::addToHead(T data)
{
    Node<T> *temp = new Node<T>;
    temp->data = data;
    if (List == nullptr)
    {
        List = temp;
        List->next = temp = nullptr;
        return;
    }
    temp->next = List;
    List = temp;
    temp = nullptr;
}

// Add to the end of the list
template <typename T>
void Linked_list<T>::addToTail(T data)
{
    Node<T> temp = new Node<T>;
    temp->data = data;
    if (List == nullptr)
    {
        List = temp;
        List->next = temp = nullptr;
        return;
    }
    Node<T> *temp1 = List;
    while (temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp1->next = temp = nullptr;
}

// Add data after the provided node
template <typename T>
void Linked_list<T>::add(Node<T> *previous, T data)
{
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = nullptr;
    // Without any if

    // previous = previous == nullptr ? temp : previous;
    auto temp1 = previous->next;
    // previous->next = temp1 == nullptr ? nullptr : temp;
    // temp->next = previous == temp ? nullptr : temp1;

    if (previous == nullptr)
    {
        previous = temp;
        return;
    }
    previous->next = temp;
    temp->next = temp1;
    temp1 = temp = nullptr;
}

// Returns if removed -> 0, error -> 1, not found -> -1;
template <typename T>
int Linked_list<T>::remove(T data)
{
    auto traverse = List;
    auto prev = traverse;
    while (traverse != nullptr)
    {
        if (traverse->data == data)
        {
            break;
        }
        traverse = traverse->next;
        if (traverse != nullptr && traverse->data != data)
        {
            prev = traverse;
        }
    }
    if (traverse == nullptr)
    {
        return -1;
    }
    try
    {
        prev->next = traverse->next;
        delete traverse;
        traverse = prev = nullptr;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}

// Removes from the tail of the list
template <typename T>
void Linked_list<T>::removeFromTail()
{
    auto traverse = List;
    auto prev = traverse;
    while (traverse != nullptr)
    {
        traverse = traverse->next;
        if (traverse != nullptr)
        {
            prev = traverse;
        }
    }
    if (traverse == nullptr)
    {
        return -1;
    }
    try
    {
        prev->next = traverse->next;
        delete traverse;
        traverse = prev = nullptr;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}

template <typename T>
void Linked_list<T>::removeFromHead()
{
    auto temp = List;
    if (temp == nullptr)
    {
        return;
    }

    List = List->next;
    delete temp;
    temp = nullptr;
}

template <typename T>
bool Linked_list<T>::search(T data)
{
    auto temp = List;
    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
Node<T> *Linked_list<T>::retrive(T data)
{
    auto temp = List;
    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

template <typename T>
void Linked_list<T>::traverse()
{
    auto temp = List;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}
