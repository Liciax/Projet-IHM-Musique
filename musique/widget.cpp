#include "widget.h"
#include "ui_widget.h"

const int IdRole = Qt::UserRole;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowIcon(QPixmap(":icone.png"));
    this->setWindowTitle("Musicodibou");

    this->setMinimumSize(790, 650);
    this->setMaximumSize(790, 550);


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
    b_restart->setIcon(QPixmap(":restart.png"));

    b_back1 = new QPushButton("Revenir en arriere", this);
    b_back1->setCursor(Qt::PointingHandCursor);

    //Création du layout des sélection/choix
    layoutChoix = new QGridLayout;

    layoutChoix->addWidget(labelPartition, 0, 0);
    layoutChoix->addWidget(boxPartition, 0, 1, 1, 2);
    //layoutChoix->addWidget(b_restart, 1, 2);

    layoutPiano = new QGridLayout;
    layoutPiano->addWidget(boxAfficheNote, 0 ,1, 1, 1);
    layoutPiano->addWidget(b_restart, 0, 3, 1 ,1);
    layoutPiano->addWidget(b_back1, 0, 2, 1 ,1);
    layoutPiano->addWidget(ui->widget, 1, 1, 1, 3);

    texte = QString("Notes rentrées : ");

    widgetNoteTape = new QTextEdit(texte);
    //font = new QFont();
    //font.setPixelSize(24);
    //widgetNoteTape->setFont(font);
    widgetNoteTape->setMinimumSize(QSize(768,60));
    widgetNoteTape->setMaximumSize(QSize(768,60));
    widgetNoteTape->setReadOnly(true);

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
    //layoutPrincipal->addWidget(boxAfficheNote);
    layoutPrincipal->addLayout(layoutPiano);

    this->setLayout(layoutPrincipal);

    //mapper de note et son
    mapper = new QSignalMapper(this);


    connect(ui->do_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->do_1->setShortcut(tr("&"));
    mapper->setMapping(ui->do_1, 1);
    connect(ui->re_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->re_1->setShortcut(tr("é"));
    mapper->setMapping(ui->re_1, 2);
    connect(ui->mi_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->mi_1->setShortcut(tr("\""));
    mapper->setMapping(ui->mi_1, 3);
    connect(ui->fa_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->fa_1->setShortcut(tr("'"));
    mapper->setMapping(ui->fa_1, 4);
    connect(ui->sol_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->sol_1->setShortcut(tr("("));
    mapper->setMapping(ui->sol_1, 5);
    connect(ui->la_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->la_1->setShortcut(tr("-"));
    mapper->setMapping(ui->la_1, 6);
    connect(ui->si_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->si_1->setShortcut(tr("è"));
    mapper->setMapping(ui->si_1, 7);
    connect(ui->do_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->do_2->setShortcut(tr("_"));
    mapper->setMapping(ui->do_2, 8);
    connect(ui->re_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->re_2->setShortcut(tr("ç"));
    mapper->setMapping(ui->re_2, 9);
    connect(ui->mi_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->mi_2->setShortcut(tr("à"));
    mapper->setMapping(ui->mi_2, 10);
    connect(ui->fa_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->fa_2->setShortcut(tr(")"));
    mapper->setMapping(ui->fa_2, 11);
    connect(ui->sol_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->sol_2->setShortcut(tr("="));
    mapper->setMapping(ui->sol_2, 12);
    connect(ui->la_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->la_2->setShortcut(tr("7"));
    mapper->setMapping(ui->la_2, 13);
    connect(ui->si_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->si_2->setShortcut(tr("8"));
    mapper->setMapping(ui->si_2, 14);
    connect(ui->do_3, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->do_3->setShortcut(tr("9"));
    mapper->setMapping(ui->do_3, 15);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));

    connect(boxPartition, SIGNAL(activated(int)),
            this, SLOT(partChanged()));
    connect(boxAfficheNote, SIGNAL(toggled(bool)),
            this, SLOT(setAfficheNote(bool)));

    connect(b_restart, SIGNAL(clicked()), this, SLOT(reset()));
    b_restart->setShortcut(tr("r"));
    connect(b_back1, SIGNAL(clicked()), this, SLOT(retour_en_arriere()));
    b_back1->setShortcut(tr("t"));

    //QObject::connect(b_retour, SIGNAL(clicked()), this, SLOT(playSound()));
    boxAfficheNote->setChecked(false);

}

QString Widget::calcule_resultat() {
    int i;
    int reussi = 0;
    for(i = 0; i < 8; i++)
    {
        if(vectorNote.at(i) == part->getListeNote().at(i)){
            reussi=reussi+1;
        }

    }
    QString s;
    s = s + "vous avez " + QString::number(reussi) + " bonnes reponses sur " + QString::number(part->getListeNote().size()) + " (les bonnes reponses sont en <span style=' color:#32CD32;'>vert</span>, les mauvaises en <span style=' color:#ff0000;'>rouge</span>).\n Vous retrouverez vos scores dans le fichier logs.txt.";
    return s;
}

void Widget::handleButton(int note) {
    switch(note) {
        case 1: {
            QSound::play("../musique/son/doM.wav");
            break;}
        case 2: {
            QSound::play("../musique/son/reM.wav");
            break;}
        case 3: {
            QSound::play("../musique/son/miM.wav");
            break;}
        case 4: {
            QSound::play("../musique/son/faM.wav");
            break;}
        case 5: {
            QSound::play("../musique/son/solM.wav");
            break;}
        case 6: {
            QSound::play("../musique/son/laM.wav");
            break;}
        case 7: {
            QSound::play("../musique/son/siM.wav");
            break;}
        case 8: {
            QSound::play("../musique/son/dom.wav");
            break;}
        case 9: {
            QSound::play("../musique/son/rem.wav");
            break;}
        case 10: {
            QSound::play("../musique/son/mim.wav");
            break;}
        case 11: {
            QSound::play("../musique/son/fam.wav");
            break;}
        case 12: {
            QSound::play("../musique/son/solm.wav");
            break;}
        case 13: {
            QSound::play("../musique/son/lam.wav");
            break;}
        case 14: {
            QSound::play("../musique/son/sim.wav");
            break;}
        case 15: {
            QSound::play("../musique/son/do3.wav");
            break;}
    }
    add_note_entree(note);



    widgetNoteTape->setPlainText(texte);

    vectorNote.push_back(note);
    if(vectorNote.size() ==  8 ) {
        part->setResults(vectorNote);

        texte = "Notes rentrées : ";
        widgetNoteTape->setPlainText("Notes rentrées : ");
        set_aff_notes(vectorNote);
        texte = texte + "\nNotes attendues :";
        set_aff_notes(part->getListeNote());

        QMessageBox::information(
            this,
            tr("Résultat de votre performance"),calcule_resultat(),
                    QMessageBox::Ok);

        texte = "Notes rentrées : ";
        widgetNoteTape->setPlainText("Notes rentrées : ");

        part->resetColors();
        vectorNote.clear();
    }
    part->setAvancement(part->getAvancement()+1);
}

/*
 *
 *
 *     QFile file("hiddenlogs.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text))
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QDateTime now = QDateTime::currentDateTime();
        QTextStream out(&file);
        QString s;
        switch(part) {
        case Partition1:
            s=("Partition1");
            break;
        case Partition2:
            s=("Partition2");
            break;
        }
        i = (reussi*100)/8;
        out << "[" << now.toString("[hh:mm:ss:zzz") << "], partition: " << s << ", touche: " << note;
 *
 *
 *
 *
 *
 *
 * /

void Widget::add_note_entree(int note) {

    switch(note) {
        case 1: {
            texte = texte + "  Do1";
            break;}
        case 2: {
            texte = texte + "  Ré1";
            break;}
        case 3: {
            texte = texte + "  Mi1";
            break;}
        case 4: {
            texte = texte + "  Fa1";
            break;}
        case 5: {
            texte = texte + " Sol1";
            break;}
        case 6: {
            texte = texte + "  La1";
            break;}
        case 7: {
            texte = texte + "  Si1";
            break;}
        case 8: {
            texte = texte + "  DoM";
            break;}
        case 9: {
            texte = texte + "  RéM";
            break;}
        case 10: {
            texte = texte + "  MiM";
            break;}
        case 11: {
            texte = texte + "  FaM";
            break;}
        case 12: {
            texte = texte + " SolM";
            break;}
        case 13: {
            texte = texte + "  LaM";
            break;}
        case 14: {
            texte = texte + "  SiM";
            break;}
        case 15: {
            texte = texte + " DoMM";
            break;}
    }
    widgetNoteTape->setPlainText(texte);

}

void Widget::set_aff_notes(QList<int> liste) {
    int i;
    for(i = 0; i<liste.size(); i++) {
        add_note_entree(liste.at(i));
    }
}

void Widget::reset() {
    part->setAvancement(1);
    texte = "Notes rentrées : ";
    widgetNoteTape->setPlainText("Notes rentrées : ");
    vectorNote.clear();
}

void Widget::retour_en_arriere() {
    if(vectorNote.size() > 0 ) {
        qDebug() <<"a "  << part->getAvancement();
        if(part->getAvancement() == 0) {
            part->setAvancement(7);
        } else {
            part->setAvancement(part->getAvancement()-1);
        }
        vectorNote.pop_back();
        texte = "Notes rentrées : ";
        widgetNoteTape->setPlainText("Notes rentrées : ");
        set_aff_notes(vectorNote);
    }

}


void Widget::partChanged()
{
    Partition::Part parti = Partition::Part(boxPartition->itemData(
                                                    boxPartition->currentIndex(), IdRole).toInt());
    texte = "Notes rentrées : ";
    widgetNoteTape->setPlainText("Notes rentrées : ");
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
    ui->do_1->setShortcut(tr("&"));
    ui->re_1->setShortcut(tr("é"));
    ui->mi_1->setShortcut(tr("\""));
    ui->fa_1->setShortcut(tr("'"));
    ui->sol_1->setShortcut(tr("("));
    ui->la_1->setShortcut(tr("-"));
    ui->si_1->setShortcut(tr("è"));
    ui->do_2->setShortcut(tr("_"));
    ui->re_2->setShortcut(tr("ç"));
    ui->mi_2->setShortcut(tr("à"));
    ui->fa_2->setShortcut(tr(")"));
    ui->la_2->setShortcut(tr("7"));
    ui->si_2->setShortcut(tr("8"));
    ui->do_3->setShortcut(tr("9"));
    update();
}

Widget::~Widget()
{
    delete ui;
}
