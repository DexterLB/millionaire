QT          += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = millionaire
TEMPLATE = app


SOURCES     += main.cpp mainwindow.cpp
HEADERS     += mainwindow.h question.h

FORMS       += mainwindow.ui

RESOURCES   += resources.qrc
