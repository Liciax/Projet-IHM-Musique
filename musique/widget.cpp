#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMinimumSize(420, 500);
    this->setMaximumSize(600, 600);


//    QPalette *palette = new QPalette();
//    palette->setColor(QPalette::Base, QColor(Qt::green));

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


    // creation de la partition
    widgetPartition = new QWidget();
    part = new Partition(widgetPartition);

    QPalette p( widgetPartition->palette() );
    p.setColor( QPalette::Base, Qt::cyan );
   widgetPartition->setPalette( p );

    //Création du layout principale
    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutChoix);
    layoutPrincipal->addWidget(widgetPartition);
    layoutPrincipal->addLayout(layoutPiano);

    this->setLayout(layoutPrincipal);

}


Widget::~Widget()
{
    delete ui;
}
