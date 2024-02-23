#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include <vector>
#include <omp.h>
#include <iostream>
using namespace std;

vector<int> generateArray(int n);
vector<int> shuffleArray(vector<int> &arr);
void printArray(vector<int> &arr);

#endif