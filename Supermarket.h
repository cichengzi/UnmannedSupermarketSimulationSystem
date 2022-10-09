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
    CommodityShelf commodityShelf; // 商品货架
    std::vector<User> users; // 用户列表
    ShoppingCart cart = ShoppingCart(User()); // 购物车
    User currentUser; // 当前用户

    int chineseCharToNumber(char a, char b, char c); // 中文字符转int类型

    std::string numberToChineseChar(int num); // int转中文字符

    std::set<int> chineseCharIntersection(std::string a, std::string b); // 求两个中文字符串的交集

    std::set<int> chineseCharUnion(std::string a, std::string b); // 求两个中文字符串的并集

    static bool cmp(std::pair<Commodity, double> a, std::pair<Commodity, double> b); // 定义商品排序规则

public:
    Supermarket(); // 无参构造函数

    explicit Supermarket(CommodityShelf cs); // 带参构造函数

    Commodity getCommodity(unsigned long idx); // 获取编号为idx的商品

    Commodity getCommodityByIndex(int index); // 通过索引获取商品

    Commodity getCartCommodity(unsigned long idx); // 获取编号为idx的购物车中商品

    void addCommodity(Commodity c); // 添加商品

    bool addCartCommodity(Commodity c); // 往购物车添加商品

    void removeCommodityById(unsigned long idx); // 移除编号为idx的商品

    void removeCartCommodityById(unsigned long idx); // 移除购物车中编号为idx的商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改编号为idx的商品的数量

    bool modifyCartCommodityNumber(unsigned long idx, int num); // 修改购物车中编号为idx的商品的数量

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    double getCartPrice(unsigned long idx); // 获取购物车中编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品名称

    std::string getCartName(unsigned long idx); // 获取购物车中编号为idx的商品的名称

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    int getCartNumber(unsigned long idx); // 获取购物车中编号为idx的商品的数量

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    std::string getCartDescription(unsigned long idx); // 获取购物车中编号为idx的商品的描述

    std::string toString(); // 获取类的string描述

    void setPrice(unsigned long idx, double p); // 设置编号为idx的商品的价格为p

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setCartNumber(unsigned long idx, int num); // 设置购物车中编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    LinkedList searchCommodity(std::string query, double threshold); // 搜索商品名称与query相似度不低于threshold的商品

    std::vector<User> getUsers(); // 获取users.txt中所有user

    void saveUsers(); // 保存所有user到users.txt中

    void addUser(User user); // 添加新的user

    void clearUsers(); // 清空users

    void clearCommodities(); // 清空所有商品

    std::vector<User> readUsers(); // 读取users.txt中所有用户

    double calculateSimilarity(std::string a, std::string b); // 计算字符串a和b的相似度

    std::vector<Commodity> readCommodities(); // 读取commodities.txt中所有的商品

    void saveCommodities(); // 保存商品到commodities.txt中

    void saveAll(); // 保存所有信息

    void clearAll(); // 清空所有信息

    User getUser(unsigned int idx); // 获取编号为idx的用户

    void loadAll(); // 导入所有信息

    ShoppingCart getCart(); // 获取购物车

    CommodityShelf getCommodityShelf(); // 获取货物架

    // 以下为超市的功能函数

    void login(); // 登录

    void logout(); // 登出

    bool checkMask(); // 检测是否佩戴口罩
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SUPERMARKET_H
