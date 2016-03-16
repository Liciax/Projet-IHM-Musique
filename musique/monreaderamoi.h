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

    QList<int> getListeNotes() const;
    void setListeNotes(const QList<int> &value);

private:
    QList<int> listeNotes;
};

#endif // MONREADERAMOI_H
