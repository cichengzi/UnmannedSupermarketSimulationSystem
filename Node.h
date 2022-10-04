//
// Created by cichengzi on 2022/8/15.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_NODE_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_NODE_H

#include"Commodity.h"

class Node {
private:
    Commodity data;
    Node *next;

public:
    Node();

    Node(Commodity d);

    Node(Commodity d, Node *nt);

    Commodity getCommodity();

    Node* getNext();

    std::string getName();

    void setCommodity(Commodity d);

    void setNext(Node* nt);

    void setCount(int num);
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_NODE_H
