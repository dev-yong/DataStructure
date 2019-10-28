//
//  AbstractPriorityQueue_BinaryHeap.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/28.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include "AbstractPriorityQueue.hpp"

template <typename Type>
class AbstractPriorityQueue_BinaryHeap: public AbstractPriorityQueue<Type> {

public:
    AbstractPriorityQueue_BinaryHeap(function<bool(Type, Type)> compare = [](int lhs, int rhs) { return lhs < rhs; }) {
        this->binaryHeap = new BinaryHeap<Type>(compare);
    }
    ~AbstractPriorityQueue_BinaryHeap() override {
        delete this->binaryHeap;
    }
    Type front() override {
        return this->binaryHeap->front();
    }
    int pop() override {
        return this->binaryHeap->pop();
    }
    void push(Type element) override {
        return this->binaryHeap->push(element);
    }
private:
    BinaryHeap<Type>* binaryHeap;

};
