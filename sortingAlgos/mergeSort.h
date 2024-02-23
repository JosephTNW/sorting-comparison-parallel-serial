#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <omp.h>

void merge(std::vector<int>& arr, int l, int m, int r);
void mergeSortSerial(std::vector<int>& arr, int l, int r);
void mergeSortParallel(std::vector<int>& arr, int l, int r);

#endif // MERGESORT_H
