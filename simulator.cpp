#include "simulator.h"
#include "ui_Simulator.h"
#include"productpurchase.h"
#include"ui_ProductPurchase.h"
#include"Helper.h"
#include<iostream>
#include<QMessageBox>
#include <QHBoxLayout>
#include<QLineEdit>
#include<fstream>
#include<exception>
#include<map>
#include<QFont>

Simulator::Simulator(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Simulator) {
    ui->setupUi(this);
    connect(ui->productPurchase, &QPushButton::clicked, this, &Simulator::productPurchase);
    connect(ui->Authentication, &QPushButton::clicked, this, &Simulator::authentication);
    connect(ui->deal, &QPushButton::clicked, this, &Simulator::dealCommodity);
    connect(ui->maskDetection, &QPushButton::clicked, this, &Simulator::maskDetection);
    connect(ui->purchaseRecord, &QPushButton::clicked, this, &Simulator::purchaseRecord);
    connect(ui->cargoManagement, &QPushButton::clicked, this, &Simulator::margoManagement);
    connect(ui->addUser, &QPushButton::clicked, this, &Simulator::addUser);
    connect(ui->count, &QPushButton::clicked, this, &Simulator::bestSell);
    connect(ui->quit, &QPushButton::clicked, this, &Simulator::quit);

    mask = false; // 设置口罩检测的状态，初始状态为未通过
    currentUser = User(); // 初始用户，id为0，象征未验证
    shoppingCart = ShoppingCart(currentUser); // 购物车的初始化

    // 设置字体

    //QFont buttonFont;
    //buttonFont.setFamily("STKaiti");
    //buttonFont.setPointSize(25);
    //ui->Authentication->setFont(buttonFont);
    ui->Authentication->setFlat(true);
    //ui->productPurchase->setFont(buttonFont);
    ui->productPurchase->setFlat(true);
    //ui->maskDetection->setFont(buttonFont);
    ui->maskDetection->setFlat(true);
    //ui->deal->setFont(buttonFont);
    ui->deal->setFlat(true);
    //ui->purchaseRecord->setFont(buttonFont);
    ui->purchaseRecord->setFlat(true);
    //ui->cargoManagement->setFont(buttonFont);
    ui->cargoManagement->setFlat(true);
    //ui->addUser->setFont(buttonFont);
    ui->addUser->setFlat(true);
    //ui->count->setFont(buttonFont);
    ui->count->setFlat(true);
    ui->quit->setFlat(true);

    ui->centralWidget->setStyleSheet("QWidget{background: white;}");

    iconLabel1 = new QLabel(ui->centralWidget);
    QImage* iconImage1 = new QImage();
    iconImage1->load("/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/icon.jpg");
    iconLabel1->setPixmap(QPixmap::fromImage(*iconImage1));
    iconLabel1->move(60, 450);

    iconLabel2 = new QLabel(ui->centralWidget);
    QImage* iconImage2 = new QImage();
    iconImage2->load("/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/resources/icon1.jpg");
    iconLabel2->setPixmap(QPixmap::fromImage(*iconImage2));
    iconLabel2->move(660, 450);

    this->move(380, 200);
    bestSellWidget = NULL;
    dealWidget = NULL;
    addUserWidget = NULL;
    manageWidget = NULL;
    recordWidget = NULL;

    mask = true;
}

Simulator::~Simulator() {
    delete ui;
}

void Simulator::productPurchase() {
    if (mask && currentUser.getId() != 0) { // 如果口罩检测通过并且当前用户的id不为0，即身份验证通过
        //std::cout << currentUser.getName() << std::endl;
        ProductPurchase *productPurchase = new ProductPurchase(); // 商品购买界面
        //std::cout << "after create product purchase" << std::endl;
        productPurchase->setCurrentUser(currentUser); // 设置商品购买类中的currentUser
        //std::cout << "current line" << std::endl;
        productPurchase->setShoppingCart(searchShoppingCart(currentUser)); // 设置商品购买类中的shoppingCart
        productPurchase->show(); // 展示商品购买界面
        if (bestSellWidget != NULL) {
            bestSellWidget->close();
            bestSellWidget = NULL;
        }
        if (dealWidget != NULL) {
            dealWidget->close();
            dealWidget = NULL;
        }
        if (addUserWidget != NULL) {
            addUserWidget->close();
            addUserWidget = NULL;
        }
        if (manageWidget != NULL) {
            manageWidget->close();
            manageWidget = NULL;
        }
        if (recordWidget != NULL) {
            recordWidget->close();
            recordWidget = NULL;
        }
        this->close(); // 关闭当前界面
    } else if (!mask && currentUser.getId() == 0) {
        QMessageBox::warning(this, "警告", "请先通过防疫检测和身份验证");
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请先通过防疫检测");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先通过身份验证");
    }
}

