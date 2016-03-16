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
    int i;
        loadPartition("Partition1");
  QPainter painter(this);
  painter.setPen(Qt::black);

  painter.drawLine(10,50, 710, 50);
  painter.drawLine(10,65, 710, 65);
  painter.drawLine(10,80, 710, 80);
  painter.drawLine(10,95, 710, 95);
  painter.drawLine(10,110, 710, 110);

  painter.setBrush(Qt::SolidPattern);

  // essaie des note des musique
  //x1, y1, x2, y2

//  for(i = 1; i <= liseur->getListeNotes().size(); i++) {
  for(i = liseur->getListeNotes().size(); i >= 1; i--) {
//      switch(liseur->getListeNotes().at(i-1)) {
//            case 1:

//            case 3
//      }


      qDebug() << i  << " et "<< liseur->getListeNotes().at(i-1)  << " et "<< 13.2 + (liseur->getListeNotes().at(i-1)*7.4);

      painter.drawEllipse(QRectF(40*i, (5.8 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15));//x, y , width, height
      painter.drawRect( (40*i)+14 ,-14+(7.7*liseur->getListeNotes().at(i-1)) ,1 ,30);

  }
}

