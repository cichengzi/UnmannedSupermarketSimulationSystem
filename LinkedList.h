//
// Created by cichengzi on 2022/8/16.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_LINKEDLIST_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_LINKEDLIST_H

#include"Node.h"
#include<vector>

class LinkedList {
private:
    Node* front;
    Node* back;

public:
    LinkedList();

    void addCommodity(Commodity c);

    Commodity getCommodityByIndex(int index);

    Commodity getCommodityById(unsigned long idx);

    void removeCommodityById(unsigned long idx);

    void removeCommodityByIndex(int index);

    void modifyCommodityNumber(unsigned long idx, int num);

    void clear();

    double getPrice(unsigned long idx);

    std::string getName(unsigned long idx);

    std::string getDescription(unsigned long idx);

    std::string toString();

    bool isEmpty();

    int getNumber(unsigned long idx);

    Node* getFront();

    Node* getBack();

    void setPrice(unsigned long idx, double p);

    void setNumber(unsigned long idx, int num);

    void setDescription(unsigned long idx, std::string d);

    std::vector<Commodity> getAllCommodities();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_LINKEDLIST_H
