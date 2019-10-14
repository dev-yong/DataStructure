//
//  LInkedList.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include "Node.cpp"

using namespace std;

template <typename Type>
class LinkedList {

public:
    // MARK:- public
    // MARK: constructor
    LinkedList() {
        head = 0;
        tail = 0;
    }
    ~LinkedList() {
        clear();
    }
    // MARK: Accessors
    bool isEmpty() const;
    int indexOf(Type element) const;
    int count() const;
    Type front() const;
    Type back() const;
    // MARK: Mutators
    void push_front(Type element);
    Type pop_front();
    void push_back(Type element);
    Type pop_back();
    void insert(int index, Type element);
    bool remove(Type element);
    void clear();
    void log();

private:
    //MARK:- private
    Node<Type>* head;
    Node<Type>* tail;
};
// MARK: Accessors
template <typename Type>
bool LinkedList<Type>::isEmpty() const {
    return head == nullptr;
}
template <typename Type>
int LinkedList<Type>::indexOf(Type element) const {
    if (this->isEmpty()) {
        throw;
    }
    int index = 0;
    for(Node<Type>* node = this->head; node != nullptr; node = node->next) {
        if (node->retrieve() == element) {
            return index;
        }
        index++;
    }
    throw;
}
template <typename Type>
int LinkedList<Type>::count() const {
    int count = 0;
    for(Node<Type>* node = this->head; node != nullptr; node = node->next) {
        count++;
    }
    return count;
}
template <typename Type>
Type LinkedList<Type>::front() const {
    if (this->isEmpty()) {
        throw;
    }
    return head->retrieve();
}
template <typename Type>
Type LinkedList<Type>::back() const {
    if (this->tail == nullptr) {
        throw;
    }
    return tail->retrieve();
}
// MARK: Mutators
template <typename Type>
void LinkedList<Type>::push_front(Type element) {
    Node<Type>* newNode = new Node<Type>(element);
    if (this->isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    }
    else {
        newNode->next = this->head->next;
        this->head = newNode;
    }
}
template <typename Type>
Type LinkedList<Type>::pop_front() {
    if (this->isEmpty()) {
        throw;
    }
    // when count == 1
    Type value = this->front();
    if (this->head == this->tail) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        return value;
    }
    else {
        Node<Type>* node = this->head;
        this->head = this->head->next;
        delete node;
        return value;
    }
}
template <typename Type>
void LinkedList<Type>::push_back(Type element) {
    if (this->isEmpty()) {
        this->push_front(element);
    }
    else {
        Node<Type>* newNode = new Node<Type>(element);
        this->tail->next = newNode;
        this->tail = newNode;
    }
}
template <typename Type>
Type LinkedList<Type>::pop_back() {
    if (this->isEmpty()) {
        throw;
    }
    if (this->head == this->tail) {
        return this->pop_front();
    }
    else {
        for(Node<Type>* node = this->head; node != nullptr; node = node->next) {
            if (node->next == this->tail) {
                Type value = this->tail->retrieve();
                this->tail = node;
                delete node->next;
                node->next = nullptr;
                return value;
            }
        }
    }
}
template <typename Type>
void LinkedList<Type>::insert(int index, Type element) {
    if (this->isEmpty()) {
        this->push_front(element);
        return;
    }
    int i = 0;
    for(Node<Type>* node = this->head; node != nullptr; node = node->next) {
        if (i == index) {
            if (node == tail) {
                this->push_back(element);
            }
            else {
                Node<Type>* newNode = new Node<Type>(element);
                newNode->next = node->next;
                node->next = newNode;
            }
            return;
        }
        i++;
    }
    this->push_back(element);
}
template <typename Type>
bool LinkedList<Type>::remove(Type element) {
    if (this->isEmpty()) {
        return false;
    }
    bool isRemoved = false;
    if (this->head->retrieve() == element) {
        this->pop_front();
        isRemoved = true;
    }
    else {
        for(Node<Type>* node = this->head; node != this->tail; node = node->next) {
            Node<Type>* next = node->next;
            if (next->retrieve() == element) {
                if (next == this->tail) {
                    this->tail = node;
                    node->next = nullptr;
                    delete next;
                }
                else {
                    node->next = next->next;
                    next->next = nullptr;
                    delete next;
                }
                isRemoved = true;
            }
        }
    }
    return isRemoved;
}
template <typename Type>
void LinkedList<Type>::clear() {
    Node<Type>* node = this->head;
    Node<Type>* next;
    while(node != 0) {
        next = node->next;
        delete node;
        node = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
}
template <typename Type>
void LinkedList<Type>::log() {
    for(Node<Type>* node = this->head; node != nullptr; node = node->next) {
        cout<<node->retrieve()<<" ";
    }
    cout<<endl;
}