void Simulator::authentication() {
    if (currentUser.getId() != 0) {
        QMessageBox::warning(this, "警告", "已完成身份验证，若需其他人使用，请先退出系统");
        return;
    }
    Helper helper;
    if (!DEBUG)
        currentUser = helper.faceRecognize(); // 调用人脸识别对当前用户进行身份验证，获取currentUser
    else
        currentUser = helper.readUsers().front();
    if (currentUser.getId() != 0) { // 如果id不为0，即通过身份验证
        shoppingCart = searchShoppingCart(currentUser);
        QString title = QString::fromStdString("身份验证");
        QString content = QString::fromStdString("身份验证成功！当前用户为\"" + currentUser.getName() + "\"");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
    } else {
        shoppingCart = ShoppingCart(currentUser);
        QString title = QString::fromStdString("身份验证");
        QString content = QString::fromStdString("身份验证失败！");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
    }
}

void Simulator::setShoppingCart(ShoppingCart cart) {
    shoppingCart = cart;
}

void Simulator::setCurrentUser(User us) {
    currentUser = us;
}

void Simulator::maskDetection() {
    if (mask) {
        QMessageBox::warning(this, "警告", "已完成防疫检测，请勿重复检测");
        return;
    }
    Helper helper;
    if (!DEBUG)
        mask = helper.maskDetection();
    else
        mask = true;
    if (mask) {
        QString title = QString::fromStdString("防疫检测");
        QString content = QString::fromStdString("防疫检测通过！");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
    }
    else {
        QString title = QString::fromStdString("防疫检测");
        QString content = QString::fromStdString("防疫检测不通过！");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
    }
}

void Simulator::updateCommodity() {
    Helper helper;
    std::vector<Commodity> commodities = helper.readCommodities();
    for (Commodity commodity: shoppingCart.getAllCommodities().getAllCommodities()) {
        for (int i = 0; i < commodities.size(); i++) {
            if (commodities[i].getName() == commodity.getName()) {
                commodities[i].setNumber(commodities[i].getNumber() - commodity.getNumber());
                break;
            }
        }
    }
    std::vector<Commodity> new_commodities;
    for (Commodity commodity: commodities) {
        if (commodity.getNumber() == 0)
            continue;
        new_commodities.push_back(commodity);
    }
    helper.saveCommodities(new_commodities);
}

void Simulator::dealCommodity() {
    if (mask && currentUser.getId() != 0) {
        if (bestSellWidget != NULL) {
            bestSellWidget->close();
            bestSellWidget = NULL;
        }
        if (addUserWidget != NULL) {
            addUserWidget->close();
            addUserWidget = NULL;
        }
        if (manageWidget != NULL) {
            manageWidget->close();
            manageWidget = NULL;
        }
        if (recordWidget != NULL) {
            recordWidget->close();
            recordWidget = NULL;
        }

        if (dealWidget == NULL) {
            QFont buttonFont;
            buttonFont.setFamily("STKaiti");
            buttonFont.setPointSize(30);
            dealWidget = new QWidget();
            QPushButton *yes = new QPushButton(dealWidget);
            QPushButton *no = new QPushButton(dealWidget);

            QFont nameFont;
            nameFont.setPointSize(15);
            nameFont.setFamily("STKaiti");

            QFont numFont;
            numFont.setPointSize(20);
            numFont.setFamily("STKaiti");

            dealWidget->setFixedSize(480, 720);
            yes->setText("确定");
            yes->setFont(buttonFont);
            no->setText("取消");
            no->setFont(buttonFont);
            yes->move(100, 660);
            yes->setFlat(true);
            no->move(260, 660);
            no->setFlat(true);
            dealWidget->move(1340, 200);

            QFont labelFont;
            labelFont.setFamily("STKaiti");
            labelFont.setPointSize(25);

            QLabel* balanceLabel = new QLabel(dealWidget);
            std::string balanceText = std::to_string(currentUser.getBalance());
            balanceText = balanceText.substr(0, balanceText.length() - 4);
            balanceLabel->setText(("余额: " + balanceText).c_str());
            balanceLabel->move(0, 620);
            balanceLabel->setFixedSize(240, 40);
            balanceLabel->setFont(labelFont);

            QLabel* totalPriceLabel = new QLabel(dealWidget);
            std::string totalPriceText = std::to_string(shoppingCart.getTotalPrice());
            totalPriceText = totalPriceText.substr(0, totalPriceText.length() - 4);
            totalPriceLabel->setText(("总价: " + totalPriceText).c_str());
            totalPriceLabel->move(240, 620);
            totalPriceLabel->setFixedSize(240, 40);
            totalPriceLabel->setFont(labelFont);

            QListWidget *commodityListWidget = new QListWidget(dealWidget);
            commodityListWidget->setFixedSize(480, 600);
            for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
                QWidget *widget = new QWidget(commodityListWidget);
                QHBoxLayout *layout = new QHBoxLayout();

                QLabel *nameLabel = new QLabel(QString::fromStdString(c.getName()));
                nameLabel->setFont(nameFont);
                layout->addWidget(nameLabel);

                QLabel *numLabel = new QLabel(QString::fromStdString(std::to_string(c.getNumber())));
                numLabel->setFont(numFont);
                layout->addWidget(numLabel);

                widget->setLayout(layout);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(480, 50));
                commodityListWidget->addItem(item);
                commodityListWidget->setItemWidget(item, widget);
            }

            connect(yes, &QPushButton::clicked, this, &Simulator::deal);
            connect(no, &QPushButton::clicked, this, &Simulator::closeDealCommodity);

            dealWidget->show();
        }
    } else if (!mask && currentUser.getId() == 0) {
        QMessageBox::warning(this, "警告", "请先通过防疫检测和身份验证");
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请先通过防疫检测");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先通过身份验证");
    }
}

