#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>

void mergeSortNormal(std::vector<int> &arr, int left, int right);
void merge(std::vector<int> &arr, int left, int middle, int right);
void mergeSort(std::vector<int> &arr, int left, int right, int threshold);

// Function to merge two sorted halves
void merge(std::vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(std::vector<int> &arr, int left, int right, int threshold)
{
    if (left >= right)
        return;

    if (right - left + 1 <= threshold)
    {
        // Use sequential sort for small sub-arrays
        mergeSortNormal(arr, left, right);
        return;
    }

    int middle = left + (right - left) / 2;

    std::thread leftSorter(mergeSort, std::ref(arr), left, middle, threshold);
    std::thread rightSorter(mergeSort, std::ref(arr), middle + 1, right, threshold);

    leftSorter.join();
    rightSorter.join();

    merge(arr, left, middle, right);
}

// Normal merge sort
void mergeSortNormal(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;

    mergeSortNormal(arr, left, middle);
    mergeSortNormal(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

int main()
{
    std::vector<int> arr;
    srand(0); // Set a seed for reproducibility
    for (int i = 0; i < 1000000; i++)
        arr.push_back(rand() % 10000000);

    std::vector<int> arrCopy = arr; // Copy the array for fair comparison

    // Measure the time taken by parallel merge sort
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1, 1000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Time taken by merge sort (parallel): " << elapsed_seconds.count() << "s\n";

    // Measure the time taken by normal merge sort
    start = std::chrono::high_resolution_clock::now();
    mergeSortNormal(arrCopy, 0, arrCopy.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Time taken by merge sort (normal): " << elapsed_seconds.count() << "s\n";

    return 0;
}
