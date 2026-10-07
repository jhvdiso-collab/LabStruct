#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

void initDoublyList(DoublyList& list) {
    list.head = nullptr;
    list.tail = nullptr;
}

void pushFrontDoubly(DoublyList& list, int value) {
    DoubleNode* newNode = new DoubleNode{value, nullptr, list.head};
    if (list.head != nullptr) {
        list.head->prev = newNode;
    } else {
        list.tail = newNode;
    }
    list.head = newNode;
}

void pushBackDoubly(DoublyList& list, int value) {
    DoubleNode* newNode = new DoubleNode{value, list.tail, nullptr};
    if (list.tail != nullptr) {
        list.tail->next = newNode;
    } else {
        list.head = newNode;
    }
    list.tail = newNode;
}

void popFrontDoubly(DoublyList& list) {
    if (list.head == nullptr) return;
    DoubleNode* temp = list.head;
    list.head = list.head->next;
    if (list.head != nullptr) {
        list.head->prev = nullptr;
    } else {
        list.tail = nullptr;
    }
    delete temp;
}

void printDoublyForward(const DoublyList& list) {
    DoubleNode* curr = list.head;
    cout << "nullptr <-> ";
    while (curr != nullptr) {
        cout << curr->data << " <-> ";
        curr = curr->next;
    }
    cout << "nullptr\n";
}

void printDoublyBackward(const DoublyList& list) {
    DoubleNode* curr = list.tail;
    cout << "nullptr <-> ";
    while (curr != nullptr) {
        cout << curr->data << " <-> ";
        curr = curr->prev;
    }
    cout << "nullptr\n";
}

void freeDoublyList(DoublyList& list) {
    while (list.head != nullptr) {
        popFrontDoubly(list);
    }
}