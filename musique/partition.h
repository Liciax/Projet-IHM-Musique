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
     QSize minimumSizeHint() const;
     QSize sizeHint() const;

};

#endif // PARTITION_H


// QSvgWidget * svg=new QSvgWidget ("2rightarrow.svg",NomQwidget);
// svg->resize(30,30); // Retailler l'image
// svg->move(115,5);  //Deplacer l'image
// zoomSvg->renderer(); //afficher l'image
