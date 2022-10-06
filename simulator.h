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
    explicit Simulator(QWidget *parent = nullptr);

    ~Simulator() override;

private slots:

    void productPurchase(); // 商品购买的界面

    void authentication(); // 身份验证的界面

    void maskDetection(); // 口罩检测的界面

    void deal(); // 商品结算的界面

    ShoppingCart searchShoppingCart(User us);

    void updateUser();

    void updateShoppingCart();

    void updateRecord();

    void updateCommodity();

    void purchaseRecord(); // 购买记录的界面

    void closeRecord();

    void margoManagement();

    void closeMargoManagement();

    void addMargo();

    void removeMargo();

    void helpMargo();

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
    QLineEdit* picPathPrompt;
    QLineEdit* namePrompt;
    QLineEdit* pricePrompt;
    QLineEdit* numberPrompt;
    QLineEdit* descriptionPrompt;
    QPushButton* manageAddButton;
    QPushButton* manageCloseButton;
    QPushButton* manageSubButton;
    QPushButton* manageHelpButton;
    bool DEBUG = true; // 如果是debug模式的话，不用口罩检测和人脸识别
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SIMULATOR_H
