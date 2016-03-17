#include "partition.h"

Partition::Partition(QWidget *parent)
    : QWidget(parent)
{
    part = Partition1;
    int i;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    liseur = new monReaderAMoi();
    avancement = 1;
    for(i = 0; i < 8; i++)
    {
        results.push_back(QColor(0,0,0,255));
    }
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
    this->avancement = 1;
    update();
}

QList<QColor> Partition::getResults() const
{
    return results;
}

void Partition::setResults(const QList<int> &value)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        if(value.at(i) == listeNote.at(i)){
            results[i] = (QColor(50,205,50,255));
        } else {
            results[i] = (QColor(Qt::red));
        }
        qDebug() << "lol : " << results.at(i).name();
    }
    update();

}

int Partition::getAvancement() const
{
    return avancement;
}

void Partition::setAvancement(int value)
{
    avancement = value;
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

    QPen pn;
    pn.setWidth(2);
    pn.setColor(QColor(0,0,0,255));
    painter.setPen(pn);

  painter.drawLine(10,50, 750, 50);
  painter.drawLine(10,65, 750, 65);
  painter.drawLine(10,80, 750, 80);
  painter.drawLine(10,95, 750, 95);
  painter.drawLine(10,110, 750, 110);

  painter.setBrush(Qt::SolidPattern);


  //x1, y1, x2, y2
    listeNote = liseur->getListeNotes();
    for(i = 1; i <= liseur->getListeNotes().size(); i++) {

      switch(liseur->getListeNotes().at(i-1)) {

            case 1:
                painter.drawLine((80*i)-10,((liseur->getListeNotes().at(i-1)*(-7.4))+118.4) +14, (80*i)+25, ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)+14);
                break;

            case 13:
                painter.drawLine((80*i)-10,((liseur->getListeNotes().at(i-1)*(-7.4))+118.4) +14, (80*i)+25, ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)+14);
                break;

            case 15:
                painter.drawLine((80*i)-10,((liseur->getListeNotes().at(i-1)*(-7.4))+118.4) +14, (80*i)+25, ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)+14);
                break;
      }

      pn.setColor(results.at(i-1));
      painter.setPen(pn);
      painter.drawEllipse(QRectF(80*i, (5.8 + ((liseur->getListeNotes().at(i-1)*(-7.4))+118.4)) , 15, 15));//x, y , width, height
      painter.drawRect( (80*i)+14 ,104.4+(-7.7*liseur->getListeNotes().at(i-1)) ,1 ,30);

    }

    //if(avancement > 1) {
        pn.setColor(QColor(0,0,255,255));
        painter.setPen(pn);
        painter.drawLine((80*avancement)+8 , 10 , (80*avancement)+8 , 160 );
        if(avancement==8) {
            avancement=0;
        }
    //}

}

