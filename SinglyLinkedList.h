#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <string>

struct SinglyNode {
    std::string data; 
    SinglyNode* next;
};

void pushFront(SinglyNode*& head, const std::string& value);
void pushBack(SinglyNode*& head, const std::string& value);
void popFront(SinglyNode*& head);
void printList(SinglyNode* head);
void freeList(SinglyNode*& head);


void pushBefore(SinglyNode*& head, const std::string& target, const std::string& value);
void pushAfter(SinglyNode*& head, const std::string& target, const std::string& value);


int singlyLength(const SinglyNode* head);
std::string getSingly(const SinglyNode* head, int index);
int findSingly(const SinglyNode* head, const std::string& value);
void insertSingly(SinglyNode*& head, int index, const std::string& value);
std::string eraseSingly(SinglyNode*& head, int index);
bool eraseSinglyValue(SinglyNode*& head, const std::string& value); 

#endif
