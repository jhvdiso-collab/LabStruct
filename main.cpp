#include <iostream>
#include "DynamicArray.h"
#include "Stack.h"
#include "Queue.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "BST.h"
#include "AVLTree.h"

using namespace std;

void runDynamicArrayDemo() {
    cout << "\n=== ДИНАМИЧЕСКИЙ МАССИВ ===\n";
    DynamicArray arr;
    initArray(arr, 2);

    pushBack(arr, 10);
    pushBack(arr, 20);
    pushBack(arr, 30);
    printArray(arr);

    popBack(arr);
    printArray(arr);

    freeArray(arr);
}

void runStackDemo() {
    cout << "\n=== СТЕК (LIFO) ===\n";
    StackNode* stack = nullptr;

    push(stack, 100);
    push(stack, 200);
    push(stack, 300);

    while (!isEmpty(stack)) {
        cout << "Извлечено из стека: " << pop(stack) << "\n";
    }

    freeStack(stack);
}

void runQueueDemo() {
    cout << "\n=== ОЧЕРЕДЬ (FIFO) ===\n";
    Queue q;
    initQueue(q);

    pushQueue(q, 1);
    pushQueue(q, 2);
    pushQueue(q, 3);

    while (!isQueueEmpty(q)) {
        cout << "Извлечено из очереди: " << popQueue(q) << "\n";
    }

    freeQueue(q);
}

void runSinglyLinkedListDemo() {
    cout << "\n=== ОДНОСВЯЗНЫЙ СПИСОК ===\n";
    SinglyNode* list = nullptr;

    pushFront(list, 20);
    pushFront(list, 10);
    pushBack(list, 30);

    cout << "Содержимое списка: ";
    printList(list);

    popFront(list);
    cout << "После popFront:    ";
    printList(list);

    freeList(list);
}

void runDoublyLinkedListDemo() {
    cout << "\n=== ДВУСВЯЗНЫЙ СПИСОК ===\n";
    DoublyList list;
    initDoublyList(list);

    pushFrontDoubly(list, 20);
    pushFrontDoubly(list, 10);
    pushBackDoubly(list, 30);

    cout << "Прямой обход:  "; printDoublyForward(list);
    cout << "Обратный обход: "; printDoublyBackward(list);

    popFrontDoubly(list);
    cout << "После popFront: "; printDoublyForward(list);

    freeDoublyList(list);
}

void runBSTDemo() {
    cout << "\n=== БИНАРНОЕ ДЕРЕВО ПОИСКА (BST) ===\n";
    BSTNode* root = nullptr;

    int values[] = {15, 6, 18, 3, 7, 17, 20};
    for (int v : values) root = insertBST(root, v);

    cout << "In-Order обход (по возрастанию): ";
    printBSTInOrder(root);
    cout << "\n";

    cout << "Поиск 7: " << (searchBST(root, 7) ? "Найдено" : "Не найдено") << "\n";
    cout << "Поиск 99: " << (searchBST(root, 99) ? "Найдено" : "Не найдено") << "\n";

    freeBST(root);
}

void runAVLDemo() {
    cout << "\n=== АВЛ-ДЕРЕВО (САМОБАЛАНСИРУЮЩЕЕСЯ) ===\n";
    Node* root = nullptr;

    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int k : keys) {
        root = insert(root, k);
    }

    cout << "Дерево: ";
    printInOrder(root);
    cout << "\n";

    cout << "Высота: " << getHeight(root) << "\n";

    root = remove(root, 50);
    cout << "После удаления 50: ";
    printInOrder(root);
    cout << "\n";

    freeMemory(root);
}

int main() {
    int choice = -1;

    while (choice != 0) {
        cout << "\n=========================================\n";
        cout << "   МЕНЮ ДЕМОНСТРАЦИИ СТРУКТУР ДАННЫХ\n";
        cout << "=========================================\n";
        cout << "1. Динамический массив\n";
        cout << "2. Стек (Stack)\n";
        cout << "3. Очередь (Queue)\n";
        cout << "4. Односвязный список (Singly Linked List)\n";
        cout << "5. Двусвязный список (Doubly Linked List)\n";
        cout << "6. Бинарное дерево поиска (BST)\n";
        cout << "7. АВЛ-дерево (AVL Tree)\n";
        cout << "0. Выход\n";
        cout << "Выберите вариант: ";

        if (!(cin >> choice)) {
            cout << "Неверный ввод!\n";
            break;
        }

        switch (choice) {
            case 1: runDynamicArrayDemo(); break;
            case 2: runStackDemo(); break;
            case 3: runQueueDemo(); break;
            case 4: runSinglyLinkedListDemo(); break;
            case 5: runDoublyLinkedListDemo(); break;
            case 6: runBSTDemo(); break;
            case 7: runAVLDemo(); break;
            case 0: cout << "Завершение работы.\n"; break;
            default: cout << "Неверная опция! Попробуйте снова.\n";
        }
    }

    return 0;
}