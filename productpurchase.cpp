// You may need to build the project (run Qt uic code generator) to get "ui_ProductPurchase.h" resolved

#include "productpurchase.h"
#include "ui_ProductPurchase.h"
#include"simulator.h"
#include"ui_Simulator.h"
#include<QHBoxLayout>
#include <iostream>
#include<QPalette>
#include<QLineEdit>
#include<set>

ProductPurchase::ProductPurchase(QWidget *parent) :
        QWidget(parent), ui(new Ui::ProductPurchase) {
    ui->setupUi(this);
    commodityShelf.loadCommodities();
    connect(ui->Back, &QPushButton::clicked, this, &ProductPurchase::returnBack);
    connect(ui->ShoppingCart, &QPushButton::clicked, this, &ProductPurchase::showShoppingCart);
    connect(ui->AddCommodity, &QPushButton::clicked, this, &ProductPurchase::addCommodity);
    connect(ui->removeCommodity, &QPushButton::clicked, this, &ProductPurchase::removeCommodity);
    connect(ui->clearShoppingCart, &QPushButton::clicked, this, &ProductPurchase::clearShoppingCart);
    connect(ui->searchCommodity, &QPushButton::clicked, this, &ProductPurchase::search);

    QFont buttonFont;
    buttonFont.setFamily("STKaiti");
    buttonFont.setPointSize(20);

    ui->Back->setFlat(true);
    ui->Back->setFont(buttonFont);

    ui->ShoppingCart->setFlat(true);
    ui->ShoppingCart->setFont(buttonFont);

    ui->AddCommodity->setFlat(true);
    ui->AddCommodity->setFont(buttonFont);

    ui->removeCommodity->setFlat(true);
    ui->removeCommodity->setFont(buttonFont);

    ui->clearShoppingCart->setFlat(true);
    ui->clearShoppingCart->setFont(buttonFont);

    ui->searchCommodity->setFlat(true);
    ui->searchCommodity->setFont(buttonFont);

    ui->listWidget->setViewMode(QListView::ListMode);
    ui->listWidget->setFlow(QListView::TopToBottom);

    QFont nameFont;
    nameFont.setPointSize(20);
    nameFont.setFamily("STKaiti");
    QFont priceFont;
    priceFont.setPointSize(25);
    priceFont.setFamily("STKaiti");

    Helper helper;
    commodities = helper.readCommodities();
    std::sort(commodities.begin(), commodities.end());

    for (int i = 0; i < commodities.size(); i++) {
        QWidget *widget = new QWidget(this);

        QLabel *label = new QLabel(widget);
        QPixmap *image = new QPixmap(
                commodities[i].getPicPath().c_str());

        label->setPixmap(*image);
        label->setFixedSize(200, 200);
        label->move(0, 0);
        //label->resize(200, 200);
        QHBoxLayout *layout = new QHBoxLayout();

        layout->addWidget(label);
        QLabel* nameLabel = new QLabel(QString::fromStdString(commodities[i].getName()));
        nameLabel->setFont(nameFont);
        nameLabel->setFixedSize(660, 200);
        layout->addWidget(nameLabel);

        std::string price = std::to_string(commodities[i].getPrice());
        QLabel* priceLabel = new QLabel(QString::fromStdString(price.substr(0, price.size() - 5)));
        priceLabel->setFont(priceFont);
        priceLabel->setFixedSize(100, 200);
        //priceLabel->setPalette(pe);
        priceLabel->setStyleSheet("color: red");

        layout->addWidget(priceLabel);

        widget->setLayout(layout);
        widget->move(0, 0);

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(480, 200));
        item->setText(QString::fromStdString("  " + std::to_string(commodities[i].getId())));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);
    }

    showCart = false;
    shoppingCartWidget = NULL;
    searchWidget = NULL;
    this->setWindowTitle("商品选购");

    this->move(380, 200);
}

ProductPurchase::~ProductPurchase() {
    delete ui;
}

void ProductPurchase::returnBack() {
    if (shoppingCartWidget != NULL) {
        shoppingCartWidget->close();
        shoppingCartWidget = NULL;
    }

    if (searchWidget != NULL) {
        searchWidget->close();
        searchWidget = NULL;
    }

    //printf("here\n");
    Simulator *simulator = new Simulator();
    simulator->setCurrentUser(currentUser);
    simulator->setShoppingCart(shoppingCart);
    simulator->setMask(true);
    simulator->show();
    keyWord = "";
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

void ProductPurchase::setCommodities(std::vector<Commodity> commodities) {
    this->commodities = commodities;
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
        Helper helper;
        QString item_id = QString::fromStdString(helper.removePrefixBlank(ui->listWidget->currentItem()->text().toStdString()));
        Commodity commodity = commodityShelf.getCommodity(atoll(item_id.toStdString().c_str()));
        int num = shoppingCart.getCommodity(commodity.getId()).getNumber() + 1;
        if (num > commodity.getNumber())
            num = commodity.getNumber();
        commodity.setNumber(num);
        shoppingCart.removeCommodityById(commodity.getId());
        shoppingCart.addCommodity(commodity);

        //std::cout << "Add one " << commodity.getName() << ", current number: " << shoppingCart.getCommodity(commodity.getId()).getNumber() << std::endl;
        saveShoppingCart();

        if (shoppingCartWidget == NULL)
            showShoppingCart();
        else {
            showShoppingCart();
            showShoppingCart();
        }
    }
}

