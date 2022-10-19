//
// Created by cichengzi on 2022/8/18.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_TEST_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_TEST_H

#include"Supermarket.h"

class Tester {
public:
    bool assertTrueString(std::string a, std::string b); // 判断两个字符串是否相等

    bool assertTrueUserType(UserType a, UserType b); // 判断两个用户类型是否相等

    bool assertTrueDouble(double a, double b); // 判断两个浮点数是否相等

    bool assertTrueInt(int a, int b); // 判断两个整型是否相等
};

class AutoTest: Tester {
    bool testReadUsers(); // 测试读取用户信息

    bool testAddUser(); // 测试添加用户

    bool testClearAllUsers(); // 测试清空所有用户

    bool testGetUser(); // 测试获取用户

    bool testSaveUsers(); // 测试保存用户

    bool runAllTest(); // 运行所有测试
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_TEST_H
