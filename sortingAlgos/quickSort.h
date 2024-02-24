#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <omp.h>

int partition(std::vector<int>& arr, int low, int high);
void quickSortSerial(std::vector<int>& arr, int low, int high);
void quickSortParallel(std::vector<int>& arr, int low, int high);

#endif // QUICKSORT_H
