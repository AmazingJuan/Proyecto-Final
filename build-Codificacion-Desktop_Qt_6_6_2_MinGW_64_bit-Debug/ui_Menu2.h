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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu2
{
public:
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QWidget *Menu2)
    {
        if (Menu2->objectName().isEmpty())
            Menu2->setObjectName("Menu2");
        Menu2->resize(400, 300);
        dateTimeEdit = new QDateTimeEdit(Menu2);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(120, 100, 194, 22));

        retranslateUi(Menu2);

        QMetaObject::connectSlotsByName(Menu2);
    } // setupUi

    void retranslateUi(QWidget *Menu2)
    {
        Menu2->setWindowTitle(QCoreApplication::translate("Menu2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu2: public Ui_Menu2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU2_H