void Simulator::closeDealCommodity() {
    dealWidget->close();
    dealWidget = NULL;
}

void Simulator::deal() {
    double total_price = shoppingCart.getTotalPrice();
    if (total_price <= currentUser.getBalance()) {
        QString title = QString::fromStdString("商品结算");
        std::string content_str = "商品结算成功";
        for (Commodity commodity: shoppingCart.getAllCommodities().getAllCommodities()) {
            content_str += "\n" + commodity.getName() + " x " + std::to_string(commodity.getNumber());
        }
        QString content = QString::fromStdString(content_str);
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);

        updateUser(); // 更新currentUser和users.txt

        std::cout << "Before update Record:" << std::endl;
        std::cout << shoppingCart.toString() << std::endl;
        updateRecord(); // 更新records.txt

        std::cout << "After update ShoppingCart:" << std::endl;
        std::cout << shoppingCart.toString() << std::endl;
        updateCommodity(); // 更新commodities.txt

        updateShoppingCart(); // 清空shoppingCart并更新carts.txt

        dealWidget->close();
    } else {
        QString title = QString::fromStdString("商品结算");
        QString content = QString::fromStdString("商品结算失败");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
        dealWidget->close();
    }
}

void Simulator::setMask(bool m) {
    mask = m;
}

ShoppingCart Simulator::searchShoppingCart(User us) {
    Helper helper;
    std::vector<ShoppingCart> carts = helper.readShoppingCarts();
    for (ShoppingCart cart: carts) {
        if (cart.getUser().getName() == us.getName())
            return cart;
    }
    return ShoppingCart(us);
}

void Simulator::updateUser() {
    double total_price = shoppingCart.getTotalPrice();
    currentUser.setBalance(currentUser.getBalance() - total_price);
    shoppingCart.setUser(currentUser);
    Helper helper;
    std::vector<User> users = helper.readUsers();
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getName() == currentUser.getName()) {
            users[i] = currentUser;
            helper.saveUsers(users);
            break;
        }
    }
}

void Simulator::updateShoppingCart() {
    Helper helper;
    std::vector<ShoppingCart> carts = helper.readShoppingCarts();
    std::vector<ShoppingCart> new_carts;
    for (ShoppingCart cart: carts) {
        if (cart.getUser().getName() == shoppingCart.getUser().getName())
            continue;
        new_carts.push_back(cart);
    }
    helper.saveShoppingCarts(new_carts);
    shoppingCart.clear();
}

void Simulator::updateRecord() {
    Helper helper;
    std::vector<ShoppingCart> records = helper.readRecords();
    bool add = true;
    for (int i = 0; i < records.size(); i++) {
        if (records[i].getUser().getName() == currentUser.getName()) {
            records[i].setUser(currentUser);
            for (Commodity c: shoppingCart.getAllCommodities().getAllCommodities()) {
                if (records[i].getCommodity(c.getId()).getNumber() > 0) {
                    int num = records[i].getCommodity(c.getId()).getNumber() + c.getNumber();
                    records[i].removeCommodityById(c.getId());
                    c.setNumber(num);
                    records[i].addCommodity(c);
                } else {
                    records[i].addCommodity(c);
                }
            }
            add = false;
            break;
        }
    }
    if (add)
        records.push_back(shoppingCart);
    helper.saveRecords(records);
}

