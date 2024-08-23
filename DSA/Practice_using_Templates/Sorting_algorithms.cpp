#include <iostream>
#include <vector>
#include <random>

void QuickSort(std::vector<int> &array, int low, int high);
int partition(std::vector<int> &array, int low, int high);
void InsertionSort();
void SelectionSort();

void QuickSort(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int piviot = partition(array, low, high);
        QuickSort(array, low, piviot - 1);
        QuickSort(array, piviot + 1, high);
    }
}

int partition(std::vector<int> &array, int low, int high)
{
    int pi = array[low];
    int i = low + 1;
    for (int j = i; j <= high; j++)
    {
        if (array[j] < pi)
        {
            std::swap(array[i], array[j]);
            i++;
        }
    }
    int a = array[i - 1];
    array[i - 1] = array[low];
    array[low] = a;
    return i - 1;
}

int main()
{
    std::vector<int> array;
    srand(time_t(NULL));
    int m{};
    std::cout << "enter the size: ";
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        array.push_back(~(rand() * m * (~m)));
    }
    std::cout << "Array before sorting:\n";
    for (auto a : array)
    {
        std::cout << a << std::endl;
    }
    QuickSort(array, 0, array.size() - 1);
    std::cout << "Array after sorting:\n";
    for (auto a : array)
    {
        std::cout << a << std::endl;
    }
}