#include "monreaderamoi.h"

/**
 * @brief Constructeur de monReaderAMoi
 *
 */
monReaderAMoi::monReaderAMoi()
{
}



/**
 * @brief recupere, pour chaque element dans root ayant comme nom de balise tag, la valeur de l'attribut att
 *
 * @param root
 * @param tag
 * @param att
 */
void monReaderAMoi::retrievElements(QDomElement root, QString tag, QString att) {
    listeNotes.clear();
    QDomNodeList nodes = root.elementsByTagName(tag);

    //qDebug() << "# nodes = " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            //qDebug() << e.attribute(att);
            listeNotes.append(e.attribute(att).toInt());
        }
    }
}

/**
 * @brief lis un fichier et remplis la liste des notes
 *
 * @param s le nom du fichier a lire
 * @return int 0 si ok, -1 si erreur
 */
int monReaderAMoi::lireFichier(QString s) {
    // cree un document pour lire de l'xml
    QDomDocument document;

    QString fich = "../musique/" + s + ".xml";

    // ouvre le fichier en ecriture
    QFile file(fich);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";
        return -1;
    }
    else
    {
        // chargement
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";
            return -1;
        }
        file.close();
    }

    // recuperation de l'element root
    QDomElement root = document.firstChildElement();

    retrievElements(root, "Note", "Code");

    return 0;
}

/**
 * @brief getteur
 *
 * @return QList<int>
 */
QList<int> monReaderAMoi::getListeNotes() const
{
    return listeNotes;
}

/**
 * @brief setteur
 *
 * @param value
 */
void monReaderAMoi::setListeNotes(const QList<int> &value)
{
    listeNotes = value;
}