void Simulator::faceCrawl() {
    std::string user_name = faceNamePrompt->text().toStdString();
    if (user_name.length() == 0) {
        QString title = "人脸采集";
        QString content = "人脸采集失败，用户姓名不能为空";
        QString buttonText = "确定";
        QMessageBox::information(this, title, content, buttonText);
        return;
    }
    system(("/Users/cichengzi/miniforge3/envs/DL/bin/python ../FaceRecognition/add_faces.py " + user_name).c_str());
    QString title = "人脸采集";
    QString content = "人脸采集成功";
    QString buttonText = "确定";
    QMessageBox::warning(this, title, content, buttonText);
}

void Simulator::newUser() {
    try {
        std::string face_name = faceNamePrompt->text().toStdString();
        std::string user_type = userTypePrompt->text().toStdString();
        std::string balance = balancePrompt->text().toStdString();
        if (face_name.length() == 0) {
            QMessageBox::warning(this, "警告", "姓名不能为空");
            return;
        }
        UserType ut;
        if (user_type[0] == 'a' || user_type[0] == 'A') {
            ut = UserType::Administrator;
        } else if (user_type[0] == 'g' || user_type[0] == 'G') {
            ut = UserType::GeneralUser;
        } else {
            QMessageBox::warning(this, "警告", "用户类型不合法");
            return;
        }
        double b = atof(balance.c_str());
        User user = User(face_name, ut, b);
        Helper helper;
        std::vector<User> users = helper.readUsers();
        bool add = true;
        for (User us: users) {
            if (us.getName() == user.getName()) {
                add = false;
                break;
            }
        }
        if (add)
            users.push_back(user);
        helper.saveUsers(users);
        QString title = QString::fromStdString("添加用户");
        QString content = QString::fromStdString("添加用户成功");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);

        faceNamePrompt->clear();
        userTypePrompt->clear();
        balancePrompt->clear();
    } catch (char *e) {
        QString title = QString::fromStdString("添加用户");
        QString content = QString::fromStdString("添加用户失败");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
    }
}

void Simulator::closeAddUser() {
    if (addUserWidget != NULL) {
        addUserWidget->close();
        addUserWidget = NULL;
    }
}

void Simulator::addUser() {
    if (mask && currentUser.getId() != 0) {
        if (bestSellWidget != NULL) {
            bestSellWidget->close();
            bestSellWidget = NULL;
        }
        if (dealWidget != NULL) {
            dealWidget->close();
            dealWidget = NULL;
        }
        if (manageWidget != NULL) {
            manageWidget->close();
            manageWidget = NULL;
        }
        if (recordWidget != NULL) {
            recordWidget->close();
            recordWidget = NULL;
        }

        if (addUserWidget == NULL) {
            QFont nameFont;
            nameFont.setPointSize(15);
            nameFont.setFamily("STKaiti");

            QFont labelFont;
            labelFont.setPointSize(25);
            labelFont.setFamily("STKaiti");

            QFont buttonFont;
            buttonFont.setPointSize(30);
            buttonFont.setFamily("STKaiti");

            addUserWidget = new QWidget();
            addUserWidget->setFixedSize(480, 360);

            faceNamePrompt = new QLineEdit(addUserWidget);
            faceNamePrompt->setPlaceholderText("请输入姓名");
            faceNamePrompt->setFixedSize(200, 40);
            faceNamePrompt->setFont(nameFont);
            faceNamePrompt->move(200, 30);

            QLabel *faceNameLabel = new QLabel(addUserWidget);
            faceNameLabel->setText("用 户 姓 名");
            faceNameLabel->setFont(labelFont);
            faceNameLabel->move(50, 30);

            QLabel *userTypeLabel = new QLabel(addUserWidget);
            userTypeLabel->setText("用 户 类 型");
            userTypePrompt = new QLineEdit(addUserWidget);
            userTypePrompt->setPlaceholderText("Admin/GeneralUser");
            userTypePrompt->setFixedSize(200, 40);
            userTypePrompt->setFont(nameFont);
            userTypePrompt->move(200, 110);
            userTypeLabel->setFont(labelFont);
            userTypeLabel->move(50, 110);

            QLabel *balanceLabel = new QLabel(addUserWidget);
            balanceLabel->setText("用 户 余 额");
            balanceLabel->setFont(labelFont);
            balanceLabel->move(50, 190);
            balancePrompt = new QLineEdit(addUserWidget);
            balancePrompt->setPlaceholderText("请输入用户余额");
            balancePrompt->setFont(nameFont);
            balancePrompt->setFixedSize(200, 40);
            balancePrompt->move(200, 190);

            QPushButton *newUserButton = new QPushButton(addUserWidget);
            newUserButton->setText("添加用户");
            newUserButton->setFont(buttonFont);
            newUserButton->move(20, 270);
            newUserButton->setFlat(true);

            faceCrawlButton = new QPushButton(addUserWidget);
            faceCrawlButton->setText("人脸采集");
            faceCrawlButton->setFont(buttonFont);
            faceCrawlButton->move(165, 270);
            faceCrawlButton->setFlat(true);

            QPushButton *closeButton = new QPushButton(addUserWidget);
            closeButton->setText("关闭界面");
            closeButton->setFont(buttonFont);
            closeButton->move(310, 270);
            closeButton->setFlat(true);

            connect(faceCrawlButton, &QPushButton::clicked, this, &Simulator::faceCrawl);
            connect(newUserButton, &QPushButton::clicked, this, &Simulator::newUser);
            connect(closeButton, &QPushButton::clicked, this, &Simulator::closeAddUser);

            addUserWidget->move(1340, 200);
            addUserWidget->show();
        }
    } else if (!mask && currentUser.getId() == 0) {
        QMessageBox::warning(this, "警告", "请先通过防疫检测和身份验证");
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请先通过防疫检测");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先通过身份验证");
    }
}

