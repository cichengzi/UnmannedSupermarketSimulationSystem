// You may need to build the project (run Qt uic code generator) to get "ui_ProductPurchase.h" resolved

#include "productpurchase.h"
#include "ui_ProductPurchase.h"
#include"simulator.h"
#include"ui_Simulator.h"
#include<QHBoxLayout>
#include <iostream>


ProductPurchase::ProductPurchase(QWidget *parent) :
        QWidget(parent), ui(new Ui::ProductPurchase) {
    ui->setupUi(this);
    commodityShelf.loadCommodities();
    connect(ui->Back, &QPushButton::clicked, this, &ProductPurchase::returnBack);
    connect(ui->ShoppingCart, &QPushButton::clicked, this, &ProductPurchase::showShoppingCart);
    connect(ui->AddCommodity, &QPushButton::clicked, this, &ProductPurchase::addCommodity);
    connect(ui->removeCommodity, &QPushButton::clicked, this, &ProductPurchase::removeCommodity);
    connect(ui->clearShoppingCart, &QPushButton::clicked, this, &ProductPurchase::clearShoppingCart);
//    connect(ui->currentItem, &QPushButton::clicked, this, &ProductPurchase::currentItem);

    //std::cout << "Now in Product Purchase, current User: " << currentUser.getName() << std::endl;

    //std::cout << shoppingCart.toString() << std::endl;

    ui->listWidget->setViewMode(QListView::ListMode);
    ui->listWidget->setFlow(QListView::TopToBottom);

    std::vector<Commodity> commodities = commodityShelf.readCommodities();
    for (int i = 0; i < commodities.size(); i++) {
        QWidget *widget = new QWidget(this);

        QLabel *label = new QLabel(widget);
        QPixmap *image = new QPixmap(
                commodities[i].getPicPath().c_str());

        label->setPixmap(*image);
        label->resize(200, 200);
        QHBoxLayout *layout = new QHBoxLayout();

        layout->addWidget(label);
        layout->addWidget(new QLabel(QString::fromStdString(commodities[i].getName())));
        std::string price = std::to_string(commodities[i].getPrice());
        layout->addWidget(new QLabel(QString::fromStdString(price.substr(0, price.size() - 5))));

        widget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(350, 200));
        item->setText(QString::fromStdString(std::to_string(commodities[i].getId())));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);
    }

    showCart = false;
    shoppingCartWidget = NULL;
    this->setWindowTitle("商品选购");
}

ProductPurchase::~ProductPurchase() {
    delete ui;
}

void ProductPurchase::returnBack() {
    if (shoppingCartWidget != NULL)
        shoppingCartWidget->close();
    Simulator *simulator = new Simulator();
    simulator->setCurrentUser(currentUser);
    simulator->setShoppingCart(shoppingCart);
    simulator->setMask(true);
    simulator->show();
    this->close();
}

void ProductPurchase::currentItem() {
    QListWidgetItem *cur = ui->listWidget->currentItem();
    if (cur != NULL) {
        std::cout << "Not Null" << std::endl;
        std::cout << cur->text().toStdString() << std::endl;
    }
    else {
        std::cout << "Null" << std::endl;
    }
}

void ProductPurchase::saveShoppingCart() {
    //std::cout << "Now in saveShoppingCart, current User: " << currentUser.getName() << std::endl;
    //std::cout << "current ShoppingCart User: " << shoppingCart.getUser().getName() << std::endl;
    if (currentUser.getName() != "无名") {
        Helper helper;
        std::vector<ShoppingCart> carts = helper.readShoppingCarts();
        bool add = true;
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].getUser().getName() == currentUser.getName()) {
                add = false;
                carts[i] = shoppingCart;
                break;
            }
        }
        if (add)
            carts.push_back(shoppingCart);

        FILE *fw = fopen("../data/carts.txt", "w");
        for (ShoppingCart cart: carts) {
            fprintf(fw, "%s\n", cart.toString().c_str());
            //std::cout << cart.toString() << std::endl;
        }
        fclose(fw);
    }
}

void ProductPurchase::setCurrentUser(User us) {
    currentUser = us;
}

void ProductPurchase::setShoppingCart(ShoppingCart cart) {
    shoppingCart = cart;
}

