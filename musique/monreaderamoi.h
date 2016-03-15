#ifndef MONREADERAMOI_H
#define MONREADERAMOI_H

#include <QList>
#include <QString>
#include <QtXml>

class monReaderAMoi
{
public:
    monReaderAMoi();
    void retrievElements(QDomElement root, QString tag, QString att);
    int lireFichier(QString s);


private:
    QList<int> listeNotes;
};

#endif // MONREADERAMOI_H
