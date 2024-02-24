#include <vector>
#include <omp.h>
#include <iostream>
#include <random>
#include <algorithm>
#include "sortingAlgos/bubbleSort.h"
#include "sortingAlgos/mergeSort.h"
#include "sortingAlgos/insertionSort.h"
#include "sortingAlgos/quickSort.h"
#include "sortingAlgos/bucketSort.h"
#include "utils/arrayUtils.h"

using namespace std;

void runBubbleSort(vector<int> &arr)
{
    vector<int> arrCopy = arr;

    double start, end;
    start = omp_get_wtime();
    bubbleSortSerial(arr);
    end = omp_get_wtime();
    cout << "Serial Bubble Sort: " << end - start << " seconds." << endl;

    start = omp_get_wtime();
    bubbleSortParallel(arrCopy);
    end = omp_get_wtime();
    cout << "Parallel Bubble Sort: " << end - start << " seconds." << endl;
}

void runMergeSort(vector<int>& arr) {
    vector<int> arrCopy = arr;

    double start, end;

    start = omp_get_wtime();
    mergeSortSerial(arrCopy, 0, arrCopy.size() - 1);
    end = omp_get_wtime();
    cout << "Serial Merge Sort: " << end - start << " seconds." << endl;

    start = omp_get_wtime();
    mergeSortParallel(arr, 0, arr.size() - 1);
    end = omp_get_wtime();
    cout << "Parallel Merge Sort: " << end - start << " seconds." << endl;
}

void runInsertionSort(vector<int>& arr) {
    vector<int> arrCopy = arr;

    double start, end;

    start = omp_get_wtime();
    insertionSortSerial(arrCopy);
    end = omp_get_wtime();
    cout << "Serial Insertion Sort: " << end - start << " seconds." << endl;

    start = omp_get_wtime();
    insertionSortParallel(arr);
    end = omp_get_wtime();
    cout << "Parallel Insertion Sort: " << end - start << " seconds." << endl;
}

void runQuickSort(vector<int>& arr) {
    vector<int> arrCopy = arr;

    double start, end;

    start = omp_get_wtime();
    quickSortSerial(arrCopy, 0, arrCopy.size() - 1);
    end = omp_get_wtime();
    cout << "Serial Quick Sort: " << end - start << " seconds." << endl;

    start = omp_get_wtime();
    quickSortParallel(arr, 0, arr.size() - 1);
    end = omp_get_wtime();
    cout << "Parallel Quick Sort: " << end - start << " seconds." << endl;
}

void runBucketSort(vector<int>& arr, int num_buckets) {
    vector<int> arrCopy = arr;

    double start, end;

    start = omp_get_wtime();
    bucketSortSerial(arrCopy, num_buckets);
    end = omp_get_wtime();
    cout << "Serial Bucket Sort: " << end - start << " seconds." << endl;

    start = omp_get_wtime();
    bucketSortParallel(arr, num_buckets);
    end = omp_get_wtime();
    cout << "Parallel Bucket Sort: " << end - start << " seconds." << endl;
}

int main()
{
    bool running = true;
    int choice, n;
    vector<int> arr = generateArray(10000);
    
    do
    {
        cout << "This is a program to visualize and time various sorting algorithms together with its parallel implementation." << endl;
        cout << "Please specify the size of the array to sort and visualize: (default: 10000)" << endl;
        cin >> n;

        arr = generateArray(n);
        arr = shuffleArray(arr);
        printArray(arr);

        cout << "Please select the sorting algorithm you would like to visualize:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Quick Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Selection Sort" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "You have selected Bubble Sort." << endl;
            runBubbleSort(arr);
            break;
        case 2:
            cout << "You have selected Merge Sort." << endl;
            runMergeSort(arr);
            break;
        case 3:
            cout << "You have selected Quick Sort." << endl;
            break;
        case 4:
            cout << "You have selected Insertion Sort." << endl;
            runInsertionSort(arr);
            break;
        case 5:
            cout << "You have selected Selection Sort." << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (running);

    printArray(arr);

    return 0;
}

