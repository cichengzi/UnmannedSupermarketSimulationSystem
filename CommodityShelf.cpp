#include"CommodityShelf.h"

CommodityShelf::CommodityShelf() {
    shelves = new LinkedList[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++)
        shelves[i] = LinkedList();
}

unsigned int CommodityShelf::hash(unsigned long idx) {
    return idx % MAXSIZE;
}

void CommodityShelf::addCommodity(Commodity c) {
    shelves[hash(c.getId())].addCommodity(c);
}

Commodity CommodityShelf::getCommodity(unsigned long idx) {
    Node *cur = shelves[hash(idx)].getFront();
    while (cur != nullptr) {
        if (cur->getCommodity().getId() == idx)
            return cur->getCommodity();
        cur = cur->getNext();
    }
    return Commodity();
}

void CommodityShelf::removeCommodityById(unsigned long idx) {
    shelves[hash(idx)].removeCommodityById(idx);
}

void CommodityShelf::modifyCommodityNumber(unsigned long idx, int num) {
    shelves[hash(idx)].modifyCommodityNumber(idx, num);
}

double CommodityShelf::getPrice(unsigned long idx) {
    return getCommodity(idx).getPrice();
}

std::string CommodityShelf::getName(unsigned long idx) {
    return getCommodity(idx).getName();
}

std::string CommodityShelf::toString() {
    std::string content;
    for (int i = 0; i < MAXSIZE; i++) {
        if (shelves[i].isEmpty())
            continue;
        if (content.length() == 0)
            content += shelves[i].toString();
        else
            content += "\n" + shelves[i].toString();
    }
    return content;
}

int CommodityShelf::getNumber(unsigned long idx) {
    return getCommodity(idx).getNumber();
}

void CommodityShelf::setPrice(unsigned long idx, double p) {
    shelves[hash(idx)].setPrice(idx, p);
}

void CommodityShelf::setNumber(unsigned long idx, int num) {
    shelves[hash(idx)].setNumber(idx, num);
}

std::string CommodityShelf::getDescription(unsigned long idx) {
    return getCommodity(idx).getDescription();
}

void CommodityShelf::setDescription(unsigned long idx, std::string d) {
    shelves[hash(idx)].setDescription(idx, d);
}

LinkedList CommodityShelf::getAllCommodities() {
    LinkedList list = LinkedList();
    for (int i = 0; i < MAXSIZE; i++) {
        Node *cur = shelves[i].getFront();
        while (cur != nullptr) {
            list.addCommodity(cur->getCommodity());
            cur = cur->getNext();
        }
    }
    return list;
}

void CommodityShelf::clear() {
    for (int i = 0; i < MAXSIZE; i++) {
        shelves[i].clear();
    }
}

void CommodityShelf::saveCommodities() {
    FILE *fw = fopen("../data/commodities.txt", "w");
    LinkedList list = getAllCommodities();
    for (Commodity commodity: list.getAllCommodities()) {
        fprintf(fw, "%s\n", commodity.toString().c_str());
    }
    fclose(fw);
}

std::vector<Commodity> CommodityShelf::readCommodities() {
    FILE *fr = fopen("../data/commodities.txt", "r");
    char s[1000];
    Helper helper;
    std::vector<Commodity> ans;
    while (fgets(s, 1000, fr) != NULL) {
        std::string line = helper.charArrayToString(s);
        line = helper.substring(line, 0, line.length() - 1);
        std::vector<std::string> splits = helper.split(line, ",");
        std::string pic_path = splits[0];
        std::string name = splits[1];
        double price = atof(splits[2].c_str());
        Commodity commodity = Commodity(splits[1], atof(splits[2].c_str()), atoi(splits[3].c_str()), splits[5]);
        commodity.setPicPath(pic_path);
        commodity.setId(atoll(splits[4].c_str()));
        ans.push_back(commodity);
    }
    fclose(fr);
    return ans;
}

void CommodityShelf::loadCommodities() {
    std::vector<Commodity> commodities = readCommodities();
    clear();
    for (Commodity commodity: commodities) {
        addCommodity(commodity);
    }
}