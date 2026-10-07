#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

void pushFront(SinglyNode*& head, int value) {
    SinglyNode* newNode = new SinglyNode{value, head};
    head = newNode;
}

void pushBack(SinglyNode*& head, int value) {
    SinglyNode* newNode = new SinglyNode{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    SinglyNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void popFront(SinglyNode*& head) {
    if (head == nullptr) return;
    SinglyNode* temp = head;
    head = head->next;
    delete temp;
}

void printList(SinglyNode* head) {
    SinglyNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr\n";
}

void freeList(SinglyNode*& head) {
    while (head != nullptr) {
        popFront(head);
    }
}