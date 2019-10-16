//
//  main.cpp
//  DataStructure
//
//  Created by 이광용 on 2019/10/14.
//  Copyright © 2019 GwangYongLee. All rights reserved.
//

#include <iostream>
//#include "AbstractList.hpp"
//#include "List/AbstractList_LinkedList.cpp"
#include "LinkedList/LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;
    for(int i = 0; i<10; i++) {
        list1.push_back(i);
        list2.push_back(i * 10);
    }
    list1.log();
    list2.log();
    list1 = list2;
    list1.log();

    return 0;
}
