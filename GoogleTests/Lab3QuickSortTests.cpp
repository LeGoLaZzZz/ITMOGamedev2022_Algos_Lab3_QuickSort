#include <algorithm>
#include "gtest/gtest.h"
#include "../QuickSort.h"

class SortTests : public testing::Test {
protected:
    void SetUp() override {
    }

    template<typename T, typename Compare>
    void TestFor(T *items, int arraySize, Compare comp) {

        T *mySorted = new T[arraySize];
        T *stdSorted = new T[arraySize];

        for (int i = 0; i < arraySize; ++i) {
            mySorted[i] = items[i];
            stdSorted[i] = items[i];

            quick_sort<T, Compare>((T *) mySorted, (T *) (mySorted + arraySize - 1), comp);

            std::sort(stdSorted, stdSorted + arraySize, comp);
            for (int i = 0; i < arraySize; ++i) {
                EXPECT_EQ(mySorted[i], stdSorted[i]);
            }
        }


        delete[] mySorted;
        delete[] stdSorted;
    }
};

TEST_F(SortTests, forwardFor) {


    const int size = 15;
    int innitIntArray[size];
    std::string innitStringArray[size];

    for (int i = 0; i < size; ++i) {
        innitIntArray[i] = i;
        innitStringArray[i] = i;
    }

    TestFor(innitIntArray, size, [](int a, int b) { return a < b; });
    TestFor(innitStringArray, size, [](std::string a, std::string b) { return a < b; });

}

TEST_F(SortTests, reverseFor) {

    const int size = 15;
    int innitIntArray[size];
    std::string innitStringArray[size];

    int j=0;
    for (int i = size - 1; i >= 0; --i) {
        innitIntArray[j] = i;
        innitStringArray[j] = i;
        j++;
    }

    TestFor(innitIntArray, size, [](int a, int b) { return a < b; });
    TestFor(innitStringArray, size, [](std::string a, std::string b) { return a < b; });
}

TEST_F(SortTests, longStrFor) {


    const int size = 15;
    std::string innitStringArray[size];

    int j=0;
    for (int i = size - 1; i >= 0; --i) {
        innitStringArray[j++] = std::to_string(i) + std::string(100, 'a');
    }

    TestFor(innitStringArray, size, [](std::string a, std::string b) { return a < b; });

}


TEST(QuickSort, sampleTest) {
    const int size = 15;
    int innitArray[size];
    int mySorted[size];
    int stdSorted[size];

    for (int i = 0; i < size; ++i) {
        innitArray[i] = i;
        mySorted[i] = i;
        stdSorted[i] = i;
    }
    quick_sort(mySorted, mySorted + size - 1, [](int a, int b) { return a < b; });
    std::sort(stdSorted, stdSorted + size);
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(mySorted[i], stdSorted[i]);
    }
}