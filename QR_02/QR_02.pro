#-------------------------------------------------
#
# Project created by QtCreator 2016-09-03T21:23:02
#
#-------------------------------------------------

QT       += core gui svg network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QR_02
TEMPLATE = app

CONFIG += C++14

SOURCES += main.cpp\
        mainwindow.cpp \
    QrCode.cpp \
    QrSegment.cpp \
    BitBuffer.cpp

HEADERS  += mainwindow.h \
    QrCode.hpp \
    QrSegment.hpp \
    BitBuffer.hpp

FORMS    += mainwindow.ui
