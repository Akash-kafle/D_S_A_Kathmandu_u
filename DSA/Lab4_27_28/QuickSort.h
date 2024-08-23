#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <thread>
#include <tuple>
#include <mutex>

int partion(std::vector<int> &array, int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    for (int j = i; j <= high; j++)
    {
        if (array[j] < pivot)
        {
            std::swap(array[i], array[j]);
            i++;
        }
    }
    std::swap(array[low], array[i - 1]);
    return i - 1;
}

void quickSort(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int pi = partion(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}