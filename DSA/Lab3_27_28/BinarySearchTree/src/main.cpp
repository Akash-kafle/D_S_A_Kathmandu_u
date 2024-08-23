#include "../header/binary_tree.h"
#include "../header/Array_BST.h"
#include "../header/Linked_BST.h"

void Main_for_ArrayBst();
void Main_for_LinkedBst();

int main()
{

    Main_for_LinkedBst();
    Main_for_ArrayBst();
    return 0;
}

void Main_for_ArrayBst()
{
    ArrayBinarySearchTree bst;
    std::cout << "Checking if this is empty: " << std::boolalpha << bst.isEmpty() << std::endl;
    std::cout << "Enter the number of elements you want to add: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        bst.addBST(i);
    }

    std::cout << "Checking if this is empty: " << std::boolalpha << bst.isEmpty() << std::endl;
    std::cout << "Searching for 2: " << bst.searchBST(2) << std::endl;
    std::cout << "Searching for 3 * n: " << bst.searchBST(3 * n) << std::endl;
    std::cout << "Searching for n % 10: " << bst.searchBST(n % 10) << std::endl;
    try
    {
        bst.removeBST(2);
    }
    catch (const char *e)

    {
        std::cerr << e << '\n';
    }
    try
    {
        std::cout << "Searching for 2(after removing): " << bst.searchBST(2) << std::endl;
        bst.~ArrayBinarySearchTree();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    try
    {

        std::cout << "Checking if this is empty(after emptying): " << std::boolalpha << bst.isEmpty() << std::endl;
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "trying to search after clearing the tree: " << std::endl;
    try
    {
        bst.searchBST(2);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "trying to remove after clearing the tree: " << std::endl;
    try
    {
        bst.removeBST(2);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "End of Array BST" << std::endl;
    return;
}

void Main_for_LinkedBst()
{

    Linked_BST bst;
    std::cout << "Checking if this is empty: " << std::boolalpha << bst.isEmpty() << std::endl;
    std::cout << "Enter the number of elements you want to add: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        bst.addBST(i);
    }

    std::cout << "Checking if this is empty: " << std::boolalpha << bst.isEmpty() << std::endl;
    std::cout << "Searching for 2: " << bst.searchBST(2) << std::endl;
    std::cout << "Searching for 3: " << bst.searchBST(3 * n) << std::endl;
    std::cout << "Searching for 4: " << bst.searchBST(100 % n) << std::endl;
    try
    {
        bst.removeBST(2);
    }
    catch (const char *e)

    {
        std::cerr << e << '\n';
    }
    try
    {
        std::cout << "Searching for 2(after removing): " << bst.searchBST(2) << std::endl;
        bst.~Linked_BST();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    try
    {

        std::cout << "Checking if this is empty(after emptying): " << std::boolalpha << bst.isEmpty() << std::endl;
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "trying to search after clearing the tree: " << std::endl;
    try
    {
        bst.searchBST(2);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "trying to remove after clearing the tree: " << std::endl;
    try
    {
        bst.removeBST(2);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "End of Linked BST" << std::endl;
    return;
}
