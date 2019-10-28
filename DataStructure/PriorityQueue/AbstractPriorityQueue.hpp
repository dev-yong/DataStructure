//
//  AbstractPriorityQueue.hpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/17.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#ifndef AbstractPriorityQueue_hpp
#define AbstractPriorityQueue_hpp

#include <iostream>
#include "../BinaryHeap/BinaryHeap.cpp"

template <typename Type>
class AbstractPriorityQueue {

public:
    virtual ~AbstractPriorityQueue() {};
    virtual Type front() = 0;
    virtual int pop() = 0;
    virtual void push(Type element) = 0;

};

#endif /* AbstractPriorityQueue_hpp */
