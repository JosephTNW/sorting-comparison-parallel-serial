#include <vector>
#include <omp.h>
#include <iostream>
using namespace std;

void bubbleSortSerial(vector<int>& arr);

void bubbleSortParallel(vector<int>& arr);