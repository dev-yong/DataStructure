//
//  BinaryHeap.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/17.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
class BinaryHeap {

public:
    //MARK:- public
    //MARK: constructor
    BinaryHeap(function<bool(Type, Type)> compare = [](Type lhs, Type rhs) { return lhs < rhs; });
    ~BinaryHeap();
    //MARK: Accessors
    bool isEmpty();
    Type front();
    Type*& sorted();
    //MARK: Mutators
    void push(Type element);
    Type pop();
    void clear();

private:
    //MARK:- private
    void upheap(int index);
    void downheap(int index);
    vector<Type> elements;
    function<Type(Type, Type)> compare;

};

template <typename Type>
BinaryHeap<Type>::BinaryHeap(function<bool(Type, Type)> compare) {
    this->compare = compare;
}
template <typename Type>
BinaryHeap<Type>::~BinaryHeap() {
    this->clear();
}
template <typename Type>
bool BinaryHeap<Type>::isEmpty() {
    return this->elements.empty();
}
template <typename Type>
Type BinaryHeap<Type>::front() {
    if (this->elements.empty()) {
        throw;
    }
    return this->elements.front();
}
template <typename Type>
Type*& BinaryHeap<Type>::sorted() {
    Type* temp = new Type[this->elements.size()];
    vector<Type> tempVector;
    while(!this->isEmpty()) {
        tempVector.push_back(this->pop());
    }
    copy(tempVector.begin(), tempVector.end(), temp);
    return temp;
}
template <typename Type>
Type BinaryHeap<Type>::pop() {
    if (this->elements.empty()) {
        throw;
    }
    Type value = this->front();
    if(this->elements.size() == 1) {
        this->elements.pop_back();
    }
    else {
        int back = this->elements.back();
        this->elements[0] = back;
        this->elements.pop_back();
        this->downheap(0);
    }
    return value;
}
template <typename Type>
void BinaryHeap<Type>::push(Type element) {
    this->elements.push_back(element);
    int endIndex = this->elements.size() - 1;
    this->upheap(endIndex);
}
template <typename Type>
void BinaryHeap<Type>::upheap(int index) {
    if (index == 0) { return; }
    int parentIndex = (index / 2) - (index % 2 == 0 ? 1 : 0);
    if (this->compare(this->elements[index], this->elements[parentIndex])) {
        swap(this->elements[parentIndex], this->elements[index]);
        this->upheap(parentIndex);
    }
}
template <typename Type>
void BinaryHeap<Type>::downheap(int index) {
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    int lastIndex = this->elements.size() - 1;
    if (leftIndex <= lastIndex && rightIndex <= lastIndex) {
        if (this->compare(this->elements[leftIndex], this->elements[index])) {
            swap(this->elements[index], this->elements[leftIndex]);
            this->downheap(leftIndex);
        } else if(this->compare(this->elements[rightIndex], this->elements[index])) {
            swap(this->elements[index], this->elements[rightIndex]);
            this->downheap(rightIndex);
        }
    }
    else if (leftIndex <= lastIndex) {
        if (this->compare(this->elements[leftIndex], this->elements[index])) {
            swap(this->elements[index], this->elements[leftIndex]);
            this->downheap(leftIndex);
        }
    }
}
template <typename Type>
void BinaryHeap<Type>::clear() {
    this->elements.clear();
}
