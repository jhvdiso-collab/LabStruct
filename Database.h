#ifndef DATABASE_H
#define DATABASE_H
#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "AVLTree.h"
#include <map>
#include <memory>
#include <string>
#include <vector>


struct Container {
    explicit Container(char type);
    ~Container();
    Container(const Container&) = delete;
    Container& operator=(const Container&) = delete;
    char type;
    DynamicArray array{};
    SinglyNode* singly = nullptr;
    DoublyList doubly{};
    StackNode* stack = nullptr;
    Queue queue{};
    Node* tree = nullptr;
    

    std::vector<std::string> values(bool reverse = false) const; 
    std::vector<int> treeValues() const; 
};

struct QueryResult { std::string output; bool changed; };

class Database {
public:
    void load(const std::string& path);
    void save(const std::string& path) const;
    QueryResult execute(const std::string& query);
private:
    std::map<std::string, std::unique_ptr<Container>> containers;
};
#endif
