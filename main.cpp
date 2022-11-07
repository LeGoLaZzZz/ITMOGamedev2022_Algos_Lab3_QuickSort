#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "QuickSort.h"


double PCFreq = 0.0;
__int64 CounterStart = 0;

/*
If you want to have the timer use seconds instead then change
PCFreq = double(li.QuadPart)/1000.0;
to
PCFreq = double(li.QuadPart);
or if you want microseconds then use
PCFreq = double(li.QuadPart)/1000000.0;
 */
void StartCounter() {
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart / 1000000.0);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}

struct PerformanceMeasureResult {
    double insertionTime;
    double quickTime;
    int arraySize;
};

template<typename T, typename Compare, typename RandomElemFunc>
PerformanceMeasureResult StartMeasure(int arraySize, Compare comp, RandomElemFunc randomElemFunc) {

    srand(time(nullptr));

    T *quickSorted = new T[arraySize];
    T *insertSorted = new T[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        T elem = randomElemFunc();
        quickSorted[i] = elem;
        insertSorted[i] = elem;
    }

    StartCounter();
    quick_sort(quickSorted, quickSorted + arraySize - 1, comp);
    auto quickTime = GetCounter();

    StartCounter();
    insert_sort(insertSorted, insertSorted + arraySize - 1, comp);
    auto insertTime = GetCounter();
    delete[] quickSorted;
    delete[] insertSorted;

    return {insertTime, quickTime, arraySize};
}

int main() {

    std::fstream fs;
    fs.open("./performanceResults.txt", std::fstream::out | std::ofstream::trunc);

    const int measureCount = 10;
    for (int i = 0; i < 10000; ++i) {

        if (i % 1000 != 0) continue;
        double quickSum = 0;
        double insertSum = 0;

        for (int j = 0; j < measureCount; ++j) {
//            auto result = StartMeasure<int>(i, [](int a, int b) { return a < b; }, []() { return rand() % 100; });
            auto result = StartMeasure<std::string>(i, [](std::string a, std::string b) { return a < b; },
                                                    []() { return std::to_string(rand() % 100); });
            quickSum += result.quickTime;
            insertSum += result.insertionTime;
        }

        fs << i << " " << quickSum / measureCount << " " << insertSum / measureCount << std::endl;

        std::cout << "size " << i << std::endl;
        std::cout << "quick " << quickSum / measureCount << std::endl;
        std::cout << "insert " << insertSum / measureCount << std::endl;
        std::cout << std::endl;
    }

    fs.close();
    return 0;
}
