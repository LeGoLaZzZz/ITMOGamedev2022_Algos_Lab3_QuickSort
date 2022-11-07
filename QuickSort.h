#ifndef LAB3QUICKSORT_QUICKSORT_H
#define LAB3QUICKSORT_QUICKSORT_H

#include <windows.h>

template<typename T, typename Compare>
void insert_sort(T *first, T *last, Compare comp) {

    for (auto i = first; i <= last; i++)
    {
        auto j = i - 1;

        T value = *(j + 1);
        while (j >= first && comp(value, *j))
        {
            *(j + 1) = std::move(*j);
            j--;
        }
        *(j + 1) = value;
    }

//    if (first == last)
//        return;
//    T x;
//    T *j;
//    for (T *i = first; i <= last; i++) {
//        j = i;
//        x = (*i);
//        while (j > first && comp(x, *(j - 1))) {
//            *j = std::move(*(j - 1));
//            j--;
//        }
//        *j = std::move(x);
//    }
}


template<typename T, typename Compare>
void quick_sort(T *first, T *last, Compare comp) {

    T *firstPointer = first;
    T *lastPointer = last;

    while (firstPointer < lastPointer) {

//        if (lastPointer - firstPointer < 5) {
//            insert_sort(firstPointer, lastPointer, comp);
//            return;
//        }

        T *midPointer = firstPointer + (lastPointer - firstPointer) / 2;

        if (comp(*midPointer, *firstPointer)) std::swap(*midPointer, *firstPointer);
        if (comp(*lastPointer, *firstPointer)) std::swap(*lastPointer, *firstPointer);
        if (comp(*lastPointer, *midPointer)) std::swap(*lastPointer, *midPointer);

        T pivot = *midPointer;
        T *i = firstPointer;
        T *j = lastPointer;

        while (true) {
            while (comp(*i, pivot)) i++;
            while (comp(pivot, *j)) j--;
            if (i >= j) break;
            std::swap(*i, *j);
            i++;
            j--;
        }

        if (lastPointer - j > j - firstPointer) {
            quick_sort(firstPointer, j, comp); // left part to recursive
            firstPointer = j + 1; // right part to while
        } else {
            quick_sort(j + 1, lastPointer, comp); // right part to recursive
            lastPointer = j; // left part to while
        }

    }

}

#endif //LAB3QUICKSORT_QUICKSORT_H
