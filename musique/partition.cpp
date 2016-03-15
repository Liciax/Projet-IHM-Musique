#include "partition.h"

Partition::Partition(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

QSize Partition::minimumSizeHint() const
{
    return QSize(200, 180);
}

QSize Partition::sizeHint() const
{
    return QSize(750, 180);
}

void Partition::paintEvent(QPaintEvent *event) {

  QPainter painter(this);
  painter.setPen(Qt::black);

  painter.drawLine(10,30, 710, 30);
  painter.drawLine(10,45, 710, 45);
  painter.drawLine(10,60, 710, 60);
  painter.drawLine(10,75, 710, 75);
  painter.drawLine(10,90, 710, 90);

  painter.setBrush(Qt::SolidPattern);

  // essaie des note des musique
  //x1, y1, x2, y2
  painter.drawEllipse(QRectF(20, 30, 15, 15)); //mi je crois
  //x, y , width, height
  painter.drawRect(34,10, 1, 30);

  painter.drawEllipse(QRectF(60, 45, 15, 15));
  painter.drawRect(74,20, 1, 30);
}
