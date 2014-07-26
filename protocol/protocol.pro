#-------------------------------------------------
#
# Project created by QtCreator 2014-07-19T08:36:48
#
#-------------------------------------------------

QT       -= gui
QT       += network

TARGET = protocol
TEMPLATE = lib

DEFINES += PROTOCOL_LIBRARY

SOURCES += protocol.cpp \
    user.pb.cc \
    stats.pb.cc \
    ecatalogsocket.cpp

HEADERS += protocol.h\
    user.pb.h \
    msgConstc.h \
    stats.pb.h \
    ecatalogsocket.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -lprotobuf

OTHER_FILES += \
    user.proto \
    stats.proto
