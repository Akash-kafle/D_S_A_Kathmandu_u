#include "../header/Linked_list_queue.h"

int main()
{
    LinkedQueue *queue = new LinkedQueue;
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

    for (int i = 0; i < user_input; i++)
    {
        std::cout << "Enter data: ";
        queue->enqueue(i);
    }
    queue->print();
    std::cout << "Front: " << queue->Front() << std::endl;
    std::cout << "Rear: " << queue->Rear() << std::endl;

    queue->clear();

    std::cout << "Queue is empty: " << std::boolalpha << queue->isEmpty() << std::endl;
    try
    {
        std::cout << "Front(After clearing): " << queue->Front() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << std::endl;
    }
    try
    {
        std::cout << "Rear(After clearing): " << queue->Rear() << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << std::endl;
    }
    std::cout << "Print(After clearing): ";
    try
    {
        queue->print();
    }
    catch (const char *msg)
    {
        std::cout << std::endl;
    }
    std::cout << std::endl;

    delete queue;
    return 0;
}