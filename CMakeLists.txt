cmake_minimum_required(VERSION 3.20)
project(data_structures_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_structures_app
        main.cpp
        DynamicArray.cpp
        Stack.cpp
        Queue.cpp
        SinglyLinkedList.cpp
        DoublyLinkedList.cpp
        BST.cpp
        AVLTree.cpp
)