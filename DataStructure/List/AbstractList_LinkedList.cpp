//
//  AbstractList_LinkedList.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include "AbstractList.hpp"
#include "../LinkedList/LinkedList.cpp"

template <typename Type>
class AbstractList_LinkedList: public AbstractList<Type> {

public:
    AbstractList_LinkedList();
    ~ AbstractList_LinkedList() override {
        delete linkedList;
    }
    int indexOf(Type element) override;
    bool remove(Type element) override;
    void insertAfter(int index, Type element) override;
    void clear() override;
    int count() override;
    void log() override;
private:
    LinkedList<Type>* linkedList;

};
template <typename Type>
AbstractList_LinkedList<Type>::AbstractList_LinkedList() {
    linkedList = new LinkedList<Type>();
}
template <typename Type>
int AbstractList_LinkedList<Type>::indexOf(Type element) {
    return this->linkedList->indexOf(element);
}
template <typename Type>
bool AbstractList_LinkedList<Type>::remove(Type element) {
    return this->linkedList->remove(element);
}
template <typename Type>
void AbstractList_LinkedList<Type>::insertAfter(int index, Type element) {
    this->linkedList->insert(index, element);
}
template <typename Type>
void AbstractList_LinkedList<Type>::clear() {
    return this->linkedList->clear();
}
template <typename Type>
int AbstractList_LinkedList<Type>::count() {
    return this->linkedList->count();
}
template <typename Type>
void AbstractList_LinkedList<Type>::log() {
    this->linkedList->log();
}
