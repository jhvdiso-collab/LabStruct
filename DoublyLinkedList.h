#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <string>

struct DoubleNode {
    std::string data; 
    DoubleNode* prev;
    DoubleNode* next;
};

struct DoublyList {
    DoubleNode* head;
    DoubleNode* tail;
};

void initDoublyList(DoublyList& list);
void pushFrontDoubly(DoublyList& list, const std::string& value);
void pushBackDoubly(DoublyList& list, const std::string& value);
void pushBeforeDoubly(DoublyList& list, const std::string& target, const std::string& value);
void pushAfterDoubly(DoublyList& list, const std::string& target, const std::string& value);

void popFrontDoubly(DoublyList& list);
void printDoublyForward(const DoublyList& list);
void printDoublyBackward(const DoublyList& list);
void freeDoublyList(DoublyList& list);

int doublyLength(const DoublyList& list);
std::string getDoubly(const DoublyList& list, int index);
int findDoubly(const DoublyList& list, const std::string& value);
void insertDoubly(DoublyList& list, int index, const std::string& value);
std::string eraseDoubly(DoublyList& list, int index);
bool eraseDoublyValue(DoublyList& list, const std::string& value);
std::string popBackDoubly(DoublyList& list);
#endif
