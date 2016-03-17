#include "widget.h"
#include "ui_widget.h"

const int IdRole = Qt::UserRole;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    k = 0;
    ui->setupUi(this);

    this->setWindowIcon(QPixmap(":icone.png"));
    this->setWindowTitle("Musicodibou");

    this->setMinimumSize(790, 650);
    this->setMaximumSize(790, 650);


    //Création des labels
    labelPartition = new QLabel(" <b> Choisir une partition :</b>");
    labelPartition->setStyleSheet("background-color: rgb(255, 255, 255)");

    //ComboBox pour les partitions
    boxPartition = new QComboBox;
    boxPartition->addItem("La mélodie du parrain", Partition::Partition1);
    boxPartition->addItem("The world is molli", Partition::Partition2);

    boxAfficheNote = new QCheckBox("Afficher les notes sur le piano");
    boxAfficheNote->setFocusPolicy(Qt::NoFocus);

    //PushBoutton valider et retour
    b_restart = new QPushButton("Recommencer", this);
    b_restart->setCursor(Qt::PointingHandCursor);

//    b_retour = new QPushButton("Retour", this);
//    b_retour->setCursor(Qt::PointingHandCursor);

    //Création du layout des sélection/choix
    layoutChoix = new QGridLayout;

    layoutChoix->addWidget(labelPartition, 0, 0);
    layoutChoix->addWidget(boxPartition, 0, 1, 1, 2);
    //layoutChoix->addWidget(b_retour, 1, 1);
    layoutChoix->addWidget(b_restart, 1, 2);

    layoutPiano = new QGridLayout;
    layoutPiano->addWidget(ui->widget, 0, 1);

    texte = QString("Vos notes : ");

    widgetNoteTape = new QTextEdit(texte);
    widgetNoteTape->setMinimumSize(QSize(768,60));
    widgetNoteTape->setMaximumSize(QSize(768,60));

//    resultatTape = new QLabel(texte, widgetNoteTape );
//    resultatTape->move(120,150);
//    resultatTape->setText("toto");

//    layoutNoteTape = new QGridLayout;
//    layoutNoteTape->addWidget(widgetNoteTape,0,0);

    //Création de la partition
    widgetPartition = new QWidget();
    part = new Partition(widgetPartition);
    svg = new QSvgWidget(":clef_sol.svg", widgetPartition);
    svg->resize(60,140); // Retailler l'image
    svg->move(0,8);  //Deplacer l'image
    svg->renderer();


    //Création du layout principale
    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutChoix);
    layoutPrincipal->addWidget(widgetPartition);
    //layoutPrincipal->addLayout(layoutNoteTape);
    layoutPrincipal->addWidget(widgetNoteTape);
    widgetNoteTape->setStyleSheet("background-color: rgb(255, 255, 255)");
    layoutPrincipal->addWidget(boxAfficheNote);
    layoutPrincipal->addLayout(layoutPiano);

    this->setLayout(layoutPrincipal);

    //mapper de note et son
    mapper = new QSignalMapper(this);

    connect(ui->do_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->do_1, 1);
    connect(ui->re_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->re_1, 2);
    connect(ui->mi_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->mi_1, 3);
    connect(ui->fa_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->fa_1, 4);
    connect(ui->sol_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->sol_1, 5);
    connect(ui->la_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->la_1, 6);
    connect(ui->si_1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->si_1, 7);
    connect(ui->do_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->do_2, 8);
    connect(ui->re_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->re_2, 9);
    connect(ui->mi_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->mi_2, 10);
    connect(ui->fa_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->fa_2, 11);
    connect(ui->sol_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->sol_2, 12);
    connect(ui->la_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->la_2, 13);
    connect(ui->si_2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->si_2, 14);
    connect(ui->do_3, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->do_3, 15);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));

    connect(boxPartition, SIGNAL(activated(int)),
            this, SLOT(partChanged()));
    connect(boxAfficheNote, SIGNAL(toggled(bool)),
            this, SLOT(setAfficheNote(bool)));

    connect(b_restart, SIGNAL(clicked()), this, SLOT(reset()));

    //QObject::connect(b_retour, SIGNAL(clicked()), this, SLOT(playSound()));
    boxAfficheNote->setChecked(false);

}

