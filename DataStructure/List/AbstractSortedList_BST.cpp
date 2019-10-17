//
//  AbstractSortedList_BST.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/17.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>
#include "AbstractSortedList.hpp"
#include "../BinarySearchTree/BinarySearchTree.cpp"

template <typename Type>
class AbstractSortedList_BST: public AbstractSortedList<Type> {

public:
    AbstractSortedList_BST() {
        this->binarySearchTree = new BinarySearchTree<Type>();
    }
    ~AbstractSortedList_BST() override {
        delete this->binarySearchTree;
    }
    bool isEmpty() override {
        return this->binarySearchTree->isEmpty();
    }
    Type minimum() override {
        return this->binarySearchTree->minimum();
    }
    Type maximum() override {
        return this->binarySearchTree->maximum();
    }
    bool find(Type element) override {
        return this->binarySearchTree->find(element);
    }
    void insert(Type element) override {
        this->binarySearchTree->insert(element);
    }
    void remove(Type element) override {
        this->binarySearchTree->remove(element);
    }
private:
    BinarySearchTree<Type>* binarySearchTree;

};