void Simulator::purchaseRecord() {
    if (currentUser.getId() != 0 && mask) {
        if (bestSellWidget != NULL) {
            bestSellWidget->close();
            bestSellWidget = NULL;
        }
        if (dealWidget != NULL) {
            dealWidget->close();
            dealWidget = NULL;
        }
        if (addUserWidget != NULL) {
            addUserWidget->close();
            addUserWidget = NULL;
        }
        if (manageWidget != NULL) {
            manageWidget->close();
            manageWidget = NULL;
        }

        if (recordWidget == NULL) {
            Helper helper;
            std::vector<ShoppingCart> records = helper.readRecords();
            ShoppingCart currentRecord = ShoppingCart(currentUser);
            for (ShoppingCart record: records) {
                if (record.getUser().getName() == currentUser.getName()) {
                    currentRecord = record;
                    break;
                }
            }
            recordWidget = new QWidget();
            recordWidget->setFixedSize(540, 720);
            recordListWidget = new QListWidget(recordWidget);
            recordListWidget->setFixedSize(540, 600);

            QFont nameFont;
            nameFont.setPointSize(15);
            nameFont.setFamily("STKaiti");

            QFont numFont;
            numFont.setPointSize(20);
            numFont.setFamily("STKaiti");

            QFont buttonFont;
            buttonFont.setPointSize(40);
            buttonFont.setFamily("STKaiti");

            for (Commodity c: currentRecord.getAllCommodities().getAllCommodities()) {
                QWidget *widget = new QWidget(recordWidget);
                QHBoxLayout *layout = new QHBoxLayout();

                QLabel *nameLabel = new QLabel(QString::fromStdString(c.getName()));
                nameLabel->setFont(nameFont);
                nameLabel->setFixedSize(500, 60);
                layout->addWidget(nameLabel);

                QLabel *numLabel = new QLabel(QString::fromStdString(std::to_string(c.getNumber())));
                numLabel->setFont(numFont);
                numLabel->setFixedSize(40, 60);
                layout->addWidget(numLabel);

                widget->setLayout(layout);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(540, 60));
                recordListWidget->addItem(item);
                recordListWidget->setItemWidget(item, widget);
            }
            recordButton = new QPushButton(recordWidget);
            recordButton->setText("关闭");
            recordButton->setFont(buttonFont);
            recordButton->move(220, 620);
            recordButton->setFlat(true);

            connect(recordButton, &QPushButton::clicked, this, &Simulator::closeRecord);

            recordWidget->move(1340, 200);
            recordWidget->show();
        }

    } else if (!mask && currentUser.getId() == 0) {
        QMessageBox::warning(this, "警告", "请先通过防疫检测和身份验证");
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请先通过防疫检测");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先通过身份验证");
    }
}

void Simulator::closeRecord() {
    if (recordWidget != NULL) {
        recordWidget->close();
        recordWidget = NULL;
        recordListWidget = NULL;
        recordButton = NULL;
    }
}

