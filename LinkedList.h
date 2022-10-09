//
// Created by cichengzi on 2022/8/16.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_LINKEDLIST_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_LINKEDLIST_H

#include"Node.h"
#include<vector>

class LinkedList {
private:
    Node* front; // 链表的头结点
    Node* back; // 链表的尾结点

public:
    LinkedList(); // 链表类的默认构造函数

    void addCommodity(Commodity c); // 添加商品

    Commodity getCommodityByIndex(int index); // 通过索引获取商品

    Commodity getCommodityById(unsigned long idx); // 通过编号idx获取商品

    void removeCommodityById(unsigned long idx); // 从链表中移除编号为idx的商品

    void removeCommodityByIndex(int index); // 通过索引移除商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改编号为idx的商品数量为num

    void clear(); // 清空链表中所有的商品

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品的名称

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    std::string toString(); // 获取链表类的string描述

    bool isEmpty(); // 判断链表是否为空

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    Node* getFront(); // 获取链表的头结点

    Node* getBack(); // 获取链表的尾结点

    void setPrice(unsigned long idx, double p); // 设置编号为idx的商品的价格为p

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    std::vector<Commodity> getAllCommodities(); // 获取链表中所有的商品
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_LINKEDLIST_H
