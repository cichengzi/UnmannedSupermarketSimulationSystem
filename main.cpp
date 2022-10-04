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
    /*
    QApplication a(argc, argv);
    Simulator simulator;
    simulator.show();
    return a.exec();
     */
    //system("conda activate DL");

    system("python ../MaskDetection/mask_detection.py");
    return 0;
}