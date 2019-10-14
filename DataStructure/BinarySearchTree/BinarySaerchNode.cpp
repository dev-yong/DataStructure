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
    BinarySearchNode<Type>* getParent() {
        return this->parent;
    }
    BinarySearchNode<Type>* getLeft() {
        return this->left;
    }
    BinarySearchNode<Type>* getRight() {
        return this->right;
    }
    bool isLeaf() {
        return this->left == 0 && this->right == 0;
    }
    bool hasLeft() {
        return this->left == 0;
    }
    bool hasRight() {
        return this->right == 0;
    }

private:
    BinarySearchNode<Type>* parent;
    BinarySearchNode<Type>* left;
    BinarySearchNode<Type>* right;
    Type element;

};

template <typename Type>
class BinarySearchTree {

public:
    BinarySearchTree() {
        root = 0;
    }
    ~BinarySearchTree() {
        delete root;
    }
    bool isEmpty() {
        return root == 0;
    }
    Type minimum() {
        if (isEmpty()) {
            throw;
        }
        return minimum(root)->retrieve();
    }
    Type maximum() {
        if (isEmpty()) {
            throw;
        }
        return maximum(root)->retrieve();
    }
    bool find(Type element) {
        if (isEmpty()) {
            throw;
        }
        return find(root, element);
    }
    void insert(Type element) {
        if (isEmpty()) {
            root = new BinarySearchNode<Type>(element);
        }
        else {
            insert(root, element);
        }
    }
    void remove(Type element) {
        if (isEmpty()) {
            return;
        }
        else {
            remove(root, element);
        }
    }

private:
    BinarySearchNode<Type>* minimum(BinarySearchNode<Type>*& node) {
        return node->getLeft() != 0 ? node->getLeft()->minimum() : node;
    }
    BinarySearchNode<Type>* maximum(BinarySearchNode<Type>*& node) {
        return node->getRight() != 0 ? node->getRight()->maixmum() : node;
    }
    bool find(BinarySearchNode<Type>*& node, Type element) {
        Type value = node->retrieve();
        if (value == element) {
            return true;
        }
        else if (value > element) {
            return find(node->getLeft(), element);
        }
        else if (value < element) {
            return find(node->getRight(), element);
        }
        else {
            return false;
        }
    }

    void insert(BinarySearchNode<Type>* current, Type& element) {
        if (current->element > element) {
            if (current->left == 0) {
                BinarySearchNode<Type> newNode = new BinarySearchNode<Type>(element);
                newNode.parent = current;
                current->left = newNode;
            }
            else {
                current->left->insert(element);
            }
        }
        else {
            if (current->right == 0) {
                BinarySearchNode<Type> newNode = new BinarySearchNode<Type>(element);
                newNode.parent = this;
                current->right = newNode;
            }
            else {
                current->right->insert(element);
            }
        }
    }
    void remove(BinarySearchNode<Type>* current, Type& element) {
        if (current->element == element) {
            if (current->getLeft() != 0 && current->getRight() != 0) {
                BinarySearchNode<Type>* rightMinimumNode = minimum(current->getRight());
                BinarySearchNode<Type>* newNode = BinarySearchNode<Type>(rightMinimumNode->element);
                if (rightMinimumNode->isLeaf()) {
                    removeWhenLeaf(rightMinimumNode);
                } else if (!rightMinimumNode->hasLeft() && rightMinimumNode->hasRight()) {
                    removeWhenHasOnlyLeft(rightMinimumNode);
                }
                newNode->parent = current->parent;
                newNode->left = current->left;
                newNode->right = current->right;
            }
            else if (current->hasLeft() && !current->hasRight()) {
                removeWhenHasOnlyLeft(current);
            }
            else if (!current->hasLeft() && current->hasRight()) {
                removeWhenHasOnlyRight(current);
            }
            else {
                removeWhenLeaf(current);
            }
        }
        else if (current->element > element) {
            remove(current->getLeft(), element);
        }
        else {
            remove(current->getRight(), element);
        }
    }
    void removeWhenLeaf(BinarySearchNode<Type>* current) {
        if (current == root) {
            delete root;
        }
        if (current->parent->left == current) {
            current->parent->left = 0;
            delete current;
        } else {
            current->parent->right = 0;
            delete current;
        }
    }
    void removeWhenHasOnlyLeft(BinarySearchNode<Type>* current) {
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
    void removeWhenHasOnlyRight(BinarySearchNode<Type>* current) {
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

    BinarySearchNode<Type>* root;

};
