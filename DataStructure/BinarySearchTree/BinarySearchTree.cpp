//
//  BinarySearchTree.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/17.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>
#include "BinarySaerchNode.cpp"
#include <queue>

template <typename Type>
class BinarySearchTree {

public:
    // MARK:- public
    // MARK: constructor
    BinarySearchTree();
    ~BinarySearchTree();
    // MARK: Accessors
    bool isEmpty();
    Type minimum();
    Type maximum();
    bool find(Type element);
    int height();
    void log();
    // MARK: Mutators
    void insert(Type element);
    void remove(Type element);
    void clear();
private:
    //MARK:- private
    // MARK: Accessors
    BinarySearchNode<Type>* minimum(BinarySearchNode<Type>* node);
    BinarySearchNode<Type>* maximum(BinarySearchNode<Type>* node);
    bool find(BinarySearchNode<Type>* node, Type element);
    int height(BinarySearchNode<Type>* node, int depth = 0);
    // MARK: Mutators
    BinarySearchNode<Type>* insert(BinarySearchNode<Type>* current, Type element);
    BinarySearchNode<Type>* remove(BinarySearchNode<Type>* current, Type element);
    void clear(BinarySearchNode<Type>* current);
    BinarySearchNode<Type>* root;

};

template <typename Type>
BinarySearchTree<Type>::BinarySearchTree() {
    this->root = 0;
}
template <typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {
    this->clear();
}
template <typename Type>
bool BinarySearchTree<Type>::isEmpty() {
    return this->root == 0;
}
template <typename Type>
Type BinarySearchTree<Type>::minimum() {
    if (this->isEmpty()) {
        throw; //underflow
    }
    return this->minimum(this->root)->retrieve();
}
template <typename Type>
Type BinarySearchTree<Type>::maximum() {
    if (this->isEmpty()) {
        throw; //underflow
    }
    return this->maximum(this->root)->retrieve();
}
template <typename Type>
bool BinarySearchTree<Type>::find(Type element) {
    if (this->isEmpty()) {
        return false;
    }
    return this->find(this->root, element);
}
template <typename Type>
int BinarySearchTree<Type>::height() {
    if (this->isEmpty()) {
        return -1;
    }
    return this->height(this->root);
}
template <typename Type>
void BinarySearchTree<Type>::log() {
    if (this->isEmpty()) {
        cout << "Tree is empty";
    }
    queue<BinarySearchNode<Type>*> queue;
    queue.push(this->root);
    while(!queue.empty()) {
        BinarySearchNode<Type>* node = queue.front();
        cout << node->retrieve() << " ";
        queue.pop();
        if (node->hasLeft()) {
            queue.push(node->left);
        }
        if (node->hasRight()) {
            queue.push(node->right);
        }
    }
    cout << endl;
}
template <typename Type>
void BinarySearchTree<Type>::insert(Type element) {
    if (this->isEmpty()) {
        this->root = new BinarySearchNode<Type>(element);
    }
    else {
        this->insert(this->root, element);
    }
}
template <typename Type>
void BinarySearchTree<Type>::remove(Type element) {
    if (this->isEmpty()) {
        return;
    }
    else {
        this->remove(this->root, element);
    }
}
template <typename Type>
void BinarySearchTree<Type>::clear() {
    if (this->isEmpty()) {
        return;
    }
    this->clear(this->root);
}
template <typename Type>
BinarySearchNode<Type>* BinarySearchTree<Type>::minimum(BinarySearchNode<Type>* node) {
    return node->hasLeft() ? this->minimum(node->left) : node;
}
template <typename Type>
BinarySearchNode<Type>* BinarySearchTree<Type>::maximum(BinarySearchNode<Type>* node) {
    return node->hasRight() ? this->maximum(node->right) : node;
}
template <typename Type>
bool BinarySearchTree<Type>::find(BinarySearchNode<Type>* node, Type element) {
    if (node->retrieve() == element) {
        return true;
    }
    else if (node->retrieve() > element) {
        return this->find(node->left, element);
    }
    else {
        return this->find(node->right, element);
    }
}
template <typename Type>
int BinarySearchTree<Type>::height(BinarySearchNode<Type>* node, int depth) {
    if (node->isLeaf()) {
        return depth;
    }
    int height = 0;
    if (node->hasLeft()) {
        return max(height, this->height(node->left, depth + 1));
    }
    if (node->hasRight()) {
        return max(height, this->height(node->right, depth + 1));
    }
    return height;
}
template <typename Type>
BinarySearchNode<Type>* BinarySearchTree<Type>::insert(BinarySearchNode<Type>* current, Type element) {
    if (current == 0) {
        current = new BinarySearchNode<Type>(element);
    }
    else if (current->retrieve() > element) {
        BinarySearchNode<Type>* node = insert(current->left, element);
        current->left = node;
        if (node != 0) {
            node->parent = current;
        }
    }
    else {
        BinarySearchNode<Type>* node = insert(current->right, element);
        current->right = node;
        if (node != 0) {
            node->parent = current;
        }
    }
    return current;
}
template <typename Type>
BinarySearchNode<Type>* BinarySearchTree<Type>::remove(BinarySearchNode<Type>* current, Type element) {
    if (current == 0) {
        return 0;
    }
    else if (current->retrieve() > element) {
        BinarySearchNode<Type>* node = this->remove(current->left, element);
        current->left = node;
        if (node != 0) {
            node->parent = current;
        }
    }
    else if (current->retrieve() < element) {
        BinarySearchNode<Type>* node = this->remove(current->right, element);
        current->right = node;
        if (node != 0) {
            node->parent = current;
        }
    }
    else { // current->retrieve() == element
        BinarySearchNode<Type>* promotableNode = 0;
        if (current->hasRight()) {
            BinarySearchNode<Type>* minimumNode = this->minimum(current->right);
            BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(minimumNode->retrieve());
            current->right = this->remove(current->right, minimumNode->retrieve());
            newNode->parent = current->parent;
            newNode->left = current->left;
            newNode->right = current->right;
            promotableNode = newNode;
            if (current == this->root) {
                this->root = promotableNode;
            }
        }
        else if (current->hasLeft())  {
            promotableNode = current->left;
        }
        delete current;
        return promotableNode;
    }
    return current;
}
template <typename Type>
void BinarySearchTree<Type>::clear(BinarySearchNode<Type>* current) {
    if (current == 0) {
        return;
    }
    this->clear(current->left);
    this->clear(current->right);
    delete current;
}
