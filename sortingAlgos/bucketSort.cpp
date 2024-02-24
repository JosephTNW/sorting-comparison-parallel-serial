#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

void bucketSortSerial(std::vector<int>& arr, int num_buckets) {
    int n = arr.size();
    std::vector<std::vector<int>> buckets(num_buckets);

    // Place elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucket_index = arr[i] / num_buckets;
        buckets[bucket_index].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < num_buckets; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < num_buckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

void bucketSortParallel(std::vector<int>& arr, int num_buckets) {
    int n = arr.size();
    std::vector<std::vector<int>> buckets(num_buckets);

    #pragma omp parallel for default(none) shared(arr, buckets, num_buckets)
    for (int i = 0; i < n; ++i) {
        int bucket_index = arr[i] / num_buckets;
        #pragma omp critical
        buckets[bucket_index].push_back(arr[i]);
    }

    // Sort each bucket in parallel
    #pragma omp parallel for default(none) shared(buckets)
    for (int i = 0; i < num_buckets; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < num_buckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}
