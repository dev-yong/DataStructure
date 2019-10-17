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
    BinarySearchTree() {
        this->root = 0;
    }
    ~BinarySearchTree() {
        this->clear();
        delete this->root;
    }
    // MARK: Accessors
    bool isEmpty() {
        return root == 0;
    }
    Type minimum() {
        if (isEmpty()) {
            throw; //underflow
        }
        return minimum(root)->retrieve();
    }
    Type maximum() {
        if (isEmpty()) {
            throw; //underflow
        }
        return maximum(root)->retrieve();
    }
    bool find(Type element) {
        if (isEmpty()) {
            return false;
        }
        return find(root, element);
    }
    int height() {
        if (this->isEmpty()) {
            return -1;
        }
        return height(this->root);
    }
    void log() {
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
    // MARK: Mutators
    void insert(Type element) {
        if (isEmpty()) {
            this->root = new BinarySearchNode<Type>(element);
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
    void clear() {
        if (this->isEmpty()) {
            return;
        }
        this->clear(this->root);
    }
private:
    //MARK:- private
    BinarySearchNode<Type>* minimum(BinarySearchNode<Type>*& node) {
        return node->left;// != 0 ? node->getLeft()->minimum() : node;
    }
    BinarySearchNode<Type>* maximum(BinarySearchNode<Type>*& node) {
        return node->right;// != 0 ? node->getRight()->maixmum() : node;
    }
    bool find(BinarySearchNode<Type>*& node, Type element) {
        Type value = node->retrieve();
        if (value == element) {
            return true;
        }
        else if (value > element) {
            return find(node->left, element);
        }
        else if (value < element) {
            return find(node->right, element);
        }
        else {
            return false;
        }
    }
    int height(BinarySearchNode<Type>*& node, int depth = 0) {
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
    void insert(BinarySearchNode<Type>* current, Type& element) {
        if (current->retrieve() > element) {
            if (current->left == 0) {
                BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(element);
                newNode->parent = current;
                current->left = newNode;
            }
            else {
                insert(current->left, element);
            }
        }
        else {
            if (current->right == 0) {
                BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(element);
                newNode->parent = current;
                current->right = newNode;
            }
            else {
                insert(current->right, element);
            }
        }
    }
    void remove(BinarySearchNode<Type>* current, Type& element) {
        if (current->retrieve() == element) {
            if (current->hasLeft() && current->hasRight() != 0) {
                BinarySearchNode<Type>* rightMinimumNode = minimum(current->right);
                Type minimumValue = rightMinimumNode->retrieve();
                BinarySearchNode<Type>* newNode = new BinarySearchNode<Type>(minimumValue);
                if (rightMinimumNode->isLeaf()) {
                    removeWhenLeaf(rightMinimumNode);
                } else if (!rightMinimumNode->hasLeft() && rightMinimumNode->hasRight()) {
                    removeWhenHasOnlyLeft(rightMinimumNode);
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
                removeWhenHasOnlyLeft(current);
            }
            else if (!current->hasLeft() && current->hasRight()) {
                removeWhenHasOnlyRight(current);
            }
            else {
                removeWhenLeaf(current);
            }
        }
        else if (current->retrieve() > element) {
            remove(current->left, element);
        }
        else {
            remove(current->right, element);
        }
    }
    void clear(BinarySearchNode<Type>* current) {
           if (current->hasLeft() && current->hasRight()) {
               clear(current->left);
               clear(current->right);
           }
           else if (current->hasLeft() && !current->hasRight()) {
               clear(current->left);
           }
           else if (!current->hasLeft() && current->hasRight()) {
               clear(current->right);
           }
           else {
               removeWhenLeaf(current);
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
