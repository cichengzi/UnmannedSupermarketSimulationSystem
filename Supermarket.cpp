#include"Supermarket.h"
#include<set>
#include<vector>
#include<algorithm>
#include<iostream>

Supermarket::Supermarket() {
    commodityShelf = CommodityShelf();
}

Supermarket::Supermarket(CommodityShelf cs) {
    commodityShelf = cs;
}

Commodity Supermarket::getCommodity(unsigned long idx) {
    return commodityShelf.getCommodity(idx);
}

double Supermarket::calculateSimilarity(std::string a, std::string b) {
    std::set<int> in = chineseCharIntersection(a, b);
    std::set<int> uni = chineseCharUnion(a, b);
    return 1.0 * in.size() / uni.size();
}

bool Supermarket::cmp(std::pair<Commodity, double> a, std::pair<Commodity, double> b) {
    return a.second > b.second;
}

LinkedList Supermarket::searchCommodity(std::string query, double threshold) {
    LinkedList list = commodityShelf.getAllCommodities();
    LinkedList ans = LinkedList();
    Node *cur = list.getFront();
    std::vector<std::pair<Commodity, double> > temp;
    while (cur != nullptr) {
        double sim = calculateSimilarity(query, cur->getCommodity().getName());
        if (sim >= threshold) {
            temp.emplace_back(cur->getCommodity(), sim);
        }
        cur = cur->getNext();
    }
    std::sort(temp.begin(), temp.end(), cmp);
    for (std::pair<Commodity, double> p: temp) {
        ans.addCommodity(p.first);
    }
    return ans;
}

void Supermarket::addCommodity(Commodity c) {
    commodityShelf.addCommodity(c);
}

void Supermarket::removeCommodityById(unsigned long idx) {
    commodityShelf.removeCommodityById(idx);
}

void Supermarket::modifyCommodityNumber(unsigned long idx, int num) {
    commodityShelf.modifyCommodityNumber(idx, num);
}

double Supermarket::getPrice(unsigned long idx) {
    return commodityShelf.getPrice(idx);
}

std::string Supermarket::getName(unsigned long idx) {
    return commodityShelf.getName(idx);
}

int Supermarket::getNumber(unsigned long idx) {
    return commodityShelf.getNumber(idx);
}

std::string Supermarket::getDescription(unsigned long idx) {
    return commodityShelf.getDescription(idx);
}

void Supermarket::setPrice(unsigned long idx, double p) {
    commodityShelf.setPrice(idx, p);
}

void Supermarket::setNumber(unsigned long idx, int num) {
    commodityShelf.setNumber(idx, num);
}

void Supermarket::setDescription(unsigned long idx, std::string d) {
    commodityShelf.setDescription(idx, d);
}

std::vector<User> Supermarket::getUsers() {
    return users;
}

void Supermarket::saveUsers() {
    FILE *fw = fopen("../data/users.txt", "w");
    for (User user: users) {
        fprintf(fw, "%s\n", user.toString().c_str());
    }
    fclose(fw);
}

std::vector<User> Supermarket::readUsers() {
    FILE *fr = fopen("../data/users.txt", "r");
    char s[1000];
    std::vector<User> allUsers;
    while (fgets(s, 1000, fr) != NULL) {
        std::string ns;
        std::string us;
        std::string bs;
        int i = 0;
        for (; s[i] != ','; i++) {
            ns += s[i];
        }
        i++;
        for (; s[i] != ','; i++) {
            us += s[i];
        }
        i++;
        for (; s[i] != '\0'; i++) {
            bs += s[i];
        }
        User user;
        if (atoi(us.c_str()) == 0) {
            user = User(ns, Administrator, atof(bs.c_str()));
        } else {
            user = User(ns, GeneralUser, atof(bs.c_str()));
        }
        allUsers.push_back(user);
    }
    fclose(fr);
    return allUsers;
}

void Supermarket::addUser(User user) {
    users.push_back(user);
}

void Supermarket::clearUsers() {
    users.clear();
}

void Supermarket::clearCommodities() {
    commodityShelf.clear();
}

std::string Supermarket::toString() {
    std::string s = "CommodityShelf:\n" + commodityShelf.toString() + "\nUsers:";
    for (User user: users) {
        s += "\n" + user.toString();
    }
    return s;
}

int Supermarket::chineseCharToNumber(char a, char b, char c) {
    return a * 128 * 128 + b * 128 + c;
}

