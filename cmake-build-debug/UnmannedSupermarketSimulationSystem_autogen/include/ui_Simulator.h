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
    QPushButton *count;
    QPushButton *quit;

    void setupUi(QMainWindow *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->resize(960, 720);
        centralWidget = new QWidget(Simulator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 960, 120));
        Authentication = new QPushButton(centralWidget);
        Authentication->setObjectName(QString::fromUtf8("Authentication"));
        Authentication->setGeometry(QRect(120, 210, 720, 60));
        Authentication->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        productPurchase = new QPushButton(centralWidget);
        productPurchase->setObjectName(QString::fromUtf8("productPurchase"));
        productPurchase->setGeometry(QRect(120, 270, 720, 60));
        productPurchase->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        maskDetection = new QPushButton(centralWidget);
        maskDetection->setObjectName(QString::fromUtf8("maskDetection"));
        maskDetection->setGeometry(QRect(120, 150, 720, 60));
        maskDetection->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        deal = new QPushButton(centralWidget);
        deal->setObjectName(QString::fromUtf8("deal"));
        deal->setGeometry(QRect(120, 330, 720, 60));
        deal->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        purchaseRecord = new QPushButton(centralWidget);
        purchaseRecord->setObjectName(QString::fromUtf8("purchaseRecord"));
        purchaseRecord->setGeometry(QRect(120, 390, 720, 60));
        purchaseRecord->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        cargoManagement = new QPushButton(centralWidget);
        cargoManagement->setObjectName(QString::fromUtf8("cargoManagement"));
        cargoManagement->setGeometry(QRect(120, 450, 720, 60));
        cargoManagement->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        addUser = new QPushButton(centralWidget);
        addUser->setObjectName(QString::fromUtf8("addUser"));
        addUser->setGeometry(QRect(120, 510, 720, 60));
        addUser->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        count = new QPushButton(centralWidget);
        count->setObjectName(QString::fromUtf8("count"));
        count->setGeometry(QRect(120, 570, 720, 60));
        count->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(120, 630, 721, 61));
        quit->setStyleSheet(QString::fromUtf8("font: 34pt \"STKaiti\";"));
        Simulator->setCentralWidget(centralWidget);

        retranslateUi(Simulator);

        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QMainWindow *Simulator)
    {
        Simulator->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("Simulator", "<html><head/><body><p align=\"center\"><span style=\" font-family:'STKaiti'; font-size:96pt; font-weight:700;\">\346\227\240 \344\272\272 \350\266\205 \345\270\202 \346\250\241 \346\213\237 \347\263\273 \347\273\237</span></p></body></html>", nullptr));
        Authentication->setText(QCoreApplication::translate("Simulator", "\350\272\253 \344\273\275 \351\252\214 \350\257\201", nullptr));
        productPurchase->setText(QCoreApplication::translate("Simulator", "\345\225\206 \345\223\201 \351\200\211 \350\264\255", nullptr));
        maskDetection->setText(QCoreApplication::translate("Simulator", "\351\230\262 \347\226\253 \346\243\200 \346\265\213", nullptr));
        deal->setText(QCoreApplication::translate("Simulator", "\345\225\206 \345\223\201 \347\273\223 \347\256\227", nullptr));
        purchaseRecord->setText(QCoreApplication::translate("Simulator", "\350\264\255 \344\271\260 \350\256\260 \345\275\225", nullptr));
        cargoManagement->setText(QCoreApplication::translate("Simulator", "\350\264\247 \347\211\251 \347\256\241 \347\220\206", nullptr));
        addUser->setText(QCoreApplication::translate("Simulator", "\346\267\273 \345\212\240 \347\224\250 \346\210\267", nullptr));
        count->setText(QCoreApplication::translate("Simulator", "\347\203\255 \351\224\200 \345\225\206 \345\223\201", nullptr));
        quit->setText(QCoreApplication::translate("Simulator", "\351\200\200 \345\207\272 \347\263\273 \347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
