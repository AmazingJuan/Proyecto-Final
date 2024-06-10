/********************************************************************************
** Form generated from reading UI file 'Stage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGE_H
#define UI_STAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stage
{
public:
    QGraphicsView *graphicsView;
    QLabel *L_hp;
    QLabel *L_time;

    void setupUi(QWidget *Stage)
    {
        if (Stage->objectName().isEmpty())
            Stage->setObjectName("Stage");
        Stage->resize(800, 800);
        graphicsView = new QGraphicsView(Stage);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 700, 700));
        L_hp = new QLabel(Stage);
        L_hp->setObjectName("L_hp");
        L_hp->setGeometry(QRect(0, 0, 350, 50));
        L_time = new QLabel(Stage);
        L_time->setObjectName("L_time");
        L_time->setGeometry(QRect(350, 0, 350, 50));

        retranslateUi(Stage);

        QMetaObject::connectSlotsByName(Stage);
    } // setupUi

    void retranslateUi(QWidget *Stage)
    {
        Stage->setWindowTitle(QCoreApplication::translate("Stage", "Form", nullptr));
        L_hp->setText(QString());
        L_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Stage: public Ui_Stage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGE_H
