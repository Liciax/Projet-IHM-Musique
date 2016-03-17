#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QRectF>
#include <QPaintEvent>
#include <QSvgWidget>
#include <QSound>
#include <QVector>
#include <QString>
#include <QSignalMapper>
#include <QMessageBox>
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

public slots:
    void handleButton(int note);
    void partChanged();
    void setAfficheNote(bool note);

private:

    Ui::Widget *ui;
    Partition * part;
    QSignalMapper * mapper;

    QVBoxLayout *layoutPrincipal;
    QGridLayout *layoutChoix;
    QGridLayout *layoutPiano;
    QGridLayout *layoutNoteAffiche;

    QComboBox *boxPartition;
    QCheckBox *boxAfficheNote;
    QLabel *labelPartition;

    QPushButton *b_valider;
    QPushButton *b_retour;

    QWidget *widgetPartition;

    QSvgWidget *svg;
    QVector<int> vectorNote;
    int avancement;
    bool note;

};

#endif // WIDGET_H
