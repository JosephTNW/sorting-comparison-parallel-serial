#include <iostream>
#include <vector>
#include <omp.h>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortSerial(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortSerial(arr, low, pi - 1);
        quickSortSerial(arr, pi + 1, high);
    }
}

void quickSortParallel(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
#pragma omp parallel sections
        {
#pragma omp section
            quickSortParallel(arr, low, pi - 1);
#pragma omp section
            quickSortParallel(arr, pi + 1, high);
        }
    }
}
