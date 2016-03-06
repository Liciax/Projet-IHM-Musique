#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
/*
    QPalette palette;
    palette.setColor(QPalette::Base, QColor(Qt::black));

    ui->diese1->setPalette(palette);
    ui->diese2->setPalette(palette);
    ui->diese3->setPalette(palette);
    ui->diese4->setPalette(palette);
    ui->diese5->setPalette(palette);
*/
    //Création des labels
    labelInstru = new QLabel("Choisir un instrument : ");
    labelPartition = new QLabel("Choisir une partition : ");

    //ComboBox pour les instruments
    boxIntrument = new QComboBox;
    boxIntrument->addItem("Xylophone");
    boxIntrument->addItem("Piano");

    //ComboBox pour les partitions
    boxPartition = new QComboBox;
    boxPartition->addItem("Partition 1");
    boxPartition->addItem("Partition 2");

    //PushBoutton valider et retour
    b_valider = new QPushButton("Valider");
    b_valider->setCursor(Qt::PointingHandCursor);
    b_retour = new QPushButton("Retour");
    b_retour->setCursor(Qt::PointingHandCursor);

    //Création du layout des sélection/choix
    layoutChoix = new QGridLayout;
    layoutChoix->addWidget(labelInstru, 0, 0);
    layoutChoix->addWidget(boxIntrument, 0, 1, 1, 2);
    layoutChoix->addWidget(labelPartition, 1, 0);
    layoutChoix->addWidget(boxPartition, 1, 1 ,1 ,2);
    layoutChoix->addWidget(b_retour, 2, 1);
    layoutChoix->addWidget(b_valider, 2, 2);

    layoutPiano = new QGridLayout;
    layoutPiano->addWidget(ui->widget, 0, 1);

    /*
    layoutPiano->addWidget(ui->do_2, 0, 0);
    layoutPiano->addWidget(ui->re, 0, 1);
    layoutPiano->addWidget(ui->mi, 0, 2);
    layoutPiano->addWidget(ui->fa, 0, 3);
    layoutPiano->addWidget(ui->sol, 0, 4);
    layoutPiano->addWidget(ui->la, 0, 5);
    layoutPiano->addWidget(ui->si, 0, 6);
*/

    //Création du layout principale
    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutChoix);
    layoutPrincipal->addWidget(ui->widget);
    layoutPrincipal->addLayout(layoutPiano);

    this->setLayout(layoutPrincipal);
}

Widget::~Widget()
{
    delete ui;
}
