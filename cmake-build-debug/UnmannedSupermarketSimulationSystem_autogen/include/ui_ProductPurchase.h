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
    QPushButton *clearShoppingCart;
    QPushButton *Back;
    QPushButton *AddCommodity;
    QPushButton *removeCommodity;
    QPushButton *ShoppingCart;
    QPushButton *searchCommodity;

    void setupUi(QWidget *ProductPurchase)
    {
        if (ProductPurchase->objectName().isEmpty())
            ProductPurchase->setObjectName(QString::fromUtf8("ProductPurchase"));
        ProductPurchase->resize(960, 720);
        scrollArea = new QScrollArea(ProductPurchase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(-1, 0, 971, 720));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 969, 718));
        listWidget = new QListWidget(scrollAreaWidgetContents);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(-1, 0, 961, 600));
        clearShoppingCart = new QPushButton(scrollAreaWidgetContents);
        clearShoppingCart->setObjectName(QString::fromUtf8("clearShoppingCart"));
        clearShoppingCart->setGeometry(QRect(10, 630, 151, 51));
        Back = new QPushButton(scrollAreaWidgetContents);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(180, 630, 131, 51));
        AddCommodity = new QPushButton(scrollAreaWidgetContents);
        AddCommodity->setObjectName(QString::fromUtf8("AddCommodity"));
        AddCommodity->setGeometry(QRect(330, 630, 131, 51));
        removeCommodity = new QPushButton(scrollAreaWidgetContents);
        removeCommodity->setObjectName(QString::fromUtf8("removeCommodity"));
        removeCommodity->setGeometry(QRect(480, 630, 151, 51));
        ShoppingCart = new QPushButton(scrollAreaWidgetContents);
        ShoppingCart->setObjectName(QString::fromUtf8("ShoppingCart"));
        ShoppingCart->setGeometry(QRect(650, 630, 151, 51));
        searchCommodity = new QPushButton(scrollAreaWidgetContents);
        searchCommodity->setObjectName(QString::fromUtf8("searchCommodity"));
        searchCommodity->setGeometry(QRect(820, 630, 121, 51));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ProductPurchase);

        QMetaObject::connectSlotsByName(ProductPurchase);
    } // setupUi

    void retranslateUi(QWidget *ProductPurchase)
    {
        ProductPurchase->setWindowTitle(QCoreApplication::translate("ProductPurchase", "ProductPurchase", nullptr));
        clearShoppingCart->setText(QCoreApplication::translate("ProductPurchase", "\346\270\205\347\251\272\350\264\255\347\211\251\350\275\246", nullptr));
        Back->setText(QCoreApplication::translate("ProductPurchase", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        AddCommodity->setText(QCoreApplication::translate("ProductPurchase", "\346\267\273\345\212\240\345\225\206\345\223\201", nullptr));
        removeCommodity->setText(QCoreApplication::translate("ProductPurchase", "\347\247\273\351\231\244\345\225\206\345\223\201", nullptr));
        ShoppingCart->setText(QCoreApplication::translate("ProductPurchase", "\346\230\276\347\244\272\350\264\255\347\211\251\350\275\246", nullptr));
        searchCommodity->setText(QCoreApplication::translate("ProductPurchase", "\346\220\234\347\264\242\345\225\206\345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductPurchase: public Ui_ProductPurchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTPURCHASE_H
