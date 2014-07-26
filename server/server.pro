#-------------------------------------------------
#
# Project created by QtCreator 2014-07-18T19:48:12
#
#-------------------------------------------------

QT       += core network sql

QT       -= gui

TARGET = server
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qcatalogserver.cpp \
    qcatalogserverthread.cpp \
    loginmessagehandler.cpp

HEADERS += \
    qcatalogserver.h \
    qcatalogserverthread.h \
    loginmessagehandler.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../protocol/release/ -lprotocol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../protocol/debug/ -lprotocol
else:unix: LIBS += -L$$OUT_PWD/../protocol/ -lprotocol

INCLUDEPATH += ../protocol
DEPENDPATH += ../protocol

LIBS += -lprotobuf
