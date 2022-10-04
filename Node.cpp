#include"Node.h"

Node::Node() {
    data = Commodity();
    next = nullptr;
}

Node::Node(Commodity d) {
    data = d;
    next = nullptr;
}

Node::Node(Commodity d, Node *nt) {
    data = d;
    next = nt;
}

Commodity Node::getCommodity() {
    return data;
}

Node * Node::getNext() {
    return next;
}

void Node::setCommodity(Commodity d) {
    data = d;
}

void Node::setNext(Node *nt) {
    next = nt;
}

void Node::setCount(int num) {
    data.setNumber(num);
}

std::string Node::getName() {
    return data.getName();
}