void Simulator::margoManagement() {
    if (mask && currentUser.getId() != 0 && currentUser.getUserType() == UserType::Administrator) {
        if (bestSellWidget != NULL) {
            bestSellWidget->close();
            bestSellWidget = NULL;
        }
        if (dealWidget != NULL) {
            dealWidget->close();
            dealWidget = NULL;
        }
        if (addUserWidget != NULL) {
            addUserWidget->close();
            addUserWidget = NULL;
        }
        if (recordWidget != NULL) {
            recordWidget->close();
            recordWidget = NULL;
        }

        if (manageWidget == NULL) {
            QFont nameFont;
            nameFont.setPointSize(15);
            nameFont.setFamily("STKaiti");

            QFont labelFont;
            labelFont.setPointSize(25);
            labelFont.setFamily("STKaiti");

            QFont buttonFont;
            buttonFont.setPointSize(30);
            buttonFont.setFamily("STKaiti");

            manageWidget = new QWidget();
            manageWidget->setFixedSize(480, 720);

            picPathPrompt = new QLineEdit(manageWidget);
            picPathPrompt->setPlaceholderText("请输入商品图片路径");
            picPathPrompt->setFont(nameFont);
            picPathPrompt->move(200, 50);
            picPathPrompt->setFixedSize(250, 40);
            QLabel *picPathLabel = new QLabel(manageWidget);
            picPathLabel->setText("图 片 路 径");
            picPathLabel->move(35, 55);
            picPathLabel->setFont(labelFont);

            namePrompt = new QLineEdit(manageWidget);
            namePrompt->setPlaceholderText("请输入商品名称");
            namePrompt->setFont(nameFont);
            namePrompt->move(200, 150);
            namePrompt->setFixedSize(250, 40);
            QLabel *nameLabel = new QLabel(manageWidget);
            nameLabel->setText("商 品 名 称");
            nameLabel->move(35, 155);
            nameLabel->setFont(labelFont);

            pricePrompt = new QLineEdit(manageWidget);
            pricePrompt->setPlaceholderText("请输入商品价格");
            pricePrompt->setFont(nameFont);
            pricePrompt->move(200, 250);
            pricePrompt->setFixedSize(250, 40);
            QLabel *priceLabel = new QLabel(manageWidget);
            priceLabel->setText("商 品 价 格");
            priceLabel->move(35, 255);
            priceLabel->setFont(labelFont);

            numberPrompt = new QLineEdit(manageWidget);
            numberPrompt->setPlaceholderText("请输入商品数量");
            numberPrompt->setFont(nameFont);
            numberPrompt->move(200, 350);
            numberPrompt->setFixedSize(250, 40);
            QLabel *numberLabel = new QLabel(manageWidget);
            numberLabel->setText("商 品 数 量");
            numberLabel->move(35, 355);
            numberLabel->setFont(labelFont);

            descriptionPrompt = new QLineEdit(manageWidget);
            descriptionPrompt->setPlaceholderText("请输入商品描述");
            descriptionPrompt->setFont(nameFont);
            descriptionPrompt->move(200, 450);
            descriptionPrompt->setFixedSize(250, 40);
            QLabel *descriptionLabel = new QLabel(manageWidget);
            descriptionLabel->setText("商 品 描 述");
            descriptionLabel->move(35, 455);
            descriptionLabel->setFont(labelFont);

            manageAddButton = new QPushButton(manageWidget);
            manageAddButton->setText("进货");
            manageAddButton->move(70, 550);
            manageAddButton->setFont(buttonFont);
            manageAddButton->setFlat(true);

            manageSubButton = new QPushButton(manageWidget);
            manageSubButton->setText("出货");
            manageSubButton->move(280, 550);
            manageSubButton->setFont(buttonFont);
            manageSubButton->setFlat(true);

            manageCloseButton = new QPushButton(manageWidget);
            manageCloseButton->setText("关闭");
            manageCloseButton->move(70, 620);
            manageCloseButton->setFont(buttonFont);
            manageCloseButton->setFlat(true);

            manageHelpButton = new QPushButton(manageWidget);
            manageHelpButton->setText("帮助");
            manageHelpButton->move(280, 620);
            manageHelpButton->setFont(buttonFont);
            manageHelpButton->setFlat(true);

            connect(manageCloseButton, &QPushButton::clicked, this, &Simulator::closeMargoManagement);
            connect(manageAddButton, &QPushButton::clicked, this, &Simulator::addMargo);
            connect(manageSubButton, &QPushButton::clicked, this, &Simulator::removeMargo);
            connect(manageHelpButton, &QPushButton::clicked, this, &Simulator::helpMargo);

            manageWidget->move(1340, 200);
            manageWidget->show();
        }
    } else if (!mask && currentUser.getId() == 0) {
        QMessageBox::warning(this, "警告", "请先通过防疫检测和身份验证");
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请先通过防疫检测");
    } else if (currentUser.getId() == 0) { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先通过身份验证");
    } else {
        QMessageBox::warning(this, "警告", "您不是管理员，无法进行进出货管理");
    }
}

