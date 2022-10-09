//
// Created by cichengzi on 2022/9/18.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SIMULATOR_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SIMULATOR_H

#include <QMainWindow>
#include<QListWidget>
#include <QPushButton>
#include<QTextEdit>
#include"User.h"
#include"ShoppingCart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Simulator; }
QT_END_NAMESPACE

class Simulator : public QMainWindow {
Q_OBJECT

public:
    explicit Simulator(QWidget *parent = nullptr); // 默认构造函数

    ~Simulator() override; // 析构函数

private slots:

    void productPurchase(); // 商品购买的界面

    void authentication(); // 身份验证的界面

    void maskDetection(); // 口罩检测的界面

    void deal(); // 商品结算的界面

    ShoppingCart searchShoppingCart(User us); // 搜索用户为us的购物车

    void updateUser(); // 更新users.txt

    void updateShoppingCart(); // 更新carts.txt

    void updateRecord(); // 更新records.txt

    void updateCommodity(); // 更新commodities.txt

    void purchaseRecord(); // 购买记录的界面

    void closeRecord(); // 关闭购买记录界面

    void margoManagement(); // 进出货管理界面

    void closeMargoManagement(); // 关闭进出货管理界面

    void addMargo(); // 添加货物

    void removeMargo(); // 移除货物

    void helpMargo(); // 帮助界面

    void addUser(); // 添加用户界面

    void faceCrawl(); // 人脸采集

public slots:
    void setCurrentUser(User us); // 设置currentUser

    void setShoppingCart(ShoppingCart cart); // 设置shoppingCart

    void setMask(bool m); // 设置口罩检测是否通过


private:
    Ui::Simulator *ui;
    User currentUser; // 当前用户
    ShoppingCart shoppingCart; // 当前用户对应的购物车
    bool mask; // 是否佩戴口罩
    QWidget* recordWidget; // 购买记录控件
    QListWidget* recordListWidget; // 购买记录列表控件
    QPushButton* recordButton; // 返回控件
    QWidget* manageWidget; // 进出货管理控件
    QWidget* addUserWidget; // 添加用户界面
    QLineEdit* picPathPrompt; // 商品图片路径输入栏
    QLineEdit* namePrompt; // 商品名称输入栏
    QLineEdit* pricePrompt; // 商品价格输入栏
    QLineEdit* numberPrompt; // 商品数量输入栏
    QLineEdit* descriptionPrompt; // 商品描述输入栏
    QPushButton* manageAddButton; // 商品添加按钮
    QPushButton* manageCloseButton; // 界面关闭按钮
    QPushButton* manageSubButton; // 商品移除按钮
    QPushButton* manageHelpButton; // 帮助按钮
    QPushButton* faceCrawlButton; // 人脸采集按钮
    QLineEdit* faceNamePrompt; // 人脸姓名输入栏
    bool DEBUG = true; // 如果是debug模式的话，不用口罩检测和人脸识别
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SIMULATOR_H
