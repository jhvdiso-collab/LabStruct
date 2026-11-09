#include "DoublyLinkedList.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void initDoublyList(DoublyList& list) {
    list.head = nullptr;
    list.tail = nullptr;
}

void pushFrontDoubly(DoublyList& list, const string& value) {
    DoubleNode* newNode = new DoubleNode{value, nullptr, list.head};
    if (list.head != nullptr) {
        list.head->prev = newNode;
    } else {
        list.tail = newNode;
    }
    list.head = newNode;
}

void pushBackDoubly(DoublyList& list, const string& value) {
    DoubleNode* newNode = new DoubleNode{value, list.tail, nullptr};
    if (list.tail != nullptr) {
        list.tail->next = newNode;
    } else {
        list.head = newNode;
    }
    list.tail = newNode;
}

void pushBeforeDoubly(DoublyList& list, const string& target, const string& value) {
    DoubleNode* curr = list.head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }
    if (curr == nullptr) return;
    if (curr == list.head) {
        pushFrontDoubly(list, value);
        return;
    }
    DoubleNode* newNode = new DoubleNode{value, curr->prev, curr};
    curr->prev->next = newNode;
    curr->prev = newNode;
}

void pushAfterDoubly(DoublyList& list, const string& target, const string& value) {
    DoubleNode* curr = list.head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }
    if (curr == nullptr) return;
    if (curr == list.tail) {
        pushBackDoubly(list, value);
        return;
    }
    DoubleNode* newNode = new DoubleNode{value, curr, curr->next};
    curr->next->prev = newNode;
    curr->next = newNode;
}

void popFrontDoubly(DoublyList& list) {
    if (list.head == nullptr) {
        return;
    }
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

namespace {
DoubleNode* doublyAt(const DoublyList& list, int index) {
    if (index < 0) {
        throw std::out_of_range("List index");
    }
    DoubleNode* node = list.head;
    for (int i = 0; i < index && node != nullptr; i++) {
        node = node->next;
    }
    if (!node) {
        throw std::out_of_range("List index");
    }
    return node;
}
string unlinkDoubly(DoublyList& list, DoubleNode* node) {
    string value = node->data;
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list.head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list.tail = node->prev;
    }
    delete node;
    return value;
}
} 

int doublyLength(const DoublyList& list) {
    int n = 0;
    for (DoubleNode* p = list.head; p; p = p->next) {
        ++n;
    }
    return n;
}

string getDoubly(const DoublyList& list, int index) {
    return doublyAt(list, index)->data;
}

int findDoubly(const DoublyList& list, const string& value) {
    int i = 0;
    for (DoubleNode* p = list.head; p; p = p->next, ++i) {
        if (p->data == value) {
            return i;
        }
    }
    return -1;
}

void insertDoubly(DoublyList& list, int index, const string& value) {
    if (index < 0) {
        throw out_of_range("List index");
    }
    if (index == 0) {
        pushFrontDoubly(list, value);
        return;
    }
    DoubleNode* prev = doublyAt(list, index - 1);
    DoubleNode* node = new DoubleNode{value, prev, prev->next};
    if (prev->next) {
        prev->next->prev = node;
    } else {
        list.tail = node;
    }
    prev->next = node;
}

string eraseDoubly(DoublyList& list, int index) {
    return unlinkDoubly(list, doublyAt(list, index));
}

bool eraseDoublyValue(DoublyList& list, const string& value) {
    for (DoubleNode* p = list.head; p; p = p->next) {
        if (p->data == value) {
            unlinkDoubly(list, p);
            return true;
        }
    }
    return false;
}

string popBackDoubly(DoublyList& list) {
    if (!list.tail) {
        throw std::out_of_range("Empty list");
    }
    return unlinkDoubly(list, list.tail);
}
