//
//  AbstractList_TwoEndedArray.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include "AbstractList.hpp"


template <typename Type>
class AbstractList_TwoEndedArray: AbstractList<Type> {

public:
    AbstractList_TwoEndedArray() override;
    ~AbstractList_TwoEndedArray() override {}
    int indexOf(Type element) override;
    bool remove(Type element) override;
    void insertAfter(int index, Type element) override;
    void clear() override;
    int count() override;
    void log() override;
private:


};
