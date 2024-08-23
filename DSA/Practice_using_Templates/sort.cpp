#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <future>
#include <numeric>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(std::vector<int>& arr, int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void hybridSort(std::vector<int>& arr, int threshold = 10) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[i], arr[min_idx]);
        if (n - i - 1 <= threshold) {
            insertionSort(arr, i + 1, n);
            break;
        }
    }
}

double timedSort(const std::vector<int>& arr, void (*sortFunc)(std::vector<int>&)) {
    std::vector<int> arrCopy = arr;  // Create a copy to sort
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arrCopy);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

void runComparison(int size, int numRuns) {
    std::vector<double> selectionTimes, hybridTimes;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    for (int run = 0; run < numRuns; run++) {
        std::vector<int> arr(size);
        for (int& num : arr) num = dis(gen);

        auto futureSelection = std::async(std::launch::async, [&arr]() {
            return timedSort(arr, selectionSort);
        });
        auto futureHybrid = std::async(std::launch::async, [&arr]() {
            return timedSort(arr, [](std::vector<int>& arr) { hybridSort(arr); });
        });

        selectionTimes.push_back(futureSelection.get());
        hybridTimes.push_back(futureHybrid.get());
    }

    double avgSelection = std::accumulate(selectionTimes.begin(), selectionTimes.end(), 0.0) / numRuns;
    double avgHybrid = std::accumulate(hybridTimes.begin(), hybridTimes.end(), 0.0) / numRuns;

    std::cout << "Array size: " << size << std::endl;
    std::cout << "Average time for selection sort: " << avgSelection << " seconds" << std::endl;
    std::cout << "Average time for hybrid sort: " << avgHybrid << " seconds" << std::endl;
    std::cout << "Improvement: " << (avgSelection - avgHybrid) / avgSelection * 100 << "%" << std::endl;
    std::cout << std::endl;
}

int main() {
    std::vector<int> sizes = {1000, 5000, 10000, 20000, 50000};
    int numRuns = 5;

    for (int size : sizes) {
        runComparison(size, numRuns);
    }

    return 0;
}
