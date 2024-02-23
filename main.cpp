#include <vector>
#include <omp.h>
#include <iostream>
#include <random>
#include <algorithm>
#include "sortingAlgos/bubbleSort.h"
#include "sortingAlgos/mergeSort.h"
using namespace std;


vector<int> generateArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }
    return arr;
}

vector<int> shuffleArray(vector<int> &arr)
{
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
    return arr;
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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

    // Serial Merge Sort
    start = omp_get_wtime();
    mergeSortSerial(arrCopy, 0, arrCopy.size() - 1);
    end = omp_get_wtime();
    cout << "Serial Merge Sort: " << end - start << " seconds." << endl;

    // Parallel Merge Sort
    start = omp_get_wtime();
    mergeSortParallel(arr, 0, arr.size() - 1);
    end = omp_get_wtime();
    cout << "Parallel Merge Sort: " << end - start << " seconds." << endl;
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
            // Call your quick sort function here with the appropriate parameters
            break;
        case 4:
            cout << "You have selected Insertion Sort." << endl;
            // Call your insertion sort function here with the appropriate parameters
            break;
        case 5:
            cout << "You have selected Selection Sort." << endl;
            // Call your selection sort function here with the appropriate parameters
            break;
        case 6:
            cout << "Exiting program." << endl;
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (running);

    // After the loop, you might want to display the sorted array or perform additional actions
    printArray(arr);

    return 0;
}

