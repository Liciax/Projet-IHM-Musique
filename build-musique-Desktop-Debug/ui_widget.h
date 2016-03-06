/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QPushButton *mi;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *re;
    QPushButton *do_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(694, 360);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 160, 381, 181));
        mi = new QPushButton(widget);
        mi->setObjectName(QStringLiteral("mi"));
        mi->setGeometry(QRect(120, 20, 50, 150));
        mi->setCursor(QCursor(Qt::PointingHandCursor));
        mi->setFlat(false);
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(220, 20, 50, 150));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_11->setFlat(false);
        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(320, 20, 50, 150));
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_13->setFlat(false);
        re = new QPushButton(widget);
        re->setObjectName(QStringLiteral("re"));
        re->setGeometry(QRect(70, 20, 50, 150));
        re->setCursor(QCursor(Qt::PointingHandCursor));
        re->setFlat(false);
        do_2 = new QPushButton(widget);
        do_2->setObjectName(QStringLiteral("do_2"));
        do_2->setEnabled(true);
        do_2->setGeometry(QRect(20, 20, 50, 150));
        do_2->setCursor(QCursor(Qt::PointingHandCursor));
        do_2->setFlat(false);
        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(270, 20, 50, 150));
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_12->setFlat(false);
        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(170, 20, 50, 150));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_10->setFlat(false);
        mi->raise();
        pushButton_11->raise();
        pushButton_13->raise();
        re->raise();
        do_2->raise();
        pushButton_12->raise();
        pushButton_10->raise();
        mi->raise();
        pushButton_11->raise();
        pushButton_13->raise();
        re->raise();
        do_2->raise();
        pushButton_12->raise();
        pushButton_10->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        mi->setText(QApplication::translate("Widget", "Mi", 0));
        pushButton_11->setText(QApplication::translate("Widget", "Sol", 0));
        pushButton_13->setText(QApplication::translate("Widget", "Si", 0));
        re->setText(QApplication::translate("Widget", "Re", 0));
        do_2->setText(QApplication::translate("Widget", "Do", 0));
        pushButton_12->setText(QApplication::translate("Widget", "La", 0));
        pushButton_10->setText(QApplication::translate("Widget", "Fa", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
