#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DoubleNode {
    int data;
    DoubleNode* prev;
    DoubleNode* next;
};

struct DoublyList {
    DoubleNode* head;
    DoubleNode* tail;
};

void initDoublyList(DoublyList& list);
void pushFrontDoubly(DoublyList& list, int value);
void pushBackDoubly(DoublyList& list, int value);
void popFrontDoubly(DoublyList& list);
void printDoublyForward(const DoublyList& list);
void printDoublyBackward(const DoublyList& list);
void freeDoublyList(DoublyList& list);

#endif