#-------------------------------------------------
#
# Project created by QtCreator 2014-07-18T19:55:32
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app
LIBS += -lprotobuf-lite

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    adduserdialog.cpp \
    addgroup.cpp \
    addparameter.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    adduserdialog.h \
    addgroup.h \
    addparameter.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    adduserdialog.ui \
    addgroup.ui \
    addparameter.ui

unix:!macx: LIBS += -L$$OUT_PWD/../lib/ -lprotocol

INCLUDEPATH += $$PWD/../protocol
DEPENDPATH += $$PWD/../protocol

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../lib/libprotocol.a
#QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic -march=corei7-avx -pipe -ffast-math -flto
