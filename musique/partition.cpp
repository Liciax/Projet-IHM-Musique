#include "partition.h"

Partition::Partition(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    liseur = new monReaderAMoi();
}

QSize Partition::minimumSizeHint() const
{
    return QSize(200, 180);
}

QSize Partition::sizeHint() const
{
    return QSize(750, 180);
}

void Partition::loadPartition(QString s) {
    liseur->lireFichier(s);
}

void Partition::paintEvent(QPaintEvent *event) {

        loadPartition("Partition1");
  QPainter painter(this);
  painter.setPen(Qt::black);
  painter.drawLine(10,30, 710, 30);
  painter.drawLine(10,45, 710, 45);
  painter.drawLine(10,60, 710, 60);
  painter.drawLine(10,75, 710, 75);
  painter.drawLine(10,90, 710, 90);

}

