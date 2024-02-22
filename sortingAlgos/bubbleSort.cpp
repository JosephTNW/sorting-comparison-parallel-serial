#include <vector>
#include <omp.h>
#include <iostream>
using namespace std;

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