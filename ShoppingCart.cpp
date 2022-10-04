#include"ShoppingCart.h"
#include"Helper.h"

ShoppingCart::ShoppingCart(User us) {
    cartSize = 0;
    user = us;
    carts = new LinkedList[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++) {
        carts[i] = LinkedList();
    }
}

unsigned int ShoppingCart::hash(unsigned long idx) {
    return idx % MAXSIZE;
}

void ShoppingCart::addCommodity(Commodity c) {
    carts[hash(c.getId())].addCommodity(c);
}

void ShoppingCart::removeCommodityById(unsigned long idx) {
    carts[hash(idx)].removeCommodityById(idx);
}

void ShoppingCart::modifyCommodityNumber(unsigned long idx, int num) {
    carts[hash(idx)].modifyCommodityNumber(idx, num);
}

double ShoppingCart::getPrice(unsigned long idx) {
    return carts[hash(idx)].getPrice(idx);
}

std::string ShoppingCart::getName(unsigned long idx) {
    return carts[hash(idx)].getName(idx);
}

int ShoppingCart::getNumber(unsigned long idx) {
    return carts[hash(idx)].getNumber(idx);
}

std::string ShoppingCart::getDescription(unsigned long idx) {
    return carts[hash(idx)].getDescription(idx);
}

Commodity ShoppingCart::getCommodity(unsigned long idx) {
    return carts[hash(idx)].getCommodityById(idx);
}

void ShoppingCart::setNumber(unsigned long idx, int num) {
    carts[hash(idx)].setNumber(idx, num);
}

void ShoppingCart::setDescription(unsigned long idx, std::string d) {
    carts[hash(idx)].setDescription(idx, d);
}

LinkedList ShoppingCart::getAllCommodities() {
    LinkedList list = LinkedList();
    for (int i = 0; i < MAXSIZE; i++) {
        Node *cur = carts[i].getFront();
        while (cur != nullptr) {
            list.addCommodity(cur->getCommodity());
            cur = cur->getNext();
        }
    }
    return list;
}

double ShoppingCart::getTotalPrice() {
    double tol = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        Node *cur = carts[i].getFront();
        while (cur != nullptr) {
            tol += cur->getCommodity().getPrice() * cur->getCommodity().getNumber();
            cur = cur->getNext();
        }
    }
    return tol;
}

void ShoppingCart::clear() {
    for (int i = 0; i < MAXSIZE; i++) {
        carts[i].clear();
    }
}

std::string ShoppingCart::toString() {
    std::string content;
    content += user.toString() + "\n";
    for (int i = 0; i < MAXSIZE; i++) {
        if (carts[i].isEmpty())
            continue;
        content += carts[i].toString() + "\n";
    }
    if (content[content.length() - 1] == '\n')
        content = content.substr(0, content.length() - 1);
    return content;
}

ShoppingCart::ShoppingCart() {
    cartSize = 0;
    user = User();
    carts = new LinkedList[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++) {
        carts[i] = LinkedList();
    }
}

User ShoppingCart::getUser() {
    return user;
}

void ShoppingCart::setUser(User us) {
    user = us;
}

void ShoppingCart::loadShoppingCart() {
    Helper helper;
    std::vector<ShoppingCart> carts = helper.readShoppingCarts();
    //std::cout << "Now in loadShoppingCart, current User: " << currentUser.getName() << std::endl;
    for (ShoppingCart c: carts) {
        if (c.getUser().getName() == getUser().getName()) {
            *this = c;
            break;
        }
    }
}