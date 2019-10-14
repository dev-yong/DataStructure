//
//  Node.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename Type>
class Node {

public:
    Node(Type element): element(element), next(0) {}
    Type retrieve() const;
    Node* next;
private:
    Type element;

};

template <typename Type>
Type Node<Type>::retrieve() const {
    return this->element;
}

