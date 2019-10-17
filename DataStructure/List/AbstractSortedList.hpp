//
//  AbstractSortedList.hpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/17.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#ifndef AbstractSortedList_hpp
#define AbstractSortedList_hpp

#include <iostream>

using namespace std;

template <typename Type>
class AbstractSortedList {

public:
    virtual ~AbstractSortedList() = 0;
    virtual bool isEmpty() = 0;
    virtual Type minimum() = 0;
    virtual Type maximum() = 0;
    virtual bool find(Type element) = 0;
    virtual void insert(Type element) = 0;
    virtual void remove(Type element) = 0;
    
};

#endif /* AbstractSortedList_hpp */
