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
    Commodity();

    Commodity(std::string nm, double p, int nb, std::string d);

    std::string getPicPath();

    void setId(unsigned long i);

    void setPicPath(std::string pic_path);

    std::string getName();

    double getPrice();

    int getNumber();

    std::string getDescription();

    unsigned long getId();

    void setPrice(double p);

    void setNumber(int nb);

    void setDescription(std::string d);

    std::string toString();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITY_H
