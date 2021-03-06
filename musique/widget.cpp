#include "widget.h"
#include "ui_widget.h"

const int IdRole = Qt::UserRole;

/**
 * @brief constructeur de widget
 *
 * @param parent le widget pere
 */
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowIcon(QPixmap(":icone.png"));
    this->setWindowTitle("Musicodibou");

    this->setMinimumSize(810, 680);
    this->setMaximumSize(810, 680);


    QTabWidget *onglets = new QTabWidget(this);
    onglets->setGeometry(10, 10 ,790, 660); //on declare la taille des 3 fenetres onglets
    cours = new QWidget;
    exercice = new QWidget;
    raccourci = new QWidget;

    //on commence par l'onglet exercice:
    //Création du label
    labelPartition = new QLabel(" Choisir une partition : ");
    labelPartition->setFont(QFont("Sans-serif", 12, QFont::Bold));

    //ComboBox pour les partitions
    boxPartition = new QComboBox;
    boxPartition->addItem("La mélodie du parrain", Partition::Partition1);
    boxPartition->addItem("The world is molli", Partition::Partition2);
    boxPartition->addItem("La marseillaise", Partition::Partition3);

    //checkbox pour afficher ou non les notes sur les touches
    boxAfficheNote = new QCheckBox("Afficher les notes sur le piano");
    boxAfficheNote->setFocusPolicy(Qt::NoFocus);

    //PushBoutton recommencer et retour
    b_restart = new QPushButton("Recommencer", this);
    b_restart->setCursor(Qt::PointingHandCursor);
    b_restart->setFocusPolicy(Qt::NoFocus);
    QPixmap recommencerIcon = QPixmap(":recommencer.png");
    b_restart->setIcon(recommencerIcon);

    b_back1 = new QPushButton("Revenir en arriere", this);
    b_back1->setCursor(Qt::PointingHandCursor);
    b_back1->setFocusPolicy(Qt::NoFocus);
    QPixmap retourIcon = QPixmap(":retour.png");
    b_back1->setIcon(retourIcon);

    //Création du layout des sélection/choix: on va commencer a agencer les objets
    //1er layout pour le choix de partition
    layoutChoix = new QGridLayout;

    layoutChoix->addWidget(labelPartition, 0, 0); //tout en haut de l'onglet
    layoutChoix->addWidget(boxPartition, 0, 1, 1, 2);//en dessous du label

    //2eme layout pour le piano/pour les boutons
    layoutPiano = new QGridLayout;
    layoutPiano->addWidget(boxAfficheNote, 0 ,1, 1, 1);//en dessous de la partition
    layoutPiano->addWidget(b_restart, 0, 3, 1 ,1);//a droite de boxAfficheNote
    layoutPiano->addWidget(b_back1, 0, 2, 1 ,1);//a droite de b_restart
    layoutPiano->addWidget(ui->widget, 1, 1, 1, 3);//tout en bas


    texte = QString("Notes rentrées : ");

    //widget pour afficher l'historique des notes entrées
    widgetNoteTape = new QTextEdit(texte);
    //on veut ecrire en plus gros et lisible
    QFont f("Sans-serif", 12, QFont::Bold);
    widgetNoteTape->setFont(f);

    //on empeche le changement de la taille du widget et l'ecriture
    widgetNoteTape->setMinimumSize(QSize(768,60));
    widgetNoteTape->setMaximumSize(QSize(768,60));
    widgetNoteTape->setReadOnly(true);
    widgetNoteTape->setStyleSheet("background-color: rgb(255, 255, 255)");

    //Création de la partition
    widgetPartition = new QWidget();
    part = new Partition(widgetPartition);
    svg = new QSvgWidget(":clef_sol.svg", widgetPartition);
    svg->resize(60,140); // Retailler l'image
    svg->move(0,8);  //Deplacer l'image
    svg->renderer();


    //Création du layout principal : on rassemble le tout
    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutChoix);
    layoutPrincipal->addWidget(widgetPartition);
    layoutPrincipal->addWidget(widgetNoteTape);
    layoutPrincipal->addLayout(layoutPiano);

    //fin de la creation de l'onglet exercice

    //onglet exercice
    exercice->setLayout(layoutPrincipal);

    //creation de l'onglet cours
    QLayout *layoutTuto = new QVBoxLayout;
    QLabel *labelTuto = new QLabel;
    QPixmap imageTuto = QPixmap(":tutonotes.png");
    labelTuto->setPixmap(imageTuto);
    layoutTuto->addWidget(labelTuto);
    cours->setLayout(layoutTuto);

    //creation de l'onglet raccourcis clavier
    QLayout *layoutRacc = new QVBoxLayout;
    QLabel *labelRacc = new QLabel;
    QPixmap imageRacc = QPixmap(":raccourcit.png");
    labelRacc->setPixmap(imageRacc);
    layoutRacc->addWidget(labelRacc);
    raccourci->setLayout(layoutRacc);

    //fin de la creation des onglets: debut de la connexion des boutons
    //mapper de note et son
    mapper = new QSignalMapper(this);

    //on map toutes les touches du clavier au son correspondant et au raccourci correspondant
    //le mappeur permet d'intercepter le signal d'un bouton et de lui ajouter une valeur
    connect(ui->do_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->do_1->setShortcut(tr("q"));
    mapper->setMapping(ui->do_1, 1);
    connect(ui->re_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->re_1->setShortcut(tr("s"));
    mapper->setMapping(ui->re_1, 2);
    connect(ui->mi_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->mi_1->setShortcut(tr("d"));
    mapper->setMapping(ui->mi_1, 3);
    connect(ui->fa_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->fa_1->setShortcut(tr("f"));
    mapper->setMapping(ui->fa_1, 4);
    connect(ui->sol_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->sol_1->setShortcut(tr("g"));
    mapper->setMapping(ui->sol_1, 5);
    connect(ui->la_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->la_1->setShortcut(tr("h"));
    mapper->setMapping(ui->la_1, 6);
    connect(ui->si_1, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->si_1->setShortcut(tr("j"));
    mapper->setMapping(ui->si_1, 7);
    connect(ui->do_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->do_2->setShortcut(tr("w"));
    mapper->setMapping(ui->do_2, 8);
    connect(ui->re_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->re_2->setShortcut(tr("x"));
    mapper->setMapping(ui->re_2, 9);
    connect(ui->mi_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->mi_2->setShortcut(tr("c"));
    mapper->setMapping(ui->mi_2, 10);
    connect(ui->fa_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->fa_2->setShortcut(tr("v"));
    mapper->setMapping(ui->fa_2, 11);
    connect(ui->sol_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->sol_2->setShortcut(tr("b"));
    mapper->setMapping(ui->sol_2, 12);
    connect(ui->la_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->la_2->setShortcut(tr("n"));
    mapper->setMapping(ui->la_2, 13);
    connect(ui->si_2, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->si_2->setShortcut(tr(","));
    mapper->setMapping(ui->si_2, 14);
    connect(ui->do_3, SIGNAL(clicked()), mapper, SLOT(map()));
    ui->do_3->setShortcut(tr(";"));
    mapper->setMapping(ui->do_3, 15);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));//on relie tout le clavier

    connect(boxPartition, SIGNAL(activated(int)),
            this, SLOT(partChanged()));//on relie le choix de partition a la fonction correspondante
    connect(boxAfficheNote, SIGNAL(toggled(bool)),
            this, SLOT(setAfficheNote(bool)));//on relie la checkbox a la fonction correspondante

    connect(b_restart, SIGNAL(clicked()), this, SLOT(reset()));
    b_restart->setShortcut(tr("r"));//on relie le bouton recommencer a sa fonction et on ajoute un raccourci clavier
    connect(b_back1, SIGNAL(clicked()), this, SLOT(retour_en_arriere()));
    b_back1->setShortcut(Qt::Key_Backspace);//on relie le bouton revenir en arriere a sa fonction et on ajoute un raccourci clavier


    boxAfficheNote->setChecked(false);

    //et enfin on assemble les 3 ongets
    onglets->addTab(exercice, "Entrainement");
    onglets->addTab(cours, "Cours de solfège");
    onglets->addTab(raccourci, "Raccourcis clavier");

}

/**
 * @brief calcule un taux de reussite et l'ecrit dans un string pour un affichage
 *
 *
 * @return QString s un descriptif du resultat
 */
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
    s = s + "Vous avez <b>" + QString::number(reussi) + "</b> bonnes reponses sur <b>" + QString::number(part->getListeNote().size()) + "</b> (les bonnes reponses sont en <span style=' color:#32CD32;'>vert</span>, les mauvaises en <span style=' color:#ff0000;'>rouge</span>).</br> Vous retrouverez vos scores dans le fichier \"resultats.txt\".";
    return s;
}

/**
 * @brief joue le son note et agit en fonction de l'etat de jeu
 * @details la note rentrée est stockée, puis lorsque toutes les notes ont été rentrée on affiche le resultat
 *
 * @param note l'id de la touche sur laquelle l'utilisateur a cliqué
 */
void Widget::handleButton(int note) {
    switch(note) {//on joue le son
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
    //on met a jour l'historique et le log
    add_note_entree(note);
    part->writelog(note);
    vectorNote.push_back(note);

    //dans le cas ou on a rentré 8 notes, fin d'exercice: il faut changer la couleur des notes, afficher l'historique attendu et afficher le popup
    if(vectorNote.size() ==  8 ) {
        part->setResults(vectorNote);

        texte = "Notes rentrées : ";
        widgetNoteTape->setPlainText("Notes rentrées : ");
        set_aff_notes(vectorNote);
        texte = texte + "\nNotes attendues :";
        set_aff_notes(part->getListeNote());

        QMessageBox *message = new QMessageBox(widgetPartition);
        message->setText(calcule_resultat());
        message->addButton( QMessageBox::Ok );
        message->setWindowTitle(tr("Résultat de votre performance"));
        message->exec();

        //fin de l'exo, on reset tout

        texte = "Notes rentrées : ";
        widgetNoteTape->setPlainText("Notes rentrées : ");

        part->resetColors();
        vectorNote.clear();
    }
    part->setAvancement(part->getAvancement()+1);
}


/**
 * @brief ajoute la note entree a l'historique
 *
 * @param note la note rentree
 */
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
            texte = texte + "  Do2";
            break;}
        case 9: {
            texte = texte + "  Ré2";
            break;}
        case 10: {
            texte = texte + "  Mi2";
            break;}
        case 11: {
            texte = texte + "  Fa2";
            break;}
        case 12: {
            texte = texte + " Sol2";
            break;}
        case 13: {
            texte = texte + "  La2";
            break;}
        case 14: {
            texte = texte + "  Si2";
            break;}
        case 15: {
            texte = texte + " Do3";
            break;}
    }
    widgetNoteTape->setPlainText(texte);

}

/**
 * @brief affiche une liste de notes dans l'historique
 *
 * @param liste la liste a afficher
 */
void Widget::set_aff_notes(QList<int> liste) {
    int i;
    for(i = 0; i<liste.size(); i++) {
        add_note_entree(liste.at(i));
    }
}

/**
 * @brief remet l'exercice a debut
 *
 */
void Widget::reset() {
    part->setAvancement(1);
    texte = "Notes rentrées : ";
    widgetNoteTape->setPlainText("Notes rentrées : ");
    vectorNote.clear();

    part->writelog(101);
}

/**
 * @brief retourne d'une note en arriere dans l'exercice
 *
 */
void Widget::retour_en_arriere() {
    if(vectorNote.size() > 0 ) {
//        qDebug() <<"a "  << part->getAvancement();
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

    part->writelog(100);

}


/**
 * @brief change la partition pour celle dans boxPartition
 *
 */
void Widget::partChanged()
{
    Partition::Part parti = Partition::Part(boxPartition->itemData(
                                                    boxPartition->currentIndex(), IdRole).toInt());
    texte = "Notes rentrées : ";
    widgetNoteTape->setPlainText("Notes rentrées : ");
    part->setPart(parti);
    vectorNote.clear();
    part->writelog(103);

}

/**
 * @brief active/desactive l'affichage des notes sur le clavier
 *
 * @param note
 */
void Widget::setAfficheNote(bool note)
{

    part->writelog(102);
    this->note = note;
    if(this->note) {
        ui->do_1->setText("Do1");
        ui->re_1->setText("Ré1");
        ui->mi_1->setText("Mi1");
        ui->fa_1->setText("Fa1");
        ui->sol_1->setText("Sol1");
        ui->la_1->setText("La1");
        ui->si_1->setText("Si1");
        ui->do_2->setText("Do2");
        ui->re_2->setText("Ré2");
        ui->mi_2->setText("Mi2");
        ui->fa_2->setText("Fa2");
        ui->sol_2->setText("Sol2");
        ui->la_2->setText("La2");
        ui->si_2->setText("Si2");
        ui->do_3->setText("Do3");

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
    ui->do_1->setShortcut(tr("q"));
    ui->re_1->setShortcut(tr("s"));
    ui->mi_1->setShortcut(tr("d"));
    ui->fa_1->setShortcut(tr("f"));
    ui->sol_1->setShortcut(tr("g"));
    ui->la_1->setShortcut(tr("h"));
    ui->si_1->setShortcut(tr("j"));
    ui->do_2->setShortcut(tr("w"));
    ui->re_2->setShortcut(tr("x"));
    ui->mi_2->setShortcut(tr("c"));
    ui->fa_2->setShortcut(tr("v"));
    ui->sol_2->setShortcut(tr("b"));
    ui->la_2->setShortcut(tr("n"));
    ui->si_2->setShortcut(tr(","));
    ui->do_3->setShortcut(tr(";"));
    update();
}

/**
 * @brief Destructeur de Widget
 *
 */
Widget::~Widget()
{
    delete ui;
}
