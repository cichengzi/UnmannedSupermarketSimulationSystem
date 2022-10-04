//
// Created by cichengzi on 2022/8/18.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_TEST_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_TEST_H

#include"Supermarket.h"

class Tester {
public:
    bool assertTrueString(std::string a, std::string b);

    bool assertTrueUserType(UserType a, UserType b);

    bool assertTrueDouble(double a, double b);

    bool assertTrueInt(int a, int b);

    bool testReadUsers();

    bool testAddUser();

    bool testClearAllUsers();

    bool testGetUser();

    bool testSaveUsers();

    bool runAllTest();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_TEST_H
