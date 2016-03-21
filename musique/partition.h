#ifndef PARTITION_H
#define PARTITION_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>
#include "monreaderamoi.h"

class Partition : public QWidget
{
    Q_OBJECT

public :

    enum Part {Partition1, Partition2, Partition3};

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
     void resetColors();

     QList<int> getListeNote() const;
     void setListeNote(const QList<int> &value);

     void writelog(int note);


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