void Simulator::closeMargoManagement() {
    if (manageWidget != NULL) {
        manageWidget->close();
        manageWidget = NULL;
        picPathPrompt = NULL;
        namePrompt = NULL;
        pricePrompt = NULL;
        numberPrompt = NULL;
        descriptionPrompt = NULL;
        manageAddButton = NULL;
        manageCloseButton = NULL;
    }
}

void Simulator::addMargo() {
    Helper helper;
    std::string pic_path = picPathPrompt->text().toStdString();
    std::string name = namePrompt->text().toStdString();
    std::string price = pricePrompt->text().toStdString();
    std::string number = numberPrompt->text().toStdString();
    std::string description = descriptionPrompt->text().toStdString();
    std::string idx = helper.currentTimeStamp();
    if (pic_path.length() == 0) {
        QMessageBox::warning(this, "警告", "商品图片路径不能为空");
        return;
    }

    // 判断商品图片路径处是否存在文件
    std::ifstream f(pic_path.c_str());
    if (!f.good()) {
        QMessageBox::warning(this, "警告", "商品图片路径处不存在图片文件");
        return;
    }

    if (name.length() == 0) {
        QMessageBox::warning(this, "警告", "商品名称不能为空");
        return;
    }

    if (price.length() == 0) {
        QMessageBox::warning(this, "警告", "商品价格不能为空");
        return;
    }

    // 判断价格是否合法
    try {
        double p = atof(price.c_str());
    }catch (char *e) {
        QMessageBox::warning(this, "警告", "商品价格不合法");
        return;
    }

    if (number.length() == 0) {
        QMessageBox::warning(this, "警告", "商品数量不能为空");
        return;
    }

    try {
        int num = atoi(number.c_str());
    }catch (char *e) {
        QMessageBox::warning(this, "警告", "商品数量不合法");
        return;
    }

    std::vector<Commodity> commodities = helper.readCommodities();
    bool add = true;
    for (int i = 0; i < commodities.size(); i++) {
        if (commodities[i].getName() == name) {
            int num = commodities[i].getNumber() + atoi(number.c_str());
            commodities[i].setNumber(num);
            add = false;
            break;
        }
    }
    Commodity commodity = Commodity(name, atof(price.c_str()), atoi(number.c_str()), description);
    commodity.setPicPath(pic_path);
    if (add)
        commodities.push_back(commodity);
    helper.saveCommodities(commodities);

    QString title = QString::fromStdString("添加货物");
    QString content = QString::fromStdString("货物添加成功！");
    QString buttonText = QString::fromStdString("确定");
    QMessageBox::information(this, title, content, buttonText);
}

void Simulator::removeMargo() {
    Helper helper;
    std::string name = namePrompt->text().toStdString();
    std::string number = numberPrompt->text().toStdString();
    if (name.length() == 0) {
        QMessageBox::warning(this, "警告", "商品名称不能为空");
        return;
    }
    Commodity commodity;
    std::vector<Commodity> commodities = helper.readCommodities();
    for (Commodity c: commodities) {
        if (c.getName() == name) {
            commodity = c;
            break;
        }
    }

    if (commodity.getId() == 0) {
        QMessageBox::warning(this, "警告", "不存在此名称的商品");
        return;
    }

    if (number.length() == 0) {
        std::vector<Commodity> new_commodities;
        for (Commodity c: commodities) {
            if (c.getName() == name)
                continue;
            new_commodities.push_back(c);
        }
        helper.saveCommodities(new_commodities);

        QString title = QString::fromStdString("删除货物");
        QString content = QString::fromStdString("货物删除成功！");
        QString buttonText = QString::fromStdString("确定");
        QMessageBox::information(this, title, content, buttonText);
    } else {
        try {
            int num = atoi(number.c_str());
            if (num > commodity.getNumber()) {
                QMessageBox::warning(this, "警告", "不存在这么多的此商品");
                return;
            }
            std::vector<Commodity> new_commodities;
            for (Commodity c: commodities) {
                if (c.getName() == name)
                    continue;
                new_commodities.push_back(c);
            }
            if (num < commodity.getNumber()) {
                commodity.setNumber(commodity.getNumber() - num);
                new_commodities.push_back(commodity);
            }
            helper.saveCommodities(new_commodities);
            QString title = QString::fromStdString("出货");
            QString content = QString::fromStdString("出货" + std::to_string(num) + "件成功！");
            QString buttonText = QString::fromStdString("确定");
            QMessageBox::information(this, title, content, buttonText);
        }catch(char *e) {
            QMessageBox::warning(this, "警告", "商品数量不合法");
            return;
        }
    }
}