void Widget::handleButton(int note) {
    switch(note) {
        case 1: {
            QSound::play("../musique/son/doM.wav");
            //QLabel * label_do = new QLabel("Do", widgetNoteTape);
            texte = texte + " Do";

            break;}
        case 2: {
            QSound::play("../musique/son/reM.wav");
            //QLabel * label_re = new QLabel("Ré", widgetNoteTape);
            texte = texte + " Ré";
            break;}
        case 3: {
            QSound::play("../musique/son/miM.wav");
            //QLabel * label_mi = new QLabel("Mi", widgetNoteTape);
            texte = texte + " Mi";
            break;}
        case 4: {
            QSound::play("../musique/son/faM.wav");
            //QLabel * label_fa = new QLabel("Fa", widgetNoteTape);
            texte = texte + " Fa";
            break;}
        case 5: {
            QSound::play("../musique/son/solM.wav");
            //QLabel * label_sol = new QLabel("Sol",widgetNoteTape);
            texte = texte + " Sol";
            break;}
        case 6: {
            QSound::play("../musique/son/laM.wav");
            //QLabel * label_la = new QLabel("La",widgetNoteTape);
            texte = texte + " La";
            break;}
        case 7: {
            QSound::play("../musique/son/siM.wav");
            //QLabel * label_si = new QLabel("Si",widgetNoteTape);
            texte = texte + " Si";
            break;}
        case 8: {
            QSound::play("../musique/son/dom.wav");
            //QLabel * label_do2 = new QLabel("Do",widgetNoteTape);
            texte = texte + " Do";
            break;}
        case 9: {
            QSound::play("../musique/son/rem.wav");
            //QLabel * label_re2 = new QLabel("Ré",widgetNoteTape);
            texte = texte + " Ré";
            break;}
        case 10: {
            QSound::play("../musique/son/mim.wav");
            //QLabel * label_mi2 = new QLabel("Mi",widgetNoteTape);
            texte = texte + " Mi";
            break;}
        case 11: {
            QSound::play("../musique/son/fam.wav");
            //QLabel * label_fa2 = new QLabel("Fa",widgetNoteTape);
            texte = texte + " Fa";
            break;}
        case 12: {
            QSound::play("../musique/son/solm.wav");
            //QLabel * label_sol2 = new QLabel("Sol",widgetNoteTape);
            texte = texte + " Sol";
            break;}
        case 13: {
            QSound::play("../musique/son/lam.wav");
            //QLabel * label_la2 = new QLabel("La",widgetNoteTape);
            texte = texte + " La";
            break;}
        case 14: {
            //QSound::play("../musique/son/o.wav");
            QSound::play("../musique/son/sim.wav");
            //QLabel * label_si2 = new QLabel("Si",widgetNoteTape);
            texte = texte + " Si";
            break;}
        case 15: {
            QSound::play("../musique/son/do3.wav");
            //QLabel * label_do3 = new QLabel("Do",widgetNoteTape);
            texte = texte + " Do";
            break;}
    }


//    layoutNoteTape->addWidget(widgetNoteTape, 0, k);
//    k++;
//    texte.replace(0,texte.size(), temp);
    widgetNoteTape->setPlainText(texte);

//    qDebug() << "a:" << resultatTape->text();

    vectorNote.push_back(note);
    if(vectorNote.size() ==  8 ) {
        part->setResults(vectorNote);

        QMessageBox::information(
            this,
            tr("Résultat de votre performance"),
            tr("An information message.") );

        part->resetColors();

        vectorNote.clear();

        //fin de la partition, affich et log
    }
    part->setAvancement(part->getAvancement()+1);


}

void Widget::reset() {
    part->setAvancement(1);
    vectorNote.clear();
}


void Widget::partChanged()
{
    Partition::Part parti = Partition::Part(boxPartition->itemData(
                                                    boxPartition->currentIndex(), IdRole).toInt());
    part->setPart(parti);
    vectorNote.clear();

}

void Widget::setAfficheNote(bool note)
{
    this->note = note;
    if(this->note) {
        ui->do_1->setText("Do");
        ui->re_1->setText("Ré");
        ui->mi_1->setText("Mi");
        ui->fa_1->setText("Fa");
        ui->sol_1->setText("Sol");
        ui->la_1->setText("La");
        ui->si_1->setText("Si");
        ui->do_2->setText("Do");
        ui->re_2->setText("Ré");
        ui->mi_2->setText("Mi");
        ui->fa_2->setText("Fa");
        ui->sol_2->setText("Sol");
        ui->la_2->setText("La");
        ui->si_2->setText("Si");
        ui->do_3->setText("Do");

    } else {
        ui->do_1->setText("");
        ui->re_1->setText("");
        ui->mi_1->setText("");
        ui->fa_1->setText("");
        ui->sol_1->setText("");
        ui->la_1->setText("");
        ui->si_1->setText("");
        ui->do_2->setText("");
        ui->re_2->setText("");
        ui->mi_2->setText("");
        ui->fa_2->setText("");
        ui->sol_2->setText("");
        ui->la_2->setText("");
        ui->si_2->setText("");
        ui->do_3->setText("");
    }
    update();
}

Widget::~Widget()
{
    delete ui;
}
