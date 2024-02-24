cmake_minimum_required(VERSION 3.27)
project(MidTermProject__ArraySortingVisualization_)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_FLAGS -fopenmp)

include_directories(sortingAlgos)

add_executable(MidTermProject__ArraySortingVisualization_
        sortingAlgos/bubbleSort.cpp
        sortingAlgos/bubbleSort.h
        sortingAlgos/mergeSort.h
        main.cpp
        sortingAlgos/mergeSort.cpp
        sortingAlgos/quickSort.cpp
        sortingAlgos/quickSort.h
        sortingAlgos/bucketSort.cpp
        sortingAlgos/bucketSort.h
        utils/arrayUtils.cpp)
