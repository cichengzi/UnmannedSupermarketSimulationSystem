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
    std::string substring(std::string s, int begin);

    std::string substring(std::string s, int begin, int end);

    std::vector<std::string> split(std::string s, std::string p);

    std::string charArrayToString(char s[]);

    bool checkMask();

    User faceRecognize();

    std::vector<User> readUsers();

    std::vector<ShoppingCart> readShoppingCarts();

    std::vector<ShoppingCart> readRecords();

    std::vector<Commodity> readCommodities();

    void saveCommodities(std::vector<Commodity> commodities);

    void saveRecords(std::vector<ShoppingCart> records);

    void saveUsers(std::vector<User> users);

    void saveShoppingCarts(std::vector<ShoppingCart> carts);

    std::string currentTimeStamp();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_HELPER_H
