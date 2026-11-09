#ifndef STACK_H
#define STACK_H
#include <string>

struct StackNode {
    std::string data; 
    StackNode* next;
};

void push(StackNode*& top, const std::string& value);
std::string pop(StackNode*& top);
bool isEmpty(StackNode* top);
void freeStack(StackNode*& top);

#endif
