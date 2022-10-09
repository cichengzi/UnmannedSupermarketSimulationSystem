/********************************************************************************
** Form generated from reading UI file 'Simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulator
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *Authentication;
    QPushButton *productPurchase;
    QPushButton *maskDetection;
    QPushButton *deal;
    QPushButton *purchaseRecord;
    QPushButton *cargoManagement;
    QPushButton *addUser;

    void setupUi(QMainWindow *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->resize(960, 720);
        centralWidget = new QWidget(Simulator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 20, 201, 61));
        Authentication = new QPushButton(centralWidget);
        Authentication->setObjectName(QString::fromUtf8("Authentication"));
        Authentication->setGeometry(QRect(440, 160, 141, 61));
        productPurchase = new QPushButton(centralWidget);
        productPurchase->setObjectName(QString::fromUtf8("productPurchase"));
        productPurchase->setGeometry(QRect(440, 210, 141, 61));
        maskDetection = new QPushButton(centralWidget);
        maskDetection->setObjectName(QString::fromUtf8("maskDetection"));
        maskDetection->setGeometry(QRect(440, 110, 141, 61));
        deal = new QPushButton(centralWidget);
        deal->setObjectName(QString::fromUtf8("deal"));
        deal->setGeometry(QRect(440, 260, 141, 61));
        purchaseRecord = new QPushButton(centralWidget);
        purchaseRecord->setObjectName(QString::fromUtf8("purchaseRecord"));
        purchaseRecord->setGeometry(QRect(440, 310, 141, 61));
        cargoManagement = new QPushButton(centralWidget);
        cargoManagement->setObjectName(QString::fromUtf8("cargoManagement"));
        cargoManagement->setGeometry(QRect(440, 360, 141, 61));
        addUser = new QPushButton(centralWidget);
        addUser->setObjectName(QString::fromUtf8("addUser"));
        addUser->setGeometry(QRect(440, 410, 141, 51));
        Simulator->setCentralWidget(centralWidget);

        retranslateUi(Simulator);

        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QMainWindow *Simulator)
    {
        Simulator->setWindowTitle(QCoreApplication::translate("Simulator", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Simulator", "<html><head/><body><p><span style=\" font-size:48pt;\">\346\227\240\344\272\272\350\266\205\345\270\202</span></p></body></html>", nullptr));
        Authentication->setText(QCoreApplication::translate("Simulator", "\350\272\253\344\273\275\351\252\214\350\257\201", nullptr));
        productPurchase->setText(QCoreApplication::translate("Simulator", "\345\225\206\345\223\201\351\200\211\350\264\255", nullptr));
        maskDetection->setText(QCoreApplication::translate("Simulator", "\351\230\262\347\226\253\346\243\200\346\265\213", nullptr));
        deal->setText(QCoreApplication::translate("Simulator", "\345\225\206\345\223\201\347\273\223\347\256\227", nullptr));
        purchaseRecord->setText(QCoreApplication::translate("Simulator", "\350\264\255\344\271\260\350\256\260\345\275\225", nullptr));
        cargoManagement->setText(QCoreApplication::translate("Simulator", "\350\277\233\345\207\272\350\264\247\347\256\241\347\220\206", nullptr));
        addUser->setText(QCoreApplication::translate("Simulator", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
