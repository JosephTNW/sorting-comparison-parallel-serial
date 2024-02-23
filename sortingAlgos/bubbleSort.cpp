#include <vector>
#include <omp.h>
#include <iostream>
using namespace std;

/**
 * @brief Sorts a vector of integers using the bubble sort algorithm in serial manner.
 * 
 * The bubble sort algorithm repeatedly compares adjacent elements and swaps them if they are in the wrong order.
 * This process is repeated until the entire vector is sorted.
 * 
 * @param arr The vector of integers to be sorted.
 */
void bubbleSortSerial(vector<int>& arr) {
    bool swapped = true;
    int j = 0;
    int temp;
    
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < arr.size() - j; ++i) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

/**
 * Sorts given vector of integers with a parallel implementation of Bubble Sort algorithm.
 * 
 * @param arr The vector of integers to be sorted.
 * 
 * @remarks This function sorts the vector in ascending order with a parallel implementation of the Bubble Sort algorithm.
 *          The algorithm works by repeatedly swapping adjacent elements if they are in the wrong order, until the entire vector is sorted.
 *          The parallelization is achieved by dividing the sorting process into even and odd phases, and using OpenMP to parallelize the inner loop.
 *          During the even phase, the algorithm compares and swaps elements at even indices (0, 2, 4, ...).
 *          During the odd phase, the algorithm compares and swaps elements at odd indices (1, 3, 5, ...).
 *          The function modifies the original vector in-place.
 * 
 * @note The function assumes that the vector is not empty.
 *       The function uses OpenMP directives to parallelize the sorting process, so it requires OpenMP support.
 */
void bubbleSortParallel(vector<int>& arr) {
    int temp;
    int n = arr.size();
    
    for (int phase = 0; phase < n; ++phase) {
        if (phase % 2 == 0) {
            // Even phase
            #pragma omp parallel for default(none) shared(arr, n) private(temp)
            for (int i = 0; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        } else {
            // Odd phase
            #pragma omp parallel for default(none) shared(arr, n) private(temp)
            for (int i = 1; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }
    }
}