void ProductPurchase::addCommodity() {
    if (ui->listWidget->currentItem() != NULL) {
        QString item_id = ui->listWidget->currentItem()->text();
        Commodity commodity = commodityShelf.getCommodity(atoll(item_id.toStdString().c_str()));
        int num = shoppingCart.getCommodity(commodity.getId()).getNumber() + 1;
        if (num > commodity.getNumber())
            num = commodity.getNumber();
        commodity.setNumber(num);
        shoppingCart.removeCommodityById(commodity.getId());
        shoppingCart.addCommodity(commodity);

        //std::cout << "Add one " << commodity.getName() << ", current number: " << shoppingCart.getCommodity(commodity.getId()).getNumber() << std::endl;
        saveShoppingCart();

        if (showCart) {
            shoppingCartListWidget->clear();

            for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
                QWidget *widget = new QWidget(shoppingCartWidget);
                QHBoxLayout *layout = new QHBoxLayout();

                layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
                layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

                widget->setLayout(layout);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(240, 50));
                shoppingCartListWidget->addItem(item);
                shoppingCartListWidget->setItemWidget(item, widget);
            }
        }
        else {
            showCart = true;
            shoppingCartWidget = new QWidget();
            shoppingCartWidget->setFixedSize(240, 720);
            shoppingCartListWidget = new QListWidget(shoppingCartWidget);
            shoppingCartListWidget->setFixedSize(240, 720);
            for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
                QWidget *widget = new QWidget(shoppingCartWidget);
                QHBoxLayout *layout = new QHBoxLayout();

                layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
                layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

                widget->setLayout(layout);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(240, 50));
                shoppingCartListWidget->addItem(item);
                shoppingCartListWidget->setItemWidget(item, widget);
            }

            shoppingCartWidget->move(1460, 200);
            shoppingCartWidget->setWindowTitle("购物车");
            shoppingCartWidget->show();
        }
    }
}

void ProductPurchase::removeCommodity() {
    if (ui->listWidget->currentItem() != NULL) {
        QString item_id = ui->listWidget->currentItem()->text();
        Commodity commodity = commodityShelf.getCommodity(atoll(item_id.toStdString().c_str()));
        int num = shoppingCart.getCommodity(commodity.getId()).getNumber() - 1;
        if (num < 0)
            num = 0;
        commodity.setNumber(num);
        shoppingCart.removeCommodityById(commodity.getId());
        if (num != 0)
            shoppingCart.addCommodity(commodity);

        //std::cout << "Remove one " << commodity.getName() << ", current number: " << shoppingCart.getCommodity(commodity.getId()).getNumber() << std::endl;
        saveShoppingCart();

        if (showCart) {
            shoppingCartListWidget->clear();

            for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
                QWidget *widget = new QWidget(shoppingCartWidget);
                QHBoxLayout *layout = new QHBoxLayout();

                layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
                layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

                widget->setLayout(layout);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(240, 50));
                shoppingCartListWidget->addItem(item);
                shoppingCartListWidget->setItemWidget(item, widget);
            }
        }
        else {
            showCart = true;
            shoppingCartWidget = new QWidget();
            shoppingCartWidget->setFixedSize(240, 720);
            shoppingCartListWidget = new QListWidget(shoppingCartWidget);
            shoppingCartListWidget->setFixedSize(240, 720);
            for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
                QWidget *widget = new QWidget(shoppingCartWidget);
                QHBoxLayout *layout = new QHBoxLayout();

                layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
                layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

                widget->setLayout(layout);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(240, 50));
                shoppingCartListWidget->addItem(item);
                shoppingCartListWidget->setItemWidget(item, widget);
            }

            shoppingCartWidget->move(1460, 200);
            shoppingCartWidget->setWindowTitle("购物车");
            shoppingCartWidget->show();
        }
    }
}

void ProductPurchase::loadShoppingCart() {
    Helper helper;
    std::vector<ShoppingCart> carts = helper.readShoppingCarts();
    //std::cout << "Now in loadShoppingCart, current User: " << currentUser.getName() << std::endl;
    for (ShoppingCart cart: carts) {
        if (cart.getUser().getName() == currentUser.getName()) {
            shoppingCart = cart;
            break;
        }
    }
}

void ProductPurchase::showShoppingCart() {
    if (!showCart) {
        showCart = true;
        shoppingCartWidget = new QWidget();
        shoppingCartWidget->setFixedSize(240, 720);
        shoppingCartListWidget = new QListWidget(shoppingCartWidget);
        shoppingCartListWidget->setFixedSize(240, 720);
        for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
            QWidget *widget = new QWidget(shoppingCartWidget);
            QHBoxLayout *layout = new QHBoxLayout();

            layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
            layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

            widget->setLayout(layout);

            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(240, 50));
            shoppingCartListWidget->addItem(item);
            shoppingCartListWidget->setItemWidget(item, widget);
        }

        shoppingCartWidget->move(1460, 200);
        shoppingCartWidget->setWindowTitle("购物车");
        shoppingCartWidget->show();


    } else {
        showCart = false;
        if (shoppingCartWidget != NULL)
            shoppingCartWidget->close();
        shoppingCartWidget = NULL;
        shoppingCartListWidget = NULL;
    }
}

void ProductPurchase::clearShoppingCart() {
    shoppingCart.clear();
    saveShoppingCart();

    shoppingCartListWidget->clear();

    for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
        QWidget *widget = new QWidget(shoppingCartWidget);
        QHBoxLayout *layout = new QHBoxLayout();

        layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
        layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

        widget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(240, 50));
        shoppingCartListWidget->addItem(item);
        shoppingCartListWidget->setItemWidget(item, widget);
    }
}