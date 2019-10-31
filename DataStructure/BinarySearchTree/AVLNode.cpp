//
//  AVLNode.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/28.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <stdio.h>

template <typename Type>
class AVLNode {
public:
    AVLNode(Type& element): element(element) {
        this->parent = 0;
        this->left = 0;
        this->right = 0;
        this->height = 0;
    }
    Type retrieve();
    bool isLeaf();
    bool hasLeft();
    bool hasRight();
    AVLNode<Type>* parent;
    AVLNode<Type>* left;
    AVLNode<Type>* right;
    int height;

private:
    Type element;

};

template <typename Type>
Type AVLNode<Type>::retrieve() {
    return this->element;
}
template <typename Type>
bool AVLNode<Type>::isLeaf() {
    return this->left == 0 && this->right == 0;
}
template <typename Type>
bool AVLNode<Type>::hasLeft() {
    return this->left != 0;
}
template <typename Type>
bool AVLNode<Type>::hasRight() {
    return this->right != 0;
}
