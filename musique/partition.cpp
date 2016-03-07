#include "partition.h"

Partition::Partition(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

QSize Partition::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize Partition::sizeHint() const
{
    return QSize(400, 100);
}

void Partition::paintEvent(QPaintEvent *event) {

  QPainter painter(this);
  painter.setPen(Qt::black);
  painter.drawLine(10,20, 390, 20);
  painter.drawLine(10,30, 390, 30);
  painter.drawLine(10,40, 390, 40);
  painter.drawLine(10,50, 390, 50);
  painter.drawLine(10,60, 390, 60);

}
