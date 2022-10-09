#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SHOPPINGCART_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SHOPPINGCART_H

#include"LinkedList.h"
#include"User.h"

class ShoppingCart {
private:
    LinkedList* carts; // 购物车哈希表
    User user; // 当前购物车对应的用户
    unsigned int cartSize; // 购物车中商品种类的数量
    static const int MAXSIZE = 1031; // 购物车哈希表的最大行数
    static unsigned int hash(unsigned long idx); // 计算编号为idx的商品在哈希表中的位置
public:
    explicit ShoppingCart(User us); // 带参构造函数

    ShoppingCart(); // 无参构造函数

    User getUser(); // 获取购物车对应用户

    void setUser(User us); // 设置购物车的用户

    void addCommodity(Commodity c); // 往购物车中添加商品

    void removeCommodityById(unsigned long idx); // 从购物车中移除掉编号为idx的商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改购物车中编号为idx的商品的数量

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品的名称

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    Commodity getCommodity(unsigned long idx); // 获取编号为idx的商品

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    LinkedList getAllCommodities(); // 获取购物车中所有商品

    double getTotalPrice(); // 获取当前购物车中所有商品的总价

    void clear(); // 清空购物车

    std::string toString(); // 获取购物车的string描述

    void loadShoppingCart(); // 从carts.txt中导入当前user对应的购物车信息
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SHOPPINGCART_H
