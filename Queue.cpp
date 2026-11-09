#include "Queue.h"
#include <stdexcept>
#include <string>

using namespace std;

void initQueue(Queue& q) {
    q.head = nullptr;
    q.tail = nullptr;
}

bool isQueueEmpty(const Queue& q) {
    return q.head == nullptr;
}

void pushQueue(Queue& q, const string& value) {
    QueueNode* newNode = new QueueNode{value, nullptr};
    if (q.tail != nullptr) {
        q.tail->next = newNode;
    } else {
        q.head = newNode;
    }
    q.tail = newNode;
}

string popQueue(Queue& q) {
    if (isQueueEmpty(q)) {
        throw out_of_range("Empty queue");
    }
    QueueNode* temp = q.head;
    string value = temp->data;
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
