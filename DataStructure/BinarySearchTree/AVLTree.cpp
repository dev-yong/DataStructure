//
//  AVLTree.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/28.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include "AVLNode.cpp"
#include <queue>

template <typename Type>
class AVLTree {

public:
    enum Direction {
        LL, RR, LR, RL, none
    };
    // MARK:- public
    // MARK: constructor
    AVLTree();
    ~AVLTree();
    // MARK: Accessors
    bool isEmpty();
    Type minimum();
    Type maximum();
    bool find(Type element);
    int height();
    // MARK: Mutators
    void insert(Type element);
    void remove(Type element);
    void clear();
private:
    //MARK:- private
    // MARK: Accessors
    AVLNode<Type>* minimum(AVLNode<Type>* node);
    AVLNode<Type>* maximum(AVLNode<Type>* node);
    bool find(AVLNode<Type>* node, Type element);
    int height(AVLNode<Type>* node, int depth = 0);
    int getHeight(AVLNode<Type>* node);
    Direction unbalancedDirection(AVLNode<Type>* node, int element);
    // MARK: Mutators
    AVLNode<Type>* insert(AVLNode<Type>* current, Type element);
    AVLNode<Type>* remove(AVLNode<Type>* current, Type element);
    AVLNode<Type>* rotateRight(AVLNode<Type>* x); // for Slash /
    AVLNode<Type>* rotateLeft(AVLNode<Type>* x); // for Angle Bracket <
    // SlashType /
    // AngleBracketType <
    void clear(AVLNode<Type>* current);
    AVLNode<Type>* root;

};

template <typename Type>
AVLTree<Type>::AVLTree() {
    this->root = 0;
}
template <typename Type>
AVLTree<Type>::~AVLTree() {
    this->clear();
}
template <typename Type>
bool AVLTree<Type>::isEmpty() {
    return this->root == 0;
}
template <typename Type>
Type AVLTree<Type>::minimum() {
    if (this->isEmpty()) {
        throw;
    }
    return this->minimum(this->root);
}
template <typename Type>
Type AVLTree<Type>::maximum() {
    if (this->isEmpty()) {
        throw;
    }
    return this->maximum(this->root);
}
template <typename Type>
bool AVLTree<Type>::find(Type element) {
    if (this->isEmpty()) {
        return false;
    }
    return this->find(this->root, element);
}
template <typename Type>
int AVLTree<Type>::height() {
    if (this->isEmpty()) {
        return -1;
    }
    return this->root->height;
}
template <typename Type>
int AVLTree<Type>::getHeight(AVLNode<Type>* node) {
    if (node == 0) {
        return -1;
    }
    int leftHeight = (node->hasLeft() ? node->left->height : -1);
    int rightHeight = (node->hasRight() ? node->right->height : -1);
    return std::max(leftHeight, rightHeight) + 1;
}
template <typename Type>
typename AVLTree<Type>::Direction AVLTree<Type>::unbalancedDirection(AVLNode<Type>* node, int element) {
    int difference = this->getHeight(node->left) - this->getHeight(node->right);
    if (difference > 1) { // Left
        if (node->left->retrieve() > element) {
            return LL;
        }
        else {
            return LR;
        }
    }
    else if (difference < -1) { // Right
        if (node->right->retrieve() > element) {
            return RL;
        }
        else {
            return RR;
        }
    }
    else {
        return none;
    }
}
template <typename Type>
void AVLTree<Type>::insert(Type element) {
    this->root = this->insert(this->root, element);
}
template <typename Type>
void AVLTree<Type>::remove(Type element) {
    this->root = this->remove(this->root, element);
}
template <typename Type>
void AVLTree<Type>::clear() {
    this->clear(this->root);
}
template <typename Type>
bool AVLTree<Type>::find(AVLNode<Type>* node, Type element) {
    if (node->retrieve() == element) {
        return true;
    }
    else if (node->retrieve() > element) {
        this->find(node->left, element);
    }
    else {
        this->find(node->right, element);
    }
}
template <typename Type>
AVLNode<Type>* AVLTree<Type>::insert(AVLNode<Type>* current, Type element) {
    if (current == 0) {
        return new AVLNode<Type>(element);
    }
    else if (current->retrieve() > element) {
        AVLNode<Type>* node = this->insert(current->left, element);
        current->left = node;
        node->parent = current;
    }
    else {
        AVLNode<Type>* node = this->insert(current->right, element);
        current->right = node;
        node->parent = current;
    }
    switch (this->unbalancedDirection(current, element)) {
        case LL:
            this->rotateRight(current);
            break;
        case RR:
            this->rotateLeft(current);
            break;
        case LR:
            current->left = this->rotateLeft(current->left);
            current->left->parent = current;
            current = this->rotateRight(current);
            break;
        case RL:
            current->right = this->rotateRight(current->right);
            current->right->parent = current;
            current = this->rotateLeft(current);
            break;
        case none:
            break;
    }
    current->height = this->getHeight(current);

    return current;
}
template <typename Type>
AVLNode<Type>* AVLTree<Type>::remove(AVLNode<Type>* current, Type element) {
    //todo
    throw;
}
template <typename Type>
AVLNode<Type>* AVLTree<Type>::rotateRight(AVLNode<Type>* x) {
    AVLNode<Type>* y = x->left;
    AVLNode<Type>* z = y->right;
    y->right = x;
    y->parent = x->parent;
    x->parent = y;
    x->left = z;
    if (z != 0) {
        z->parent = x;
    }
    x->height = this->getHeight(x);
    y->height = this->getHeight(y);
    return y;
}
template <typename Type>
AVLNode<Type>* AVLTree<Type>::rotateLeft(AVLNode<Type>* x) {
    AVLNode<Type>* y = x->right;
    AVLNode<Type>* z = y->left;
    y->left = x;
    y->parent = x->parent;
    x->parent = y;
    x->right = z;
    if (z != 0) {
        z->parent = x;
    }
    x->height = this->getHeight(x);
    y->height = this->getHeight(y);
    return y;
}
template <typename Type>
void AVLTree<Type>::clear(AVLNode<Type>* current) {
    if (current == 0) {
        return;
    }
    this->clear(current->left);
    this->clear(current->right);
    delete current;
}
