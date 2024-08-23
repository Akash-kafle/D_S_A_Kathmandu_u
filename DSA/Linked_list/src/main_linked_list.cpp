#include "..\header\linked_list.h"

int main()
{
    int data{};
    int num{};
    Linked_list List;

    do
    {
        std::cout << "Enter number of node to create: ";
        std::cin >> num;

        if (!std::cin.fail())
        {
            break;
        }
        else if (num < 0)
        {
            std::cout << "Please enter a positive number" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (true);
    std::cout << "\nBefore data adding" << std::endl;
    List.print();

    for (int i = 1; i <= num; i++)
    {
        List.addToTail(i);
    }
    List.addToHead(0);
    List.add(num, 1);
    std::cout << "\nAdded data " << std::endl;
    List.print();

    List.removeFromHead(data);
    std::cout << "\nRemoved data : " << data << std::endl;
    std::cout << "\nAfter removing from head:" << std::endl;
    List.print();
    List.~Linked_list();
    std::cout << "\nAfter deleting the list:" << std::endl;
    List.print();
    return 0;
}