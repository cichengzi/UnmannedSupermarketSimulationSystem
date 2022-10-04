#include"User.h"
#include<time.h>

User::User() {
    name = "无名";
    userType = GeneralUser;
    balance = 0;
    idx = 0;
}

User::User(std::string nm) {
    name = nm;
    userType = Administrator;
    balance = 0;
    idx = 
    idx = ++userCount;
}

User::User(std::string nm, UserType ut) {
    name = nm;
    userType = ut;
    balance = 0;
    idx = ++userCount;
}

User::User(std::string nm, UserType ut, double b) {
    name = nm;
    userType = ut;
    balance = b;
    idx = ++userCount;
}

std::string User::getName() {
    return name;
}

UserType User::getUserType() {
    return userType;
}

void User::setBalance(double b) {
    balance = b;
}

double User::getBalance() {
    return balance;
}

std::string User::toString() {
    return name + "," + std::to_string(userType) + "," + std::to_string(balance);
}

unsigned int User::getId() {
    return idx;
}