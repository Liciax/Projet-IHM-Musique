#include "widget.h"
#include "ui_widget.h"

const int IdRole = Qt::UserRole;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
//    instru = Piano;

    ui->setupUi(this);

    this->setWindowIcon(QPixmap(":icone.png"));
    this->setWindowTitle("Musicodibou");

    this->setMinimumSize(750, 500);
    this->setMaximumSize(750, 500);

//    QPalette *palette = new QPalette();
//    palette->setColor(QPalette::Base, QColor(Qt::green));

    //Création des labels
    labelPartition = new QLabel("Choisir une partition : ");

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

    layoutChoix->addWidget(labelPartition, 0, 0);
    layoutChoix->addWidget(boxPartition, 0, 1 ,1 ,2);
    layoutChoix->addWidget(b_retour, 1, 1);
    layoutChoix->addWidget(b_valider, 1, 2);

    layoutPiano = new QGridLayout;
    layoutPiano->addWidget(ui->widget, 0, 1);

    //Création de la partition
    widgetPartition = new QWidget();
    part = new Partition(widgetPartition);
    svg = new QSvgWidget(":clef_sol.svg", widgetPartition);
    svg->resize(60,120); // Retailler l'image
    svg->move(5,4);  //Deplacer l'image
    svg->renderer();

//    QPalette p( widgetPartition->palette() );
//    p.setColor( QPalette::Base, Qt::cyan );
//   widgetPartition->setPalette( p );

    //Création du layout principale
    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutChoix);
    layoutPrincipal->addWidget(widgetPartition);
    layoutPrincipal->addLayout(layoutPiano);

//    QSound bells(":ff-040.wav");


//    QSound::play(":ff-040.wav");

    this->setLayout(layoutPrincipal);

    QObject::connect(b_retour, SIGNAL(clicked()), this, SLOT(playSound()));

//    instrumentChange();

}

void Widget::playSound() {
    QSound::play(":ff-040.wav");
//    qDebug( "C Style Debug Message" );

}


//void Widget::instrumentChange() {
//    instru = Instrument(boxIntrument->itemData(
//                            boxIntrument->currentIndex(), IdRole).toInt());
//    this->setInstrument(instru);
//}

Widget::~Widget()
{
    delete ui;
}
