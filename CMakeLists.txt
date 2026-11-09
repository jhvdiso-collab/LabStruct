cmake_minimum_required(VERSION 3.20)
project(data_structures_app LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(labstruct
    DynamicArray.cpp Stack.cpp Queue.cpp SinglyLinkedList.cpp
    DoublyLinkedList.cpp BST.cpp AVLTree.cpp Database.cpp)

target_include_directories(labstruct PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(labstruct PRIVATE -Wall -Wextra -Wpedantic)