std::string Supermarket::numberToChineseChar(int num) {
    std::string s;
    int a = num / (128 * 128);
    num %= (128 * 128);
    int b = num / 128;
    int c = num % 128;
    s += (char) a;
    s += (char) b;
    s += (char) c;
    return s;
}

std::set<int> Supermarket::chineseCharIntersection(std::string a, std::string b) {
    std::set<int> sa, sb;
    int i;
    for (i = 0; i < a.length();) {
        if (a[i] < 0 && i + 2 < a.length()) {
            sa.insert(chineseCharToNumber(a[i], a[i + 1], a[i + 2]));
            i += 3;
        } else {
            sa.insert((int) a[i]);
            i += 1;
        }
    }
    for (i = 0; i < b.length();) {
        if (b[i] < 0 && i + 2 < b.length()) {
            sb.insert(chineseCharToNumber(b[i], b[i + 1], b[i + 2]));
            i += 3;
        } else {
            sb.insert((int) b[i]);
            i += 1;
        }
    }
    std::set<int> s;
    std::set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), std::inserter(s, s.begin()));
    return s;
}

std::set<int> Supermarket::chineseCharUnion(std::string a, std::string b) {
    std::set<int> sa, sb;
    int i;
    for (i = 0; i < a.length();) {
        if (a[i] < 0 && i + 2 < a.length()) {
            sa.insert(chineseCharToNumber(a[i], a[i + 1], a[i + 2]));
            i += 3;
        } else {
            sa.insert((int) a[i]);
            i += 1;
        }
    }
    for (i = 0; i < b.length();) {
        if (b[i] < 0 && i + 2 < b.length()) {
            sb.insert(chineseCharToNumber(b[i], b[i + 1], b[i + 2]));
            i += 3;
        } else {
            sb.insert((int) b[i]);
            i += 1;
        }
    }
    std::set<int> s;
    std::set_union(sa.begin(), sa.end(), sb.begin(), sb.end(), std::inserter(s, s.begin()));
    return s;
}

std::vector<Commodity> Supermarket::readCommodities() {
    return commodityShelf.readCommodities();
}

void Supermarket::saveCommodities() {
    commodityShelf.saveCommodities();
}

void Supermarket::saveAll() {
    saveCommodities();
    saveUsers();
}

void Supermarket::clearAll() {
    clearCommodities();
    clearUsers();
}

User Supermarket::getUser(unsigned int idx) {
    for (User us: users) {
        if (us.getId() == idx)
            return us;
    }
    return User();
}

void Supermarket::loadAll() {
    clearAll();
    for (Commodity commodity: readCommodities()) {
        commodityShelf.addCommodity(commodity);
    }
    for (User user: readUsers()) {
        users.push_back(user);
    }
}

void Supermarket::logout() {
    currentUser = User();
}

void Supermarket::login() {
    Helper helper;
    //currentUser = helper.faceRecognize();
}

bool Supermarket::checkMask() {
    Helper helper;
    //return helper.checkMask();
    return true;
}

ShoppingCart Supermarket::getCart() {
    return cart;
}

Commodity Supermarket::getCartCommodity(unsigned long idx) {
    return cart.getCommodity(idx);
}

bool Supermarket::addCartCommodity(Commodity c) {
    if (getCommodity(c.getId()).getNumber() < c.getNumber())
        return false;
    cart.addCommodity(c);
    return true;
}

void Supermarket::removeCartCommodityById(unsigned long idx) {
    cart.removeCommodityById(idx);
}

bool Supermarket::modifyCartCommodityNumber(unsigned long idx, int num) {
    if (getCommodity(idx).getNumber() < num || num < 0)
        return false;
    if (num == 0)
        cart.removeCommodityById(idx);
    else
        cart.modifyCommodityNumber(idx, num);
    return true;
}

double Supermarket::getCartPrice(unsigned long idx) {
    return cart.getPrice(idx);
}

std::string Supermarket::getCartName(unsigned long idx) {
    return cart.getName(idx);
}

int Supermarket::getCartNumber(unsigned long idx) {
    return cart.getNumber(idx);
}

std::string Supermarket::getCartDescription(unsigned long idx) {
    return cart.getDescription(idx);
}

void Supermarket::setCartNumber(unsigned long idx, int num) {
    cart.setNumber(idx, num);
}

Commodity Supermarket::getCommodityByIndex(int index) {
    return commodityShelf.getAllCommodities().getCommodityByIndex(index);
}

CommodityShelf Supermarket::getCommodityShelf() {
    return commodityShelf;
}