#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <string>

struct DynamicArray {
    std::string* data; // Изменено на строки
    int size;
    int capacity;
};

void initArray(DynamicArray& arr, int initialCapacity = 4);
void pushBack(DynamicArray& arr, const std::string& value);
void popBack(DynamicArray& arr);
void printArray(const DynamicArray& arr);
void freeArray(DynamicArray& arr);

void insertAt(DynamicArray& arr, int index, const std::string& value);
std::string getAt(const DynamicArray& arr, int index);
std::string eraseAt(DynamicArray& arr, int index);
void setAt(DynamicArray& arr, int index, const std::string& value);
int arrayLength(const DynamicArray& arr);
#endif
