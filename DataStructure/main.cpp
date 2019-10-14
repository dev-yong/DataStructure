//
//  main.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>
#include "AbstractList.hpp"
#include "List/AbstractList_LinkedList.cpp"

using namespace std;

int main() {
    AbstractList<int>* list = new AbstractList_LinkedList<int>();
    list->insertAfter(0, 1);
    list->insertAfter(0, 2);
    list->insertAfter(0, 3);
    list->insertAfter(0, 4);
    list->insertAfter(0, 5);
    list->insertAfter(0, 6);
    list->insertAfter(0, 7);
    list->insertAfter(0, 8);
    list->log();
    delete list;

    return 0;
}
