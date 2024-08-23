#include <iostream>
#include <vector>
#include <random>

struct answer
{
    bool result = false;
    int index = -1;
};

answer binary_search(std::vector<int> &, int);

int main()
{
    std::vector<int> array;
    srand(time(0));
    int m{};
    std::cout << "enter the size: ";
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        array.push_back(rand() % m);
    }
    std::cout << "Array :\n";
    for (auto a : array)
    {
        std::cout << a << std::endl;
    }
    int searching_num = rand() % m;
    answer a = binary_search(array, searching_num);
    std::cout << "Searching num: " << searching_num << std::endl;
    std::cout << a.index << "," << a.result << std::endl;
    std::system("pause");
    return 0;
}

answer binary_search(std::vector<int> &array, int target)
{
    int max = array.size() - 1;
    int min = 0;
    int mid = (max + min) / 2;
    answer a;
    while (max >= min)
    {
        mid = (max + min) / 2;
        if (target > array[mid])
        {
            max = mid - 1;
        }
        else if (target < array[mid])
        {
            min = mid + 1;
        }
        else
        {
            a.result = true;
            a.index = mid;
            return a;
        }
    }
    return a;
}