/********************************************************************************
** Form generated from reading UI file 'ProductPurchase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTPURCHASE_H
#define UI_PRODUCTPURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductPurchase
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listWidget;
    QPushButton *currentItem;
    QPushButton *Back;
    QPushButton *AddCommodity;
    QPushButton *removeCommodity;
    QPushButton *ShoppingCart;

    void setupUi(QWidget *ProductPurchase)
    {
        if (ProductPurchase->objectName().isEmpty())
            ProductPurchase->setObjectName(QString::fromUtf8("ProductPurchase"));
        ProductPurchase->resize(960, 720);
        scrollArea = new QScrollArea(ProductPurchase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 960, 720));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 960, 720));
        listWidget = new QListWidget(scrollAreaWidgetContents);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 960, 600));
        currentItem = new QPushButton(scrollAreaWidgetContents);
        currentItem->setObjectName(QString::fromUtf8("currentItem"));
        currentItem->setGeometry(QRect(50, 630, 101, 51));
        Back = new QPushButton(scrollAreaWidgetContents);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(200, 630, 111, 51));
        AddCommodity = new QPushButton(scrollAreaWidgetContents);
        AddCommodity->setObjectName(QString::fromUtf8("AddCommodity"));
        AddCommodity->setGeometry(QRect(380, 630, 101, 51));
        removeCommodity = new QPushButton(scrollAreaWidgetContents);
        removeCommodity->setObjectName(QString::fromUtf8("removeCommodity"));
        removeCommodity->setGeometry(QRect(550, 630, 111, 51));
        ShoppingCart = new QPushButton(scrollAreaWidgetContents);
        ShoppingCart->setObjectName(QString::fromUtf8("ShoppingCart"));
        ShoppingCart->setGeometry(QRect(740, 630, 111, 51));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ProductPurchase);

        QMetaObject::connectSlotsByName(ProductPurchase);
    } // setupUi

    void retranslateUi(QWidget *ProductPurchase)
    {
        ProductPurchase->setWindowTitle(QCoreApplication::translate("ProductPurchase", "ProductPurchase", nullptr));
        currentItem->setText(QCoreApplication::translate("ProductPurchase", "\345\275\223\345\211\215\345\205\203\347\264\240", nullptr));
        Back->setText(QCoreApplication::translate("ProductPurchase", "\350\277\224\345\233\236", nullptr));
        AddCommodity->setText(QCoreApplication::translate("ProductPurchase", "+", nullptr));
        removeCommodity->setText(QCoreApplication::translate("ProductPurchase", "-", nullptr));
        ShoppingCart->setText(QCoreApplication::translate("ProductPurchase", "\350\264\255\347\211\251\350\275\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductPurchase: public Ui_ProductPurchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTPURCHASE_H
