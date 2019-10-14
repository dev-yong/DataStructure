//
//  AbstractList.hpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#ifndef AbstractList_hpp
#define AbstractList_hpp

#include <iostream>

using namespace std;

template <typename Type>
class AbstractList {

public:
    virtual ~AbstractList() {};
    virtual int indexOf(Type element) = 0;
    virtual bool remove(Type element) = 0;
    virtual void insertAfter(int index, Type element) = 0;
    virtual void clear() = 0;
    virtual int count() = 0;
    virtual void log() = 0;
};

#endif /* AbstractList_hpp */
