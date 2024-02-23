#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <omp.h>

void insertionSortSerial(std::vector<int>& arr);
void insertionSortParallel(std::vector<int>& arr);

#endif // INSERTIONSORT_H
