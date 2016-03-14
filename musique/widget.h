#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>
//#include <QSvgWidget>
#include <QSound>
#include <QString>
#include <QSignalMapper>
#include "partition.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:

    explicit Widget(QWidget *parent = 0);
    ~Widget();

//private slots:
//    void instrumentChange();

public slots:
//     void playSound();
    void handleButton(int note);

private:

    Ui::Widget *ui;
    Partition * part;
    QSignalMapper * mapper;

    QVBoxLayout *layoutPrincipal;
    QGridLayout *layoutChoix;
    QGridLayout *layoutPiano;

    QComboBox *boxPartition;

    QLabel *labelPartition;

    QPushButton *b_valider;
    QPushButton *b_retour;

    QWidget *widgetPartition;

    //QSvgWidget *svg;
};

#endif // WIDGET_H
