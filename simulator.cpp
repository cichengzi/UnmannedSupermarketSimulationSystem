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

Simulator::Simulator(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Simulator) {
    ui->setupUi(this);
    connect(ui->productPurchase, &QPushButton::clicked, this, &Simulator::productPurchase);
    connect(ui->Authentication, &QPushButton::clicked, this, &Simulator::authentication);
    connect(ui->deal, &QPushButton::clicked, this, &Simulator::deal);
    connect(ui->maskDetection, &QPushButton::clicked, this, &Simulator::maskDetection);
    connect(ui->purchaseRecord, &QPushButton::clicked, this, &Simulator::purchaseRecord);
    connect(ui->cargoManagement, &QPushButton::clicked, this, &Simulator::margoManagement);

    mask = false; // 设置口罩检测的状态，初始状态为未通过
    currentUser = User(); // 初始用户，id为0，象征未验证
    shoppingCart = ShoppingCart(currentUser); // 购物车的初始化
}

Simulator::~Simulator() {
    delete ui;
}

void Simulator::productPurchase() {
    if (mask && currentUser.getId() != 0) { // 如果口罩检测通过并且当前用户的id不为0，即身份验证通过
        //std::cout << currentUser.getName() << std::endl;
        ProductPurchase *productPurchase = new ProductPurchase(); // 商品购买界面
        productPurchase->setCurrentUser(currentUser); // 设置商品购买类中的currentUser
        productPurchase->setShoppingCart(searchShoppingCart(currentUser)); // 设置商品购买类中的shoppingCart
        productPurchase->show(); // 展示商品购买界面
        this->close(); // 关闭当前界面
    }
    else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请佩戴口罩");
    }
    else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先身份验证");
    }
}

void Simulator::authentication() {
    Helper helper;
//    currentUser = helper.faceRecognize(); // 调用人脸识别对当前用户进行身份验证，获取currentUser
    if (currentUser.getId() != 0) { // 如果id不为0，即通过身份验证
        /*
        std::vector<ShoppingCart> carts = helper.readShoppingCarts();
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].getUser().getName() == currentUser.getName()) {
                shoppingCart = carts[i];
                break;
            }
        }
        shoppingCart.setUser(currentUser);
         */
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
    /*
     * 口罩检测部分代码
     */
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

void Simulator::deal() {
    if (mask && currentUser.getId() != 0) {
        double total_price = shoppingCart.getTotalPrice();
        if (total_price <= currentUser.getBalance()) {
            QString title = QString::fromStdString("商品结算");
            QString content = QString::fromStdString("商品结算成功");
            QString buttonText = QString::fromStdString("确定");
            QMessageBox::information(this, title, content, buttonText);

            updateUser(); // 更新currentUser和users.txt

            std::cout << "Before update Record:" << std::endl;
            std::cout << shoppingCart.toString() << std::endl;
            updateRecord(); // 更新records.txt

            std::cout << "Before update ShoppingCart:" << std::endl;
            std::cout << shoppingCart.toString() << std::endl;
            updateShoppingCart(); // 清空shoppingCart并更新carts.txt

        } else {
            QString title = QString::fromStdString("商品结算");
            QString content = QString::fromStdString("商品结算失败");
            QString buttonText = QString::fromStdString("确定");
            QMessageBox::information(this, title, content, buttonText);
        }
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请佩戴口罩");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先身份验证");
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

void Simulator::purchaseRecord() {
    if (currentUser.getId() != 0 && mask) {
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
        recordWidget->setFixedSize(240, 720);
        recordListWidget = new QListWidget(recordWidget);
        recordListWidget->setFixedSize(240, 480);
        for (Commodity c: currentRecord.getAllCommodities().getAllCommodities()) {
            QWidget *widget = new QWidget(recordWidget);
            QHBoxLayout *layout = new QHBoxLayout();

            layout->addWidget(new QLabel(QString::fromStdString(c.getName())));
            layout->addWidget(new QLabel(QString::fromStdString(std::to_string(c.getNumber()))));

            widget->setLayout(layout);

            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(240, 40));
            recordListWidget->addItem(item);
            recordListWidget->setItemWidget(item, widget);
        }
        recordButton = new QPushButton(recordWidget);
        recordButton->setText("关闭");
        recordButton->move(100, 600);

        connect(recordButton, &QPushButton::clicked, this, &Simulator::closeRecord);

        recordWidget->show();

    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请佩戴口罩");
    } else { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先身份验证");
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
        manageWidget = new QWidget();
        manageWidget->setFixedSize(480, 720);

        picPathPrompt = new QLineEdit(manageWidget);
        picPathPrompt->setText("请输入商品图片路径");
        picPathPrompt->move(50, 50);

        namePrompt = new QLineEdit(manageWidget);
        namePrompt->setText("请输入商品名称");
        namePrompt->move(50, 150);

        pricePrompt = new QLineEdit(manageWidget);
        pricePrompt->setText("请输入商品价格");
        pricePrompt->move(50, 250);

        numberPrompt = new QLineEdit(manageWidget);
        numberPrompt->setText("请输入商品数量");
        numberPrompt->move(50, 350);

        descriptionPrompt = new QLineEdit(manageWidget);
        descriptionPrompt->setText("请输入商品描述");
        descriptionPrompt->move(50, 450);

        manageAddButton = new QPushButton(manageWidget);
        manageAddButton->setText("添加");

        manageCloseButton = new QPushButton(manageWidget);
        manageCloseButton->setText("关闭");
        manageCloseButton->move(50, 550);

        connect(manageCloseButton, &QPushButton::clicked, this, &Simulator::closeMargoManagement);

        manageWidget->show();
    } else if (!mask) { // 如果没有通过口罩检测
        QMessageBox::warning(this, "警告", "请佩戴口罩");
    } else if (currentUser.getId() == 0) { // 如果没有通过身份验证
        QMessageBox::warning(this, "警告", "请先身份验证");
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
    }

    if (number.length() == 0) {
        QMessageBox::warning(this, "警告", "商品数量不能为空");
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
    if (add)
        commodities.push_back(Commodity(name, atof(price.c_str()), atoi(number.c_str()), description));
    helper.saveCommodities(commodities);

    QString title = QString::fromStdString("添加货物");
    QString content = QString::fromStdString("货物添加成功！");
    QString buttonText = QString::fromStdString("确定");
    QMessageBox::information(this, title, content, buttonText);
}

void Simulator::removeMargo() {
    Helper helper;
    std::string name = namePrompt->text().toStdString();
    std::vector<Commodity> commodities = helper.readCommodities();
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
}

