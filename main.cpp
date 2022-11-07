#include <iostream>
#include <algorithm>
#include "QuickSort.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}



int main() {

    StartCounter();
    std::cout << "Hello, World!" << std::endl;
    srand(time(nullptr));

    const int size = 15;
    int innitArray[size];

    for (int i = 0; i < size; ++i) {
        innitArray[i] = rand() % 100;
    }

    std::cout << "BEFORE " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << innitArray[i] << " ";
    }

    int mySorted[size];
    for (int i = 0; i < size; ++i) {
        mySorted[i] = innitArray[i];
    }


    quick_sort(mySorted, mySorted + size - 1, [](int a, int b) { return a < b; });

    std::cout << std::endl << "AFTER " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << mySorted[i] << " ";
    }

    int stdSorted[size];
    for (int i = 0; i < size; ++i) {
        stdSorted[i] = innitArray[i];
    }

    std::sort(stdSorted, stdSorted + size);
    std::cout << std::endl << "std::sort " << std::endl;
    for (int i = 0; i < size; ++i) {

        std::cout << mySorted[i] << " ";
        if (mySorted[i] != stdSorted[i]) {
            std::cout << " FAILED " << std::endl;
            break;
        }
    }





    std::cout<< std::endl << GetCounter() <<"\n";

    return 0;
}
