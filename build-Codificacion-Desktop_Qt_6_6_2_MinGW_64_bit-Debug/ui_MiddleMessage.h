/********************************************************************************
** Form generated from reading UI file 'MiddleMessage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDDLEMESSAGE_H
#define UI_MIDDLEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiddleMessage
{
public:
    QGraphicsView *graphicsView;
    QLabel *L_message;

    void setupUi(QWidget *MiddleMessage)
    {
        if (MiddleMessage->objectName().isEmpty())
            MiddleMessage->setObjectName("MiddleMessage");
        MiddleMessage->resize(600, 700);
        graphicsView = new QGraphicsView(MiddleMessage);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 700, 700));
        L_message = new QLabel(MiddleMessage);
        L_message->setObjectName("L_message");
        L_message->setGeometry(QRect(0, 0, 600, 700));

        retranslateUi(MiddleMessage);

        QMetaObject::connectSlotsByName(MiddleMessage);
    } // setupUi

    void retranslateUi(QWidget *MiddleMessage)
    {
        MiddleMessage->setWindowTitle(QCoreApplication::translate("MiddleMessage", "Form", nullptr));
        L_message->setText(QCoreApplication::translate("MiddleMessage", "<html><head/><body><p><span style=\" color:#ffffff;\">TEXT</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiddleMessage: public Ui_MiddleMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDDLEMESSAGE_H
