#include "Stack.h"
#include <iostream>

using namespace std;

void push(StackNode*& top, int value) {
    StackNode* newNode = new StackNode{value, top};
    top = newNode;
}

int pop(StackNode*& top) {
    if (isEmpty(top)) return -1;
    StackNode* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool isEmpty(StackNode* top) {
    return top == nullptr;
}

void freeStack(StackNode*& top) {
    while (!isEmpty(top)) {
        pop(top);
    }
}