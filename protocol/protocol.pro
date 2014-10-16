#-------------------------------------------------
#
# Project created by QtCreator 2014-07-19T08:36:48
#
#-------------------------------------------------

PROTOS = stats.proto user.proto

#include(protobuf.pri)

QT       -= gui
QT       += network core sql

TARGET = ../lib/protocol

TEMPLATE = lib

CONFIG += staticlib c++11

DEFINES += PROTOCOL_LIBRARY

SOURCES += \
    user.pb.cc \
    stats.pb.cc \
    storage.pb.cc \
    message_conteiner.pb.cc \
    group.pb.cc \
    types.pb.cc \
    item.pb.cc \
    package.pb.cc \
    parameters.pb.cc \
    messages/loginrequest.cpp \
    messages/messagescontainer.cpp \
    messages/userregistrationmessage.cpp \
    DB_schema/loginmessage.cpp \
    DB_schema/user.cpp \
    DB_schema/storege.cpp \
    DB_schema/file.cpp \
    DB_schema/group.cpp \
    DB_schema/item.cpp \
    DB_schema/package.cpp \
    DB_schema/parameter.cpp

HEADERS += \
    user.pb.h \
    stats.pb.h \
    messagetype.h \
    datastreamsource.h \
    storage.pb.h \
    message_conteiner.pb.h \
    group.pb.h \
    types.pb.h \
    item.pb.h \
    package.pb.h \
    parameters.pb.h \
    messages/loginrequest.h \
    messages/messagescontainer.h \
    messages/userregistrationmessage.h \
    DB_schema/loginmessage.h \
    DB_schema/user.h \
    DB_schema/storage.h \
    DB_schema/file.h \
    DB_schema/group.h \
    DB_schema/item.h \
    DB_schema/package.h \
    DB_schema/parameter.h

OTHER_FILES += \
    user.proto \
    stats.proto \
    protobuf.pri \
    storage.proto \
    group.proto \
    message_conteiner.proto \
    item.proto \
    types.proto \
    package.proto \
    parameters.proto \
    ekataog.architect \
    schema.sql

unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -lprotobuf

