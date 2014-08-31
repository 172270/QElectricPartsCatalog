#-------------------------------------------------
#
# Project created by QtCreator 2014-07-19T08:36:48
#
#-------------------------------------------------



PROTOS = stats.proto user.proto

#include(protobuf.pri)

QT       -= gui
QT       += network

TARGET = ../lib/protocol

TEMPLATE = lib

CONFIG += staticlib

DEFINES += PROTOCOL_LIBRARY

SOURCES += protocol.cpp \
    user.pb.cc \
    stats.pb.cc \
    ecatalogsocket.cpp \
    storage.pb.cc

HEADERS += protocol.h\
    user.pb.h \
    stats.pb.h \
    ecatalogsocket.h \
    messagetype.h \
    datastreamsource.h \
    storage.pb.h

OTHER_FILES += \
    user.proto \
    stats.proto \
    protobuf.pri \
    storage.proto

unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -lprotobuf

