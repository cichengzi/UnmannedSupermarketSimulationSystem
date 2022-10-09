#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITYSHELF_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITYSHELF_H

#include"LinkedList.h"
#include"Helper.h"

const int MAXSIZE = 1031;

class CommodityShelf {
private:
    LinkedList* shelves; // 商品哈希表

    static unsigned int hash(unsigned long idx); // 获取商品编号为idx的商品在哈希表中的位置

public:
    CommodityShelf(); // 默认构造函数

    void addCommodity(Commodity c); // 添加商品

    void removeCommodityById(unsigned long idx); // 移除编号为idx的商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改编号为idx的商品的数量

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品的名称

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    Commodity getCommodity(unsigned long idx); // 获取编号为idx的商品

    std::string toString(); // 获取类的string描述

    void setPrice(unsigned long idx, double p); // 设置编号为idx的商品的价格为p

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    LinkedList getAllCommodities(); // 获取哈希表中所有的商品

    std::vector<Commodity> readCommodities(); // 读取commodities.txt中的所有商品

    void loadCommodities(); // 加载commodities.txt中的所有商品到此类对象中

    void saveCommodities(); // 将此类中所有商品信息保存到commodities.txt中

    void clear(); // 清空此类中所有商品
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITYSHELF_H
