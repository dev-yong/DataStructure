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
    BinarySearchNode(Type& element): element(element) {
        parent = 0;
        left = 0;
        right = 0;
    }

    Type retrieve() {
        return this->element;
    }
    bool isLeaf() {
        return this->left == 0 && this->right == 0;
    }
    bool hasLeft() {
        return this->left != 0;
    }
    bool hasRight() {
        return this->right != 0;
    }
    BinarySearchNode<Type>* parent;
    BinarySearchNode<Type>* left;
    BinarySearchNode<Type>* right;

private:
    Type element;

};
