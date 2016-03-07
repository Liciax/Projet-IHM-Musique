#ifndef PARTITION_H
#define PARTITION_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>

class Partition : public QWidget
{
    Q_OBJECT

public :
     Partition(QWidget *parent = 0);
     void paintEvent(QPaintEvent *event);
     QSize minimumSizeHint() const; //Q_DECL_OVERRIDE;
     QSize sizeHint() const; // Q_DECL_OVERRIDE;

};

#endif // PARTITION_H
