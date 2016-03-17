#ifndef PARTITION_H
#define PARTITION_H

#include <iostream>
#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>
#include "monreaderamoi.h"

class Partition : public QWidget
{
    Q_OBJECT

public :

    enum Part {Partition1, Partition2};

     Partition(QWidget *parent = 0);
     void paintEvent(QPaintEvent *event);
     QSize minimumSizeHint() const;
     QSize sizeHint() const;
     void loadPartition(QString s);
     void drawAvancement(int avancement);

     int getAvancement() const;
     void setAvancement(int value);

     QList<QColor> getResults() const;
     void setResults(const QList<int> &value);

public slots:
     void setPart(Part part);

private:
     Part part;
     QList<int> listeNote;
     monReaderAMoi *liseur;
     int avancement;
     QList<QColor> results;

};

#endif // PARTITION_H


// QSvgWidget * svg=new QSvgWidget ("2rightarrow.svg",NomQwidget);
// svg->resize(30,30); // Retailler l'image
// svg->move(115,5);  //Deplacer l'image
// zoomSvg->renderer(); //afficher l'image
