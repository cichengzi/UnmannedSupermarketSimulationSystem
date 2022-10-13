//
// Created by cichengzi on 2022/8/22.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_HELPER_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_HELPER_H

#include<string>
#include<vector>
#include"User.h"
#include"ShoppingCart.h"

class Helper {
public:
    std::string substring(std::string s, int begin); // 获取字符串s从begin索引开始的子串

    std::string substring(std::string s, int begin, int end); // 获取字符串s从begin索引开始到end索引间（包含end）的子串

    std::vector<std::string> split(std::string s, std::string p); // 获取用字符串p对字符串s进行分割的列表

    std::string charArrayToString(char s[]); // char array转std string

    bool checkMask(std::string pic_path); // 检测处于pic_path路径下的图片中的人是否有佩戴口罩

    User faceRecognize(std::string pic_path); // 检测处于pic_path路径下的图片中的人的身份

    bool maskDetection(); // 检测用户是否有佩戴口罩

    User faceRecognize(); // 对用户进行身份识别

    std::vector<User> readUsers(); // 读取users.txt中所有的用户信息

    std::vector<ShoppingCart> readShoppingCarts(); // 读取carts.txt中所有的购物车信息

    std::vector<ShoppingCart> readRecords(); // 读取records.txt中所有的购买记录信息

    std::vector<Commodity> readCommodities(); // 读取commodities.txt中所有的商品信息

    void saveCommodities(std::vector<Commodity> commodities); // 将commodities vector中的所有商品保存到commodities.txt中

    void saveRecords(std::vector<ShoppingCart> records); // 将records vector中所有的购物车保存到carts.txt中

    void saveUsers(std::vector<User> users); // 将users vector中所有的用户保存到users.txt中

    void saveShoppingCarts(std::vector<ShoppingCart> carts); // 将carts vector中所有的购物车保存到carts.txt中

    std::string currentTimeStamp(); // 以字符串形式获取当前的时间戳

    double getSimilarity(std::string a, std::string b); // 计算两个字符串的相似度

    std::string removePrefixBlank(std::string a);
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_HELPER_H
