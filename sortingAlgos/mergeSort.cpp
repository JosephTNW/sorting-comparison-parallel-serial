#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

/**
 * Merges two subarrays of the given array.
 * 
 * @param arr The array to be sorted.
 * @param l The starting index of the first subarray.
 * @param m The ending index of the first subarray.
 * @param r The ending index of the second subarray.
 */
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

/**
 * Sorts the given vector using the merge sort algorithm in a serial manner.
 * 
 * @param arr The vector to be sorted.
 * @param l The starting index of the subarray to be sorted.
 * @param r The ending index of the subarray to be sorted.
 */
void mergeSortSerial(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortSerial(arr, l, m);
        mergeSortSerial(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/**
 * Sorts a vector of integers using the parallel implementation of the merge sort algorithm.
 * 
 * @param arr The vector of integers to be sorted.
 * @param l The starting index of the subarray to be sorted.
 * @param r The ending index of the subarray to be sorted.
 * 
 * @note The function assumes that the vector is not empty.
 *       The function uses OpenMP directives to parallelize the sorting process, so it requires OpenMP support.
 */
void mergeSortParallel(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortParallel(arr, l, m);

            #pragma omp section
            mergeSortParallel(arr, m + 1, r);
        }

        merge(arr, l, m, r);
    }
}
