#-------------------------------------------------
#
# Project created by QtCreator 2016-09-03T19:30:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QR_01
TEMPLATE = app

CONFIG += C++14
LIBS += -lqrencode

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
