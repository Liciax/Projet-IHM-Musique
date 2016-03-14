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
    b_valider = new QPushButton("Valider", this);
    b_valider->setCursor(Qt::PointingHandCursor);
    b_retour = new QPushButton("Retour", this);
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
    /*svg = new QSvgWidget(":clef_sol.svg", widgetPartition);
    svg->resize(60,120); // Retailler l'image
    svg->move(5,4);  //Deplacer l'image
    svg->renderer();*/

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


    mapper = new QSignalMapper(this);

    connect(ui->do_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->do_1, 1); // Number to be passed in the slot

    connect(ui->re_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->re_1, 2); // Number to be passed in the slot

    connect(ui->mi_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->mi_1, 3); // Number to be passed in the slot

    connect(ui->fa_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->fa_1, 4); // Number to be passed in the slot

    connect(ui->sol_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->sol_1, 5); // Number to be passed in the slot

    connect(ui->la_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->la_1, 6); // Number to be passed in the slot

    connect(ui->si_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->si_1, 7); // Number to be passed in the slot

    connect(ui->do_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->do_2, 8); // Number to be passed in the slot

    connect(ui->re_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->re_2, 9); // Number to be passed in the slot

    connect(ui->mi_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->mi_2, 10); // Number to be passed in the slot

    connect(ui->fa_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->fa_2, 11); // Number to be passed in the slot

    connect(ui->sol_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->sol_2, 12); // Number to be passed in the slot

    connect(ui->la_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->la_2, 13); // Number to be passed in the slot

    connect(ui->si_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->si_2, 14); // Number to be passed in the slot

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));


    //QObject::connect(b_retour, SIGNAL(clicked()), this, SLOT(playSound()));

//    instrumentChange();

}

void Widget::handleButton(int note) {
    switch(note) {
        case 1: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/doM.wav");
            break;
        }
        case 2: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/reM.wav");
            break;
        }
        case 3: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/miM.wav");
            break;
        }
        case 4: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/faM.wav");
            break;
        }
        case 5: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/solM.wav");
            break;
        }
        case 6: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/laM.wav");
            break;
        }
        case 7: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/siM.wav");
            break;
        }
        case 8: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/dom.wav");
            break;
        }
        case 9: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/rem.wav");
            break;}
        case 10: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/mim.wav");
            break;}
        case 11: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/fam.wav");
            break;}
        case 12: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/solm.wav");
            break;}
        case 13: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/lam.wav");
            break;}
        case 14: {
            QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/son/sim.wav");
            break;}

    }

}


//void Widget::playSound() {
//   QSound::play("/comptes/E127854X/M1_Alma/IHM/Projet-IHM-Musique/musique/ff-040.wav");
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
