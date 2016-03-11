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
    this->setMaximumSize(800, 600);

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



   // QSound bells("mysounds/bells.wav");

    this->setLayout(layoutPrincipal);

//    connect(boxIntrument, SIGNAL(activated(int)),
//            this, SLOT(instrumentChange()));

//    instrumentChange();

}

//void Widget::setInstrument(Instrument inst) {
//    this->instru = inst;
//    update();
//}

//void Widget::instrumentChange() {
//    instru = Instrument(boxIntrument->itemData(
//                            boxIntrument->currentIndex(), IdRole).toInt());
//    this->setInstrument(instru);
//}

Widget::~Widget()
{
    delete ui;
}
