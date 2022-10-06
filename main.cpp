#include"simulator.h"
#include<QApplication>
#include<QWidget>
#include"CommodityShelf.h"
#include"Commodity.h"
#include"ShoppingCart.h"
#include"User.h"
#include"Helper.h"
#include<vector>
#include<iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Simulator simulator;
    simulator.show();
    return a.exec();

    Helper helper;
    //std::cout << helper.faceRecognize("orl_faces/s21/10.jpg").getName() << std::endl;
    //std::cout << (helper.checkMask("mask/val/without_mask/2.jpg") ? "mask" : "without mask") << std::endl;
    //std::cout << (helper.maskDetection() ? "mask": "without mask") << std::endl;
    //std::cout << helper.faceRecognize().getName() << std::endl;
    return 0;
}