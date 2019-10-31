//
//  BinarySaerchNode.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename Type>
class BinarySearchNode {
public:
    BinarySearchNode(Type element): element(element) {
        parent = 0;
        left = 0;
        right = 0;
    }
    Type retrieve();
    bool isLeaf();
    bool hasLeft();
    bool hasRight();
    BinarySearchNode<Type>* parent;
    BinarySearchNode<Type>* left;
    BinarySearchNode<Type>* right;

private:
    Type element;

};

template <typename Type>
Type BinarySearchNode<Type>::retrieve() {
    return this->element;
}
template <typename Type>
bool BinarySearchNode<Type>::isLeaf() {
    return this->left == 0 && this->right == 0;
}
template <typename Type>
bool BinarySearchNode<Type>::hasLeft() {
    return this->left != 0;
}
template <typename Type>
bool BinarySearchNode<Type>::hasRight() {
    return this->right != 0;
}
