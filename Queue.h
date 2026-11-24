#ifndef QUEUE_H
#define QUEUE_H
#include <string>

struct QueueNode {
    std::string data; 
    QueueNode* next;
};

struct Queue {
    QueueNode* head;
    QueueNode* tail;
};

void initQueue(Queue& q);
void pushQueue(Queue& q, const std::string& value);
std::string popQueue(Queue& q);
bool isQueueEmpty(const Queue& q);
void freeQueue(Queue& q);

#endif
