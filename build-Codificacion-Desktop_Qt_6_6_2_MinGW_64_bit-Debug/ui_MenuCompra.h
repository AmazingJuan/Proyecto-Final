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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuCompra
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *MenuCompra)
    {
        if (MenuCompra->objectName().isEmpty())
            MenuCompra->setObjectName("MenuCompra");
        MenuCompra->resize(700, 700);
        graphicsView = new QGraphicsView(MenuCompra);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 700, 700));

        retranslateUi(MenuCompra);

        QMetaObject::connectSlotsByName(MenuCompra);
    } // setupUi

    void retranslateUi(QWidget *MenuCompra)
    {
        MenuCompra->setWindowTitle(QCoreApplication::translate("MenuCompra", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuCompra: public Ui_MenuCompra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCOMPRA_H
