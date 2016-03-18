#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QRectF>
#include <QPaintEvent>
#include <QSvgWidget>
#include <QSound>
#include <QList>
#include <QTextEdit>
#include <QString>
#include <QSignalMapper>
#include <QMessageBox>
#include "partition.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:

    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QString calcule_resultat();

public slots:
    void handleButton(int note);
    void partChanged();
    void setAfficheNote(bool note);
    void reset();
    void retour_en_arriere();

    void add_note_entree(int note);
    void set_aff_notes(QList<int> liste);

private:

    Ui::Widget *ui;
    Partition * part;
    QSignalMapper * mapper;

    QVBoxLayout *layoutPrincipal;
    QGridLayout *layoutChoix;
    QGridLayout *layoutPiano;

    QComboBox *boxPartition;
    QCheckBox *boxAfficheNote;
    QLabel *labelPartition;

    QPushButton *b_restart;
    QPushButton *b_back1;

    QWidget *widgetPartition;
    QTextEdit *widgetNoteTape;

    QString texte;
    QFont font;

    QSvgWidget *svg;
    QList<int> vectorNote;
    int avancement;
    bool note;

};

#endif // WIDGET_H
