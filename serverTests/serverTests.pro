#-------------------------------------------------
#
# Project created by QtCreator 2014-07-19T06:53:07
#
#-------------------------------------------------

QT       += network testlib gui


TARGET = tst_servertests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_servertests.cpp \
    main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../protocol/release/ -lprotocol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../protocol/debug/ -lprotocol
else:unix: LIBS += -L$$OUT_PWD/../protocol/ -lprotocol

INCLUDEPATH += ../protocol
DEPENDPATH += ../protocol

LIBS += -lprotobuf

HEADERS += \
    tst_servertests.h
