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

  //(27.6 * (i*7.4))


  for(i = 1; i <= liseur->getListeNotes().size(); i++) {
      painter.drawEllipse(QRectF(40*i, (13.2 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15));//x, y , width, height
      painter.drawRect( (40*i)+14 ,-14+(7.7*liseur->getListeNotes().at(i-1)) ,1 ,30);

  }

/*
  i++;

  painter.drawEllipse(QRectF(40*i, (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15));
  painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

  i++;

  painter.drawEllipse(QRectF( 40*i , (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15));
  painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

    i++;

    painter.drawEllipse(QRectF(40*i, (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15)); //mi je crois
    //x, y , width, height
    painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

    i++;

    painter.drawEllipse(QRectF(40*i, (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15)); //mi je crois
    //x, y , width, height
    painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

    i++;

    painter.drawEllipse(QRectF(40*i, (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15)); //mi je crois
    //x, y , width, height
    painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

    i++;

    painter.drawEllipse(QRectF(40*i, (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15)); //mi je crois
    //x, y , width, height
    painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

    i++;

    painter.drawEllipse(QRectF(40*i, (27.6 + (liseur->getListeNotes().at(i-1)*7.4)) , 15, 15)); //mi je crois
    //x, y , width, height
    painter.drawRect( (40*i)+14 ,2.86+(8.21*liseur->getListeNotes().at(i-1)) ,1 ,30);

    i++;*/

//  painter.drawEllipse(QRectF(40*i, 35, 15, 15));//x, y , width, height
//  painter.drawRect( (40*i)+14 ,10 ,1 ,30);

//  i++;

//  painter.drawEllipse(QRectF(40*i, 42, 15, 15));
//  painter.drawRect( (40*i)+14 ,20 ,1 ,30);

//  i++;

//  painter.drawEllipse(QRectF( 40*i , 50, 15, 15));
//  painter.drawRect( (40*i)+14 ,28 ,1 ,30);

//    i++;

//    painter.drawEllipse(QRectF(40*i, 57, 15, 15)); //mi je crois
//    //x, y , width, height
//    painter.drawRect( (40*i)+14 ,36 ,1 ,30);

//    i++;

//    painter.drawEllipse(QRectF(40*i, 65, 15, 15)); //mi je crois
//    //x, y , width, height
//    painter.drawRect( (40*i)+14 ,44 ,1 ,30);

//    i++;

//    painter.drawEllipse(QRectF(40*i, 72, 15, 15)); //mi je crois
//    //x, y , width, height
//    painter.drawRect( (40*i)+14 ,52 ,1 ,30);

//    i++;

//    painter.drawEllipse(QRectF(40*i, 79, 15, 15)); //mi je crois
//    //x, y , width, height
//    painter.drawRect( (40*i)+14 ,60 ,1 ,30);

//    i++;

//  painter.drawEllipse(QRectF(40*i, 30, 15, 15)); //mi je crois
//  //x, y , width, height
//  painter.drawRect( (40*i)+14 ,10 ,1 ,30);
//    i++;
//  painter.drawEllipse(QRectF( 40*i , 45, 15, 15));

//  //painter.drawEllipse(QRectF(60, 45, 15, 15));
//  painter.drawRect( (40*i)+14 ,20 ,1 ,30);
}

