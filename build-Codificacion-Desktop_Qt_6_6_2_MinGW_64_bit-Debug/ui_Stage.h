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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stage
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Stage)
    {
        if (Stage->objectName().isEmpty())
            Stage->setObjectName("Stage");
        Stage->resize(792, 472);
        graphicsView = new QGraphicsView(Stage);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 10, 721, 441));

        retranslateUi(Stage);

        QMetaObject::connectSlotsByName(Stage);
    } // setupUi

    void retranslateUi(QWidget *Stage)
    {
        Stage->setWindowTitle(QCoreApplication::translate("Stage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stage: public Ui_Stage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGE_H
