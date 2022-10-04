//
// Created by cichengzi on 2022/8/18.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_USER_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_USER_H


#include <string>

static int userCount = 0;

enum UserType {
    Administrator = 0, GeneralUser = 1
};

class User {
private:
    std::string name; // 用户姓名
    UserType userType; // 用户类型
    double balance; // 余额
    unsigned int idx; // 用户编号

public:
    User();

    explicit User(std::string nm);

    User(std::string nm, UserType ut);

    User(std::string nm, UserType ut, double b);

    std::string getName();

    UserType getUserType();

    void setBalance(double b);

    double getBalance();

    std::string toString();

    unsigned int getId();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_USER_H
