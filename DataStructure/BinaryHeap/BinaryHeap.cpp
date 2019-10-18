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
    BinaryHeap() {};
    //MARK: Accessors
    Type minimum();
    Type maximum();
    //MARK: Mutators
    void insert(Type element);
    void remove(Type element);

private:
    //MARK:- private
    void upheap(int index);
    void downheap(int index);
    vector<Type> elements;

};

template <typename Type>
Type BinaryHeap<Type>::minimum() {
    if (elements.empty()) {
        throw;
    }
    return this->elements[0];
}
template <typename Type>
Type BinaryHeap<Type>::maximum() {
    if (elements.empty()) {
        throw;
    }
}
template <typename Type>
void BinaryHeap<Type>::insert(Type element) {
    elements.push_back(element);
    if (elements.size() != 1) {
        upheap(elements.size() - 1);
    }
}
template <typename Type>
void BinaryHeap<Type>::remove(Type element) {
    
}
template <typename Type>
void BinaryHeap<Type>::upheap(int index) {
    if (index == -1) { return; }
    int parentIndex = (index) / 2 - (index % 2 == 0 ? 1 : 0);
    if (elements[parentIndex] > elements[index]) {
        swap(elements[parentIndex], elements[index]);
        upheap(parentIndex);
    }
}
template <typename Type>
void BinaryHeap<Type>::downheap(int index) {
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int lastIndex = elements.size() - 1;
    if (leftIndex <= lastIndex) {
        if (rightIndex <= lastIndex) {
            if (elements[leftIndex] < elements[rightIndex]) {
                if (elements[leftIndex] < elements[index]) {
                    swap(elements[leftIndex], elements[index]);
                    downheap(leftIndex);
                }
                else if (elements[rightIndex] < elements[index]) {
                    swap(elements[rightIndex], elements[index]);
                    downheap(rightIndex);
                }
            }
            else {
                if (elements[rightIndex] < elements[index]) {
                    swap(elements[rightIndex], elements[index]);
                    downheap(rightIndex);
                }
                else if (elements[leftIndex] < elements[index]) {
                    swap(elements[leftIndex], elements[index]);
                    downheap(leftIndex);
                }
            }
        }
        else {
            if (elements[leftIndex] < elements[index]) {
                swap(elements[leftIndex], elements[index]);
            }
        }
    }
}
