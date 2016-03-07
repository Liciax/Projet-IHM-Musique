/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

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
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(408, 208);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 381, 181));
        mi = new QPushButton(widget);
        mi->setObjectName(QString::fromUtf8("mi"));
        mi->setGeometry(QRect(120, 20, 50, 150));
        mi->setCursor(QCursor(Qt::PointingHandCursor));
        mi->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        mi->setFlat(false);
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(220, 20, 50, 150));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_11->setFlat(false);
        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(320, 20, 50, 150));
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_13->setFlat(false);
        re = new QPushButton(widget);
        re->setObjectName(QString::fromUtf8("re"));
        re->setGeometry(QRect(70, 20, 50, 150));
        re->setCursor(QCursor(Qt::PointingHandCursor));
        re->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        re->setFlat(false);
        do_2 = new QPushButton(widget);
        do_2->setObjectName(QString::fromUtf8("do_2"));
        do_2->setEnabled(true);
        do_2->setGeometry(QRect(20, 20, 50, 150));
        do_2->setCursor(QCursor(Qt::PointingHandCursor));
        do_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        do_2->setFlat(false);
        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(270, 20, 50, 150));
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_12->setFlat(false);
        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(170, 20, 50, 150));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_10->setFlat(false);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        mi->setText(QApplication::translate("Widget", "Mi", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("Widget", "Sol", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("Widget", "Si", 0, QApplication::UnicodeUTF8));
        re->setText(QApplication::translate("Widget", "Re", 0, QApplication::UnicodeUTF8));
        do_2->setText(QApplication::translate("Widget", "Do", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("Widget", "La", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Widget", "Fa", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
