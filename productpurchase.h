//
// Created by cichengzi on 2022/9/18.
//

#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_PRODUCTPURCHASE_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_PRODUCTPURCHASE_H

#include <QWidget>
#include<QListWidget>
#include"User.h"
#include"ShoppingCart.h"
#include"CommodityShelf.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProductPurchase; }
QT_END_NAMESPACE

class ProductPurchase : public QWidget {
Q_OBJECT

public:
    explicit ProductPurchase(QWidget *parent = nullptr);

    ~ProductPurchase() override;

private slots:

    void returnBack();

    void currentItem();

    void saveShoppingCart();

    void addCommodity();

    void removeCommodity();

    void showShoppingCart();

public slots:
    void setCurrentUser(User us);

    void setShoppingCart(ShoppingCart cart);

    void loadShoppingCart();

private:
    Ui::ProductPurchase *ui;
    User currentUser;
    ShoppingCart shoppingCart;
    CommodityShelf commodityShelf;
    bool showCart; // 是否显示购物车🛒
    QWidget* shoppingCartWidget;
    QListWidget* shoppingCartListWidget;
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_PRODUCTPURCHASE_H
