/********************************************************************************
** Form generated from reading UI file 'MenuCompra.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUCOMPRA_H
#define UI_MENUCOMPRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuCompra
{
public:
    QGraphicsView *graphicsView;
    QPushButton *B_1;
    QPushButton *B_2;
    QPushButton *B_3;
    QPushButton *B_salir;
    QLabel *L_1;
    QLabel *L_2;
    QLabel *L_3;
    QLabel *L_C;

    void setupUi(QWidget *MenuCompra)
    {
        if (MenuCompra->objectName().isEmpty())
            MenuCompra->setObjectName("MenuCompra");
        MenuCompra->resize(700, 700);
        graphicsView = new QGraphicsView(MenuCompra);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 700, 700));
        B_1 = new QPushButton(MenuCompra);
        B_1->setObjectName("B_1");
        B_1->setGeometry(QRect(390, 70, 130, 130));
        B_2 = new QPushButton(MenuCompra);
        B_2->setObjectName("B_2");
        B_2->setGeometry(QRect(390, 241, 130, 130));
        B_3 = new QPushButton(MenuCompra);
        B_3->setObjectName("B_3");
        B_3->setGeometry(QRect(390, 413, 130, 130));
        B_salir = new QPushButton(MenuCompra);
        B_salir->setObjectName("B_salir");
        B_salir->setGeometry(QRect(245, 578, 210, 52));
        L_1 = new QLabel(MenuCompra);
        L_1->setObjectName("L_1");
        L_1->setGeometry(QRect(390, 206, 130, 16));
        L_2 = new QLabel(MenuCompra);
        L_2->setObjectName("L_2");
        L_2->setGeometry(QRect(390, 378, 130, 16));
        L_3 = new QLabel(MenuCompra);
        L_3->setObjectName("L_3");
        L_3->setGeometry(QRect(390, 547, 130, 16));
        L_C = new QLabel(MenuCompra);
        L_C->setObjectName("L_C");
        L_C->setGeometry(QRect(170, 70, 157, 20));

        retranslateUi(MenuCompra);

        QMetaObject::connectSlotsByName(MenuCompra);
    } // setupUi

    void retranslateUi(QWidget *MenuCompra)
    {
        MenuCompra->setWindowTitle(QCoreApplication::translate("MenuCompra", "Form", nullptr));
        B_1->setText(QString());
        B_2->setText(QString());
        B_3->setText(QString());
        B_salir->setText(QString());
        L_1->setText(QCoreApplication::translate("MenuCompra", "ASDSD", nullptr));
        L_2->setText(QCoreApplication::translate("MenuCompra", "ASDADS", nullptr));
        L_3->setText(QCoreApplication::translate("MenuCompra", "ASDADS", nullptr));
        L_C->setText(QCoreApplication::translate("MenuCompra", "ASDASD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuCompra: public Ui_MenuCompra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCOMPRA_H
