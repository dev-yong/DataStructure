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
    void insert(BinarySearchNode<Type>* current, Type element);
    void remove(BinarySearchNode<Type>* current, Type element);
    void clear(BinarySearchNode<Type>* current);
    void removeWhenLeaf(BinarySearchNode<Type>* current);
    void removeWhenHasOnlyLeft(BinarySearchNode<Type>* current);
    void removeWhenHasOnlyRight(BinarySearchNode<Type>* current);
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
    return this->root->isLeaf();
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
void BinarySearchTree<Type>::insert(BinarySearchNode<Type>* current, Type element) {
    if (current->retrieve() > element) {
        if (!current->hasLeft()) {
            BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(element);
            newNode->parent = current;
            current->left = newNode;
        }
        else {
            this->insert(current->left, element);
        }
    }
    else {
        if (!current->hasRight()) {
            BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(element);
            newNode->parent = current;
            current->right = newNode;
        }
        else {
            this->insert(current->right, element);
        }
    }
}
template <typename Type>
void BinarySearchTree<Type>::remove(BinarySearchNode<Type>* current, Type element) {
    if (current->retrieve() == element) {
        if (current->hasLeft() && current->hasRight()) {
            BinarySearchNode<Type>* rightMinimumNode = minimum(current->right);
            Type minimumValue = rightMinimumNode->retrieve();
            BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(minimumValue);
            if (rightMinimumNode->isLeaf()) {
                this->removeWhenLeaf(rightMinimumNode);
            } else if (!rightMinimumNode->hasLeft() && rightMinimumNode->hasRight()) {
                this->removeWhenHasOnlyRight(rightMinimumNode);
            }
            newNode->parent = current->parent;
            newNode->left = current->left;
            newNode->right = current->right;
            if (current == this->root) {
                this->root = newNode;
            }
            delete current;
        }
        else if (current->hasLeft() && !current->hasRight()) {
            this->removeWhenHasOnlyLeft(current);
        }
        else if (!current->hasLeft() && current->hasRight()) {
            this->removeWhenHasOnlyRight(current);
        }
        else {
            this->removeWhenLeaf(current);
        }
    }
    else if (current->retrieve() > element) {
        this->remove(current->left, element);
    }
    else {
        this->remove(current->right, element);
    }
}
template <typename Type>
void BinarySearchTree<Type>::clear(BinarySearchNode<Type>* current) {
    if (current->hasLeft() && current->hasRight()) {
        this->clear(current->left);
        this->clear(current->right);
    }
    else if (current->hasLeft() && !current->hasRight()) {
        this->clear(current->left);
    }
    else if (!current->hasLeft() && current->hasRight()) {
        this->clear(current->right);
    }
    this->removeWhenLeaf(current);
}
template <typename Type>
void BinarySearchTree<Type>::removeWhenLeaf(BinarySearchNode<Type>* current) {
    if (current == root) {
        delete root;
    }
    else if (current->parent->left == current) {
        current->parent->left = 0;
        delete current;
    }
    else {
        current->parent->right = 0;
        delete current;
    }
}
template <typename Type>
void BinarySearchTree<Type>::removeWhenHasOnlyLeft(BinarySearchNode<Type>* current) {
    if (current->parent->left == current) {
        current->parent->left = current->left;
        current->left->parent = current->parent;
        delete current;
    } else {
        current->parent->right = current->left;
        current->left->parent = current->parent;
        delete current;
    }
}
template <typename Type>
void BinarySearchTree<Type>::removeWhenHasOnlyRight(BinarySearchNode<Type>* current) {
    if (current->parent->left == current) {
        current->parent->left = current->right;
        current->right->parent = current->parent;
        delete current;
    } else {
        current->parent->right = current->right;
        current->right->parent = current->parent;
        delete current;
    }
}
