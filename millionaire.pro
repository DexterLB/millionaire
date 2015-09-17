#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T20:42:03
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
#include <QSoundEffect> е, но трябва в .pro файла

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = millionaire
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h\
		 question.h
		

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
