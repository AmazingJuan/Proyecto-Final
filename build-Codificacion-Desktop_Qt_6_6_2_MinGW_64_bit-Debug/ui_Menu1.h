/********************************************************************************
** Form generated from reading UI file 'Menu1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU1_H
#define UI_MENU1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu1
{
public:
    QGraphicsView *graphicsView;
    QPushButton *B_iniciar;
    QPushButton *B_salir;

    void setupUi(QWidget *Menu1)
    {
        if (Menu1->objectName().isEmpty())
            Menu1->setObjectName("Menu1");
        Menu1->resize(700, 700);
        Menu1->setMinimumSize(QSize(700, 700));
        Menu1->setMaximumSize(QSize(700, 700));
        graphicsView = new QGraphicsView(Menu1);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 700, 700));
        B_iniciar = new QPushButton(Menu1);
        B_iniciar->setObjectName("B_iniciar");
        B_iniciar->setGeometry(QRect(160, 170, 75, 24));
        B_salir = new QPushButton(Menu1);
        B_salir->setObjectName("B_salir");
        B_salir->setGeometry(QRect(160, 230, 75, 24));

        retranslateUi(Menu1);

        QMetaObject::connectSlotsByName(Menu1);
    } // setupUi

    void retranslateUi(QWidget *Menu1)
    {
        Menu1->setWindowTitle(QCoreApplication::translate("Menu1", "Form", nullptr));
        B_iniciar->setText(QCoreApplication::translate("Menu1", "iniciar", nullptr));
        B_salir->setText(QCoreApplication::translate("Menu1", "salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu1: public Ui_Menu1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU1_H
