//
//  main.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>
#include "AbstractDataType.hpp"

using namespace std;

void testAbstractList_LinkedList() {
    AbstractList<int>* list = new AbstractList_LinkedList<int>();
    list->insertAfter(0, 1);
    list->insertAfter(0, 2);
    list->insertAfter(0, 3);
    list->insertAfter(0, 4);
    list->insertAfter(0, 5);
    list->insertAfter(0, 6);
    list->insertAfter(0, 7);
    list->insertAfter(0, 8);
    list->log();
    delete list;
}

void testAbstractSortedList_BST() {
    AbstractSortedList<int>* sortedList = new AbstractSortedList_BST<int>();
    sortedList->insert(5);
    sortedList->insert(3);
    sortedList->insert(4);
    sortedList->insert(2);
    sortedList->insert(10);
    sortedList->insert(8);
                       
    delete sortedList;
}
void testBST() {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(4);
    bst.insert(2);
    bst.insert(10);
    bst.insert(8);
    bst.log();
    bst.remove(5);
    bst.log();
    cout<<bst.height()<<endl;
}
void testBinaryHeap() {
    BinaryHeap<int> binaryheap;
    binaryheap.push(8);
    binaryheap.push(4);
    binaryheap.push(12);
    binaryheap.push(2);
    binaryheap.pop();
    binaryheap.push(10);
}
void testAbstractPriorityQueue_BinaryHeap() {
    AbstractPriorityQueue<int>* priorityQueue = new AbstractPriorityQueue_BinaryHeap<int>();
    priorityQueue->push(8);
    priorityQueue->push(4);
    priorityQueue->push(12);
    priorityQueue->push(2);
    priorityQueue->pop();
    priorityQueue->push(10);
    delete priorityQueue;
}


int main() {

//    testAbstractList_LinkedList();
//
//    testAbstractSortedList_BST();
//
//    testBST();

    testBinaryHeap();

    testAbstractPriorityQueue_BinaryHeap();

    return 0;
}
