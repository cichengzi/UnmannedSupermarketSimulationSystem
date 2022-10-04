#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SUPERMARKET_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SUPERMARKET_H

#include"CommodityShelf.h"
#include"User.h"
#include"Helper.h"
#include"ShoppingCart.h"
#include<vector>
#include<set>

class Supermarket {
private:
    CommodityShelf commodityShelf;
    std::vector<User> users;
    ShoppingCart cart = ShoppingCart(User());
    User currentUser;

    int chineseCharToNumber(char a, char b, char c);

    std::string numberToChineseChar(int num);

    std::set<int> chineseCharIntersection(std::string a, std::string b);

    std::set<int> chineseCharUnion(std::string a, std::string b);

    static bool cmp(std::pair<Commodity, double> a, std::pair<Commodity, double> b);

public:
    Supermarket();

    explicit Supermarket(CommodityShelf cs);

    Commodity getCommodity(unsigned long idx);

    Commodity getCommodityByIndex(int index);

    Commodity getCartCommodity(unsigned long idx);

    void addCommodity(Commodity c);

    bool addCartCommodity(Commodity c);

    void removeCommodityById(unsigned long idx);

    void removeCartCommodityById(unsigned long idx);

    void modifyCommodityNumber(unsigned long idx, int num);

    bool modifyCartCommodityNumber(unsigned long idx, int num);

    double getPrice(unsigned long idx);

    double getCartPrice(unsigned long idx);

    std::string getName(unsigned long idx);

    std::string getCartName(unsigned long idx);

    int getNumber(unsigned long idx);

    int getCartNumber(unsigned long idx);

    std::string getDescription(unsigned long idx);

    std::string getCartDescription(unsigned long idx);

    std::string toString();

    void setPrice(unsigned long idx, double p);

    void setNumber(unsigned long idx, int num);

    void setCartNumber(unsigned long idx, int num);

    void setDescription(unsigned long idx, std::string d);

    LinkedList searchCommodity(std::string query, double threshold);

    std::vector<User> getUsers();

    void saveUsers();

    void addUser(User user);

    void clearUsers();

    void clearCommodities();

    std::vector<User> readUsers();

    double calculateSimilarity(std::string a, std::string b);

    std::vector<Commodity> readCommodities();

    void saveCommodities();

    void saveAll();

    void clearAll();

    User getUser(unsigned int idx);

    void loadAll();

    ShoppingCart getCart();

    CommodityShelf getCommodityShelf();

    // 以下为超市的功能函数

    void login();

    void logout();

    bool checkMask();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SUPERMARKET_H