void ProductPurchase::removeCommodity() {
    if (ui->listWidget->currentItem() != NULL) {
        Helper helper;
        QString item_id = QString::fromStdString(helper.removePrefixBlank(ui->listWidget->currentItem()->text().toStdString()));
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

        if (shoppingCartWidget == NULL)
            showShoppingCart();
        else {
            showShoppingCart();
            showShoppingCart();
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
        shoppingCartWidget->setFixedSize(480, 720);
        shoppingCartListWidget = new QListWidget(shoppingCartWidget);
        shoppingCartListWidget->setFixedSize(480, 720);

        QFont nameFont;
        nameFont.setPointSize(15);
        nameFont.setFamily("STKaiti");

        QFont numFont;
        numFont.setPointSize(20);
        numFont.setFamily("STKaiti");
        for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
            QWidget *widget = new QWidget(shoppingCartWidget);
            QHBoxLayout *layout = new QHBoxLayout();

            QLabel* nameLabel = new QLabel(QString::fromStdString(c.getName()));
            nameLabel->setFont(nameFont);

            layout->addWidget(nameLabel);

            QLabel* numberLabel = new QLabel(QString::fromStdString(std::to_string(c.getNumber())));
            numberLabel->setFont(numFont);
            layout->addWidget(numberLabel);

            widget->setLayout(layout);

            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(480, 50));
            shoppingCartListWidget->addItem(item);
            shoppingCartListWidget->setItemWidget(item, widget);
        }

        shoppingCartWidget->move(1340, 200);
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

    if (shoppingCartWidget != NULL) {
        shoppingCartListWidget->clear();

        for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
            QWidget *widget = new QWidget(shoppingCartWidget);
            QHBoxLayout *layout = new QHBoxLayout();

            layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
            layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

            widget->setLayout(layout);

            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(480, 50));
            shoppingCartListWidget->addItem(item);
            shoppingCartListWidget->setItemWidget(item, widget);
        }
    }
}

void ProductPurchase::renewCommodityList() {
    std::string currentKeyWord = keyWordPrompt->text().toStdString();
    if (currentKeyWord == keyWord)
        return;
    Helper helper;
    double threshold = 0.05;
    QFont nameFont;
    nameFont.setPointSize(20);
    nameFont.setFamily("STKaiti");
    QFont priceFont;
    priceFont.setPointSize(25);
    priceFont.setFamily("STKaiti");

    if (currentKeyWord.length() == 0) {
        commodities = helper.readCommodities();
    } else {
        std::vector<Commodity> temp_commodities = helper.readCommodities();
        commodities.clear();
        for (Commodity c: temp_commodities) {
            if (helper.getSimilarity(c.getName(), currentKeyWord) >= threshold) {
                commodities.push_back(c);
            }
        }
        keyWord = currentKeyWord;
    }

    ui->listWidget->clear();
    for (int i = 0; i < commodities.size(); i++) {
        QWidget *widget = new QWidget(this);

        QLabel *label = new QLabel(widget);
        QPixmap *image = new QPixmap(
                commodities[i].getPicPath().c_str());

        label->setPixmap(*image);
        label->resize(200, 200);
        QHBoxLayout *layout = new QHBoxLayout();

        layout->addWidget(label);
        QLabel *nameLabel = new QLabel(QString::fromStdString(commodities[i].getName()));
        nameLabel->setFont(nameFont);
        layout->addWidget(nameLabel);

        std::string price = std::to_string(commodities[i].getPrice());
        QLabel *priceLabel = new QLabel(QString::fromStdString(price.substr(0, price.size() - 5)));
        priceLabel->setFont(priceFont);
        //priceLabel->setPalette(pe);
        priceLabel->setStyleSheet("color: red");

        layout->addWidget(priceLabel);

        widget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(350, 200));
        item->setText(QString::fromStdString(std::to_string(commodities[i].getId())));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);
    }
}

void ProductPurchase::search() {
    if (searchWidget == NULL) {
        searchWidget = new QWidget();
        searchWidget->move(1340, 300);
        searchWidget->setFixedSize(240, 200);
        keyWordPrompt = new QLineEdit(searchWidget);
        keyWordPrompt->move(35, 40);
        keyWordPrompt->setPlaceholderText("请输入关键词");


        QFont buttonFont;
        buttonFont.setFamily("STKaiti");
        buttonFont.setPointSize(20);

        keyWordPrompt->setFont(buttonFont);

        QPushButton *closeButton = new QPushButton(searchWidget);
        closeButton->setText("关闭");
        closeButton->move(30, 90);
        closeButton->setFont(buttonFont);
        connect(closeButton, &QPushButton::clicked, this, &ProductPurchase::closeSearch);

        QPushButton *searchButton = new QPushButton(searchWidget);
        searchButton->setText("搜索");
        searchButton->move(130, 90);
        searchButton->setFont(buttonFont);
        connect(searchButton, &QPushButton::clicked, this, &ProductPurchase::renewCommodityList);

        searchWidget->show();
    }
}

void ProductPurchase::closeSearch() {
    if (searchWidget != NULL) {
        searchWidget->close();
        searchWidget = NULL;
    }
}