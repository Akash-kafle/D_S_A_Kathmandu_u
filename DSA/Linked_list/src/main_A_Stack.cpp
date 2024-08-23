#include "../header/ArrayStack.h"

int main()
{
    ArrayStack stack;
    int user_input;
    do
    {
        std::cout << "Enter number of data: ";
        std::cin >> user_input;

        if (!std::cin.fail())
        {
            break;
        }
        else if (user_input < 0)
        {
            std::cout << "Please enter a positive number" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (true);
    try
    {
        std::cout << "Popping an empty stack" << std::endl;
        std::cout << stack.pop() << std::endl;
    }
    catch (const char *a)
    {
        std::cerr << a << std::endl;
    }
    for (int i = 0; i < user_input; i++)
    {
        stack.push(i + 1);
    }
    std::cout << "\nPrinting the stack: " << std::endl;
    stack.print();

    std::cout << "\nPeeking top: " << stack.Top();
    std::cout << "\nRemoving top: " << stack.pop();
    std::cout << "\nTop after removal: " << stack.Top();
    std::cout << "\nPrinting the stack after removing top: " << std::endl;
    stack.print();

    stack.clear();

    std::cout << "\nPrinting the stack after clearing all data: " << std::endl;
    stack.print();

    try
    {
        std::cout << "\nPOP after clearing all data:" << std::endl;
        std::cout << stack.pop() << std::endl;
    }
    catch (const char *a)
    {
        std::cerr << a << std::endl;
    }
    try
    {
        std::cout << "\nTOP after clearing all data:" << std::endl;
        std::cout << stack.Top() << std::endl;
    }
    catch (const char *a)
    {
        std::cerr << a << std::endl;
    }
    return 0;
}