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
    return QSize(200, 220);
}

QSize Partition::sizeHint() const
{
    return QSize(800, 220);
}

void Partition::setPart(Part part)
{
    this->part = part;
    this->avancement = 1;
    update();
}
QList<int> Partition::getListeNote() const
{
    return listeNote;
}

void Partition::setListeNote(const QList<int> &value)
{
    listeNote = value;
}


QList<QColor> Partition::getResults() const
{
    return results;
}

void Partition::setResults(const QList<int> &value)
{
    int i;
    int reussi = 0;
    for(i = 0; i < 8; i++)
    {
        if(value.at(i) == listeNote.at(i)){
            reussi=reussi+1;
            results[i] = (QColor(50,205,50,255));
        } else {
            results[i] = (QColor(Qt::red));
        }

    }
    QFile file("resultats.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text))
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QDateTime now = QDateTime::currentDateTime();
        QTextStream out(&file);
        QString s;
        switch(part) {
        case Partition1:
            s=("Partition1");
            break;
        case Partition2:
            s=("Partition2");
            break;
        }
        i = (reussi*100)/8;
        out << "[" << now.toString("le dddd d MMMM yyyy, hh:mm") << "], partition: " << s << " , votre taut de reussite: " << i<< "%\n";
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

void Partition::resetColors() {
    int i;
    for(i = 0; i < 8; i++)
    {
        results[i] = QColor(0,0,0,255);
    }
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
    painter.setRenderHint(QPainter::Antialiasing);

  painter.drawLine(10,50, 750, 50);
  painter.drawLine(10,65, 750, 65);
  painter.drawLine(10,80, 750, 80);
  painter.drawLine(10,95, 750, 95);
  painter.drawLine(10,110, 750, 110);

  QBrush brush;
  brush.setColor(Qt::black);
  brush.setStyle(Qt::SolidPattern);
  painter.setBrush(brush);


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

      brush.setColor(results.at(i-1));
      painter.setBrush(brush);

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

void Partition::writelog(int bouton) {
    QString boutonTapee;
    switch(bouton) {
        case 1: {
            boutonTapee = "  Do1";
            break;}
        case 2: {
            boutonTapee = "  Ré1";
            break;}
        case 3: {
            boutonTapee = "  Mi1";
            break;}
        case 4: {
            boutonTapee = "  Fa1";
            break;}
        case 5: {
            boutonTapee = " Sol1";
            break;}
        case 6: {
            boutonTapee = "  La1";
            break;}
        case 7: {
            boutonTapee = "  Si1";
            break;}
        case 8: {
            boutonTapee = "  DoM";
            break;}
        case 9: {
            boutonTapee = "  RéM";
            break;}
        case 10: {
            boutonTapee = "  MiM";
            break;}
        case 11: {
            boutonTapee = "  FaM";
            break;}
        case 12: {
            boutonTapee = " SolM";
            break;}
        case 13: {
            boutonTapee = "  LaM";
            break;}
        case 14: {
            boutonTapee = "  SiM";
            break;}
        case 15: {
            boutonTapee = " DoMM";
            break;}
        case 100: {
            boutonTapee = " retour";
            break;}
        case 101: {
            boutonTapee = " recommencer";
            break;}
        case 102: {
            boutonTapee = " cachenotes";
            break;}
        case 103: {
            boutonTapee = " changepart";
            break;}
    }
    QDateTime dayoflog = QDateTime::currentDateTime();
    QFile file(dayoflog.toString("logddMMyy") + ".txt");
        if(!file.open(QIODevice::Append | QIODevice::Text))
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
            QTextStream out(&file);
            QString s;
            switch(part) {
            case Partition1:
                s=("Partition1");
                break;
            case Partition2:
                s=("Partition2");
                break;
            }
            out << dayoflog.toString("[hh:mm:ss:zzz]") << ", partition: " << s << ", touche: " << boutonTapee << "\n";

}

