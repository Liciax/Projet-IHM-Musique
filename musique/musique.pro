#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T20:06:30
#
#-------------------------------------------------

QT += core gui
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musique
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    partition.cpp

HEADERS  += widget.h \
    partition.h

FORMS    += widget.ui

OTHER_FILES +=

RESOURCES += \
    ressources.qrc
