#-------------------------------------------------
#
# Project created by QtCreator 2014-07-18T19:48:12
#
#-------------------------------------------------

QT       += core network sql websockets

TARGET = ../lib/server
CONFIG   += console c++11 staticlib

TEMPLATE = lib

SOURCES += main.cpp \
    qcatalogserver.cpp \
    qcatalogserverthread.cpp \
    loginmessagehandler.cpp \
    pginterface.cpp \
    registerusermessagehandler.cpp \
    dbcreator.cpp \
    qcatalogserverworker.cpp \
    workercache.cpp \
    logoutmessagehandler.cpp \
    groupsmessagehandler.cpp \
    parametershandler.cpp

HEADERS += \
    qcatalogserver.h \
    qcatalogserverthread.h \
    loginmessagehandler.h \
    pginterface.h \
    registerusermessagehandler.h \
    dbcreator.h \
    qcatalogserverworker.h \
    workercache.h \
    logoutmessagehandler.h \
    groupsmessagehandler.h \
    parametershandler.h

LIBS += -lprotobuf-lite

OTHER_FILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../protocol/release/ -lprotocol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../protocol/debug/ -lprotocol
else:unix: LIBS += -L$$OUT_PWD/../lib/ -lprotocol

INCLUDEPATH += $$PWD/../protocol
DEPENDPATH += $$PWD/../protocol

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../protocol/release/libprotocol.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../protocol/debug/libprotocol.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../protocol/release/protocol.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../protocol/debug/protocol.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib/libprotocol.a

#QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic -march=corei7-avx -pipe -ffast-math -flto
