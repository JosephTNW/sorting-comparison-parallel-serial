#include <vector>
#include <omp.h>
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

/**
 * Generates a vector representation of an array comprising of integers from 1 to n.
 * 
 * @param n The size of the array.
 * @return The generated array.
 */
vector<int> generateArray(int n)
{
    vector<int> arr(n);

    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }

    return arr;
}

/**
 * Shuffles the elements of the given array randomly.
 * Is used to shuffle the array before sorting to ensure that the sorting algorithm works as expected.
 * 
 * @param arr The array to be shuffled.
 * @return The shuffled array.
 */
vector<int> shuffleArray(vector<int> &arr)
{
    random_device rd;
    mt19937 g(rd());

    #pragma omp parallel for
    for (int i = 0; i < arr.size(); ++i)
    {
        int j = uniform_int_distribution<int>(0, i)(g);
        swap(arr[i], arr[j]);
    }

    return arr;
}

/**
 * Prints the elements of the given array in a parallelized manner to ensure quick printing process.
 * 
 * @param arr The array to be printed.
 */
void printArray(vector<int> &arr)
{
    #pragma omp parallel for
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}