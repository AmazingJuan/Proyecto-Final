/********************************************************************************
** Form generated from reading UI file 'Menu2.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU2_H
#define UI_MENU2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu2
{
public:
    QGraphicsView *graphicsView;
    QPushButton *B_iniciar;
    QPushButton *B_cargar;
    QPushButton *B_salir;

    void setupUi(QWidget *Menu2)
    {
        if (Menu2->objectName().isEmpty())
            Menu2->setObjectName("Menu2");
        Menu2->resize(700, 700);
        graphicsView = new QGraphicsView(Menu2);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 700, 700));
        B_iniciar = new QPushButton(Menu2);
        B_iniciar->setObjectName("B_iniciar");
        B_iniciar->setGeometry(QRect(150, 30, 75, 24));
        B_cargar = new QPushButton(Menu2);
        B_cargar->setObjectName("B_cargar");
        B_cargar->setGeometry(QRect(280, 30, 75, 24));
        B_salir = new QPushButton(Menu2);
        B_salir->setObjectName("B_salir");
        B_salir->setGeometry(QRect(390, 30, 75, 24));

        retranslateUi(Menu2);

        QMetaObject::connectSlotsByName(Menu2);
    } // setupUi

    void retranslateUi(QWidget *Menu2)
    {
        Menu2->setWindowTitle(QCoreApplication::translate("Menu2", "Form", nullptr));
        B_iniciar->setText(QCoreApplication::translate("Menu2", "iniciar", nullptr));
        B_cargar->setText(QCoreApplication::translate("Menu2", "cargar", nullptr));
        B_salir->setText(QCoreApplication::translate("Menu2", "salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu2: public Ui_Menu2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU2_H
