#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <vector>
#include <omp.h>

void bucketSortSerial(std::vector<int>& arr, int num_buckets);
void bucketSortParallel(std::vector<int>& arr, int num_buckets);

#endif // BUCKETSORT_H
