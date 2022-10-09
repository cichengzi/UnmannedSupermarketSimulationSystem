//
// Created by cichengzi on 2022/8/15.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_NODE_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_NODE_H

#include"Commodity.h"

class Node {
private:
    Commodity data; // 结点类的商品信息
    Node *next; // 下一个结点的指针

public:
    Node(); // 结点类的默认构造函数

    Node(Commodity d); // 带参构造函数1

    Node(Commodity d, Node *nt); // 带参构造函数2

    Commodity getCommodity(); // 获取当前结点的商品信息

    Node* getNext(); // 获取当前结点的下一个结点的指针

    std::string getName(); // 获取当前结点的商品名称

    void setCommodity(Commodity d); // 设置当前结点的商品

    void setNext(Node* nt); // 设置当前结点的下一个结点的指针

    void setCount(int num); // 设置当前结点商品的数量
};
#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_NODE_H
