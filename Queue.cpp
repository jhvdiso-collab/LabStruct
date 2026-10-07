#include "Queue.h"
#include <iostream>

using namespace std;

void initQueue(Queue& q) {
    q.head = nullptr;
    q.tail = nullptr;
}

bool isQueueEmpty(const Queue& q) {
    return q.head == nullptr;
}

void pushQueue(Queue& q, int value) {
    QueueNode* newNode = new QueueNode{value, nullptr};
    if (q.tail != nullptr) {
        q.tail->next = newNode;
    } else {
        q.head = newNode;
    }
    q.tail = newNode;
}

int popQueue(Queue& q) {
    if (isQueueEmpty(q)) return -1;
    QueueNode* temp = q.head;
    int value = temp->data;
    q.head = q.head->next;
    if (q.head == nullptr) {
        q.tail = nullptr;
    }
    delete temp;
    return value;
}

void freeQueue(Queue& q) {
    while (!isQueueEmpty(q)) {
        popQueue(q);
    }
}