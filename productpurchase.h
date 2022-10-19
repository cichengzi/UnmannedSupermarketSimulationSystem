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
    explicit ProductPurchase(QWidget *parent = nullptr); // 默认构造函数

    ~ProductPurchase() override; // 析构函数

private slots:

    void returnBack(); // 返回主界面

    void currentItem(); // 显示当前选中栏的元素

    void saveShoppingCart(); // 保存购物车信息到carts.txt

    void addCommodity(); // 添加商品到购物车

    void removeCommodity(); // 从购物车中移除商品

    void showShoppingCart(); // 展示购物车信息

    void clearShoppingCart(); // 清空购物车

    void search(); // 搜索界面

    void renewCommodityList(); // 更新陈列的商品

    void closeSearch(); // 关闭搜索界面

public slots:
    void setCurrentUser(User us); // 设置当前用户为us

    void setShoppingCart(ShoppingCart cart); // 设置当前购物车为cart

    void loadShoppingCart(); // 从carts.txt中找出用户us对应的购物车

    void setCommodities(std::vector<Commodity> commodities); // 设置商品列表

private:
    Ui::ProductPurchase *ui; // 当前界面的ui
    User currentUser; // 当前用户
    ShoppingCart shoppingCart; // 当前用户对应的购物车
    CommodityShelf commodityShelf; // 商品货架类
    bool showCart; // 是否显示购物车🛒
    QWidget* shoppingCartWidget; // 购物车界面的ui
    QListWidget* shoppingCartListWidget; // 购物车商品列表的ui

    QWidget* searchWidget; // 搜索界面ui
    QLineEdit* keyWordPrompt; // 关键词输入栏
    std::string keyWord; // 搜索关键词
    std::vector<Commodity> commodities;
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_PRODUCTPURCHASE_H
