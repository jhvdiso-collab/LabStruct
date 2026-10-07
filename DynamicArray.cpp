#include "DynamicArray.h"
#include <iostream>

using namespace std;

void initArray(DynamicArray& arr, int initialCapacity) {
    arr.data = new int[initialCapacity];
    arr.size = 0;
    arr.capacity = initialCapacity;
}

void pushBack(DynamicArray& arr, int value) {
    if (arr.size == arr.capacity) {
        int newCapacity = arr.capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < arr.size; i++) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
        arr.capacity = newCapacity;
    }
    arr.data[arr.size++] = value;
}

void popBack(DynamicArray& arr) {
    if (arr.size > 0) {
        arr.size--;
    }
}

void printArray(const DynamicArray& arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << "] (size: " << arr.size << ", capacity: " << arr.capacity << ")\n";
}

void freeArray(DynamicArray& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}