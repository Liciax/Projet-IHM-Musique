#include "partition.h"

Partition::Partition(QWidget *parent)
    : QWidget(parent)
{
    part = Partition1;

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
    return QSize(800, 180);
}

void Partition::setPart(Part part)
{
    this->part = part;
    update();
}

void Partition::loadPartition(QString s) {
    liseur->lireFichier(s);
}

void Partition::paintEvent(QPaintEvent * /* event */) {
    int i;
    switch(part) {
    case Partition1:
        loadPartition("Partition1");
        break;
    case Partition2:
        loadPartition("Partition2");
        break;
    }

  QPainter painter(this);
  painter.setPen(Qt::black);

  painter.drawLine(10,50, 750, 50);
  painter.drawLine(10,65, 750, 65);
  painter.drawLine(10,80, 750, 80);
  painter.drawLine(10,95, 750, 95);
  painter.drawLine(10,110, 750, 110);

  painter.setBrush(Qt::SolidPattern);

  // essaie des note des musique
  //x1, y1, x2, y2

    for(i = 1; i <= liseur->getListeNotes().size(); i++) {
//  for(i = liseur->getListeNotes().size(); i >= 1; i--) {

      switch(liseur->getListeNotes().at(i-1)) {

            case 1:
                painter.drawLine((80*i)-10,((liseur->getListeNotes().at(i-1)*(-7.4))+118.4) +14, (80*i)+25, ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)+14);
                break;

            case 3:
                painter.drawLine((80*i)-10,((liseur->getListeNotes().at(i-1)*(-7.4))+118.4) +14, (80*i)+25, ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)+14);
                break;

            case 5:
                painter.drawLine((80*i)-10,((liseur->getListeNotes().at(i-1)*(-7.4))+118.4) +14, (80*i)+25, ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)+14);
                break;
      }

      painter.drawEllipse(QRectF(80*i, (5.8 + ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)) , 15, 15));//x, y , width, height
      painter.drawRect( (80*i)+14 ,104.4+(-7.7*liseur->getListeNotes().at(i-1)) ,1 ,30);

  }
}

