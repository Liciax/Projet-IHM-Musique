#include "monreaderamoi.h"

/**
 * @brief Constructeur de monReaderAMoi
 *
 */
monReaderAMoi::monReaderAMoi()
{
}



/**
 * @brief
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
 * @brief
 *
 * @param s
 * @return int
 */
int monReaderAMoi::lireFichier(QString s) {
    // Create a document to write XML
    QDomDocument document;

    QString fich = "../musique/" + s + ".xml";

    // Open a file for reading
    QFile file(fich);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";
        return -1;
    }
    else
    {
        // loading
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";
            return -1;
        }
        file.close();
    }

    // Getting root element
    QDomElement root = document.firstChildElement();

    // retrievelements(QDomElement root, QString tag, QString att)
    retrievElements(root, "Note", "Code");

    //qDebug() << "Reading finished";
    return 0;
}
/**
 * @brief
 *
 * @return QList<int>
 */
QList<int> monReaderAMoi::getListeNotes() const
{
    return listeNotes;
}

/**
 * @brief
 *
 * @param value
 */
void monReaderAMoi::setListeNotes(const QList<int> &value)
{
    listeNotes = value;
}