void Simulator::helpMargo() {
    QString title = QString::fromStdString("进出货帮助");
    QString content = QString::fromStdString("进行进货操作时，请合法填写所有信息！\n进行出货时，只需填写商品名称和商品数量，不填写商品数量默认全部出货！");
    QString buttonText = QString::fromStdString("确定");
    QMessageBox::information(this, title, content, buttonText);
}

bool item_cmp(std::pair<std::string, int> a, std::pair<std::string, int> b) {
    return a.second > b.second;
}

void Simulator::bestSell() {
    if (mask && currentUser.getId() != 0) {
        if (dealWidget != NULL) {
            dealWidget->close();
            dealWidget = NULL;
        }
        if (addUserWidget != NULL) {
            addUserWidget->close();
            addUserWidget = NULL;
        }
        if (manageWidget != NULL) {
            manageWidget->close();
            manageWidget = NULL;
        }
        if (recordWidget != NULL) {
            recordWidget->close();
            recordWidget = NULL;
        }

        if (bestSellWidget == NULL) {
            Helper helper;
            std::map<std::string, int> nums;
            for (ShoppingCart sc: helper.readRecords()) {
                for (Commodity c: sc.getAllCommodities().getAllCommodities()) {
                    nums[c.getName()] = nums[c.getName()] + c.getNumber();
                }
            }
            std::vector<std::pair<std::string, int>> items;
            for (std::pair<std::string, int> num: nums) {
                items.push_back(num);
            }
            std::sort(items.begin(), items.end(), item_cmp);
            QString title = "最热销的商品前十";
            std::string content_string = "";
            for (int i = 0; i < items.size() && i < 10; i++) {
                if (content_string.length() == 0)
                    content_string += items[i].first + "(" + std::to_string(items[i].second) + ")";
                else
                    content_string += "\n" + items[i].first + "(" + std::to_string(items[i].second) + ")";
            }

            bestSellWidget = new QWidget();
            bestSellWidget->setFixedSize(480, 720);

            QFont labelFont;
            labelFont.setFamily("STKaiti");
            labelFont.setPointSize(35);

            QFont cFont;
            cFont.setFamily("STKaiti");
            cFont.setPointSize(15);

            QLabel *titleLabel = new QLabel(bestSellWidget);
            titleLabel->setText("最热销商品前十名");
            titleLabel->setFont(labelFont);
            titleLabel->move(105, 40);

            closeBestSellButton = new QPushButton(bestSellWidget);
            closeBestSellButton->setText("关闭窗口");
            closeBestSellButton->setFont(labelFont);
            closeBestSellButton->move(165, 650);
            closeBestSellButton->setFlat(true);

            connect(closeBestSellButton, &QPushButton::clicked, this, &Simulator::closeBestSell);
            QListWidget *goodsListWidget = new QListWidget(bestSellWidget);
            goodsListWidget->setFixedSize(480, 500);
            goodsListWidget->move(0, 100);

            for (int i = 0; i < items.size() && i < 10; i++) {
                std::string name = items[i].first;
                int num = items[i].second;

                QWidget *widget = new QWidget(this);
                widget->setFixedSize(480, 50);

                QLabel *nameLabel = new QLabel(widget);
                nameLabel->setText(name.c_str());
                nameLabel->setFixedSize(420, 50);
                nameLabel->move(0, 0);
                nameLabel->setFont(cFont);

                QLabel *numLabel = new QLabel(widget);
                numLabel->setText(std::to_string(num).c_str());
                numLabel->setFixedSize(60, 50);
                numLabel->move(440, 0);
                numLabel->setFont(cFont);

                QHBoxLayout *layout = new QHBoxLayout();
                layout->addWidget(nameLabel);
                layout->addWidget(numLabel);

                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(480, 50));
                goodsListWidget->addItem(item);
                goodsListWidget->setItemWidget(item, widget);
            }

            bestSellWidget->move(1340, 200);
            bestSellWidget->setStyleSheet("QWidget{background: white;}");
            bestSellWidget->show();
        }
    }
    else if (!mask && currentUser.getId() == 0) {
        QMessageBox::warning(this, "警告", "请先通过防疫检测和身份验证");
    }
    else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请先通过防疫检测");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先通过身份验证");
    }
}

void Simulator::closeBestSell() {
    if (bestSellWidget != NULL) {
        bestSellWidget->close();
        bestSellWidget = NULL;
    }
}

void Simulator::quit() {
    this->close();
}