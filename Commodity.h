#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITY_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITY_H

#include<string>

class Commodity {
private:
    std::string pic_path; // 商品图片地址
    std::string name; // 商品名称
    double price; // 商品价格
    int number; // 商品数量
    unsigned long idx; // 商品编号
    std::string description; // 商品描述

public:
    Commodity(); // 商品类的默认构造函数

    Commodity(std::string nm, double p, int nb, std::string d); // 商品类的另一个构造函数

    std::string getPicPath(); // 获取商品图片路径

    void setId(unsigned long i); // 设置商品的编号

    void setPicPath(std::string pic_path); // 设置商品图片路径

    std::string getName(); // 获取商品名称

    double getPrice(); // 获取商品价格

    int getNumber(); // 获取商品数量

    std::string getDescription(); // 获取商品描述

    unsigned long getId(); // 获取商品编号

    void setPrice(double p); // 设置商品价格

    void setNumber(int nb); // 设置商品数量

    void setDescription(std::string d); // 设置商品描述

    std::string toString(); // 商品信息转string
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITY_H
