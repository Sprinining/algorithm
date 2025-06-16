#include "sort.h"
#include <iostream>

namespace my_sort {
void Sort::swapByPtr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Sort::swapByRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Sort::xorSwap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void Sort::bubbleSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        bool isSorted = true;
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted) break;
    }
}
}