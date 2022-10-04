#include"LinkedList.h"

LinkedList::LinkedList() {
    front = nullptr;
    back = nullptr;
}

void LinkedList::addCommodity(Commodity c) {
    if (front == nullptr) {
        front = back = new Node(c);
    } else {
        Node *nd = new Node(c);
        back->setNext(nd);
        back = nd;
    }
}

Commodity LinkedList::getCommodityByIndex(int index) {
    if (index < 0) {
        printf("invalid index!");
        return Commodity();
    }
    Node *cur = front;
    while (cur != nullptr && index-- > 0) {
        cur = cur->getNext();
    }
    if (cur != nullptr)
        return cur->getCommodity();
    return Commodity();
}

void LinkedList::clear() {
    front = nullptr;
    back = nullptr;
}

void LinkedList::removeCommodityById(unsigned long idx) {
    if (front == nullptr) {

    } else if (front->getCommodity().getId() == idx) {
        front = front->getNext();
        if (front == nullptr)
            back = nullptr;
    } else {
        Node *prev = front;
        Node *cur = front->getNext();
        while (cur != nullptr && cur->getCommodity().getId() != idx) {
            prev = cur;
            cur = cur->getNext();
        }
        if (cur != nullptr) {
            prev->setNext(cur->getNext());
            if (cur == back)
                back = prev;
        }
    }
}

void LinkedList::removeCommodityByIndex(int index) {
    Commodity c = getCommodityByIndex(index);
    if (c.getNumber() != -1)
        removeCommodityById(c.getId());
}

void LinkedList::modifyCommodityNumber(unsigned long idx, int num) {
    if (front != nullptr) {
        if (num > 0) {
            Node *cur = front;
            while (cur != nullptr && cur->getCommodity().getId() != idx) {
                cur = cur->getNext();
            }
            cur->setCount(num);
        } else if (num == 0) {
            removeCommodityById(idx);
        } else {
            printf("invalid number!");
        }
    }
}

Commodity LinkedList::getCommodityById(unsigned long idx) {
    Node *cur = front;
    while (cur != nullptr && cur->getCommodity().getId() != idx)
        cur = cur->getNext();
    if (cur != nullptr) {
        return cur->getCommodity();
    }
    return Commodity();
}

double LinkedList::getPrice(unsigned long idx) {
    return getCommodityById(idx).getPrice();
}

std::string LinkedList::getName(unsigned long idx) {
    return getCommodityById(idx).getName();
}

std::string LinkedList::toString() {
    Node *cur = front;
    std::string content;
    while (cur != nullptr) {
        if (content.length() == 0)
            content += cur->getCommodity().toString();
        else
            content += "\n" + cur->getCommodity().toString();
        cur = cur->getNext();
    }
    return content;
}

bool LinkedList::isEmpty() {
    return front == nullptr && back == nullptr;
}

int LinkedList::getNumber(unsigned long idx) {
    return getCommodityById(idx).getNumber();
}

Node * LinkedList::getFront() {
    return front;
}

Node * LinkedList::getBack() {
    return back;
}

void LinkedList::setPrice(unsigned long idx, double p) {
    Node *cur = front;
    while (cur != nullptr) {
        if (cur->getCommodity().getId() == idx) {
            cur->getCommodity().setPrice(p);
            return;
        }
        cur = cur->getNext();
    }
}

void LinkedList::setNumber(unsigned long idx, int num) {
    Node *cur = front;
    while (cur != nullptr) {
        if (cur->getCommodity().getId() == idx) {
            cur->getCommodity().setNumber(num);
            return;
        }
        cur = cur->getNext();
    }
}

std::string LinkedList::getDescription(unsigned long idx) {
    return getCommodityById(idx).getDescription();
}

void LinkedList::setDescription(unsigned long idx, std::string d) {
    Node *cur = front;
    while (cur != nullptr) {
        if (cur->getCommodity().getId() == idx) {
            cur->getCommodity().setDescription(d);
            return;
        }
        cur = cur->getNext();
    }
}

std::vector<Commodity> LinkedList::getAllCommodities() {
    std::vector<Commodity> allCommodities;
    Node* cur = front;
    while (cur != nullptr) {
        allCommodities.push_back(cur->getCommodity());
        cur = cur->getNext();
    }
    return allCommodities;
}