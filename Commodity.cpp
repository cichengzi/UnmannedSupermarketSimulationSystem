#include"Commodity.h"

Commodity::Commodity() {
    pic_path = "/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/img.png";
    name = "不存在";
    price = 0;
    number = 0;
    idx = 0;
    description = "无";
}

Commodity::Commodity(std::string nm, double p, int nb, std::string d) {
    pic_path = "/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/img.png";
    name = nm;
    price = p;
    number = nb;
    description = d;
}

std::string Commodity::getName() {
    return name;
}

double Commodity::getPrice() {
    return price;
}

int Commodity::getNumber() {
    return number;
}

void Commodity::setNumber(int nb) {
    number = nb;
}

void Commodity::setPrice(double p) {
    price = p;
}

unsigned long Commodity::getId() {
    return idx;
}

std::string Commodity::toString() {
    std::string s;
    s += pic_path + ",";
    s += name + ",";
    s += std::to_string(price) + ",";
    s += std::to_string(number) + ",";
    s += std::to_string(idx) + ",";
    s += description;
    return s;
}

std::string Commodity::getDescription() {
    return description;
}

void Commodity::setDescription(std::string d) {
    description = d;
}

std::string Commodity::getPicPath() {
    return pic_path;
}

void Commodity::setPicPath(std::string p) {
    pic_path = p;
}

void Commodity::setId(unsigned long i) {
    idx = i;
}