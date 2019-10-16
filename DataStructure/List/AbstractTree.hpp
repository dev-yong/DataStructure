//
//  AbstractTree.hpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/16.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#ifndef AbstractTree_hpp
#define AbstractTree_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename Type>
class AbstractTree {

public:
    virtual ~AbstractTree() {};
    virtual Type retrieve() const = 0;
    virtual AbstractTree* parent() const = 0;
    virtual int degree() const = 0;
    virtual bool isRoot() const = 0;
    virtual bool isLeaf() const = 0;
    virtual AbstractTree* childAt(int index) const = 0;
    virtual int height() const = 0;

    virtual void insert(Type const& element) = 0;
    virtual void insert(AbstractTree<Type>* tree) = 0;
};

#endif /* AbstractTree_hpp */
