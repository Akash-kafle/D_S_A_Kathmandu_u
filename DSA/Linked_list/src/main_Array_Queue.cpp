#include "../header/ArrayQueue.h"

int main()
{

    ArrayQueue *queue = new ArrayQueue;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->print();
    std::cout << "Front: " << queue->Front() << std::endl;
    std::cout << "Rear: " << queue->Rear() << std::endl;
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->print();
    std::cout << "Front(after dequeue): " << queue->Front() << std::endl;
    std::cout << "Rear(after dequeue): " << queue->Rear() << std::endl;

    int user_input;
    std::cout << "Enter total number of enqueue: ";
    do
    {
        std::cin >> user_input;

        std::cin.clear();
        std::cin.ignore(100, '\n');

        if (user_input > 0)
        {
            break;
        }
    } while (true);
    std::cout << "Enter data: " << std::endl;
    for (int i = 0; i < user_input; i++)
    {

        queue->enqueue(i);
    }
    queue->print();
    std::cout << "Front: " << queue->Front() << std::endl;
    std::cout << "Rear: " << queue->Rear() << std::endl;

    queue->clear();

    try
    {
        std::cout << "Front(After clearing): " << queue->Front() << std::endl;
    }
    catch (const char *e)
    {
        std::cerr << '\n';
    }

    try
    {
        std::cout << "Rear(After clearing): " << queue->Rear() << std::endl;
    }
    catch (const char *e)
    {
        std::cerr << '\n';
    }

    try
    {
        std::cout << "Print(After clearing): ";
        queue->print();
    }
    catch (const char *e)
    {
        std::cerr << '\n';
    }

    try
    {
        std::cout << "Dequeue(after clearing): " << queue->dequeue() << std::endl;
    }
    catch (const char *e)
    {
        std::cerr << '\n';
    }

    delete queue;

    return 0;
}