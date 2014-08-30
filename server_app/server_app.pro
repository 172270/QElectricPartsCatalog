#-------------------------------------------------
#
# Project created by QtCreator 2014-08-30T15:54:44
#
#-------------------------------------------------

QT       += widgets network gui sql
TARGET = server_app
TEMPLATE = app

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../server/release/ -lserver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../server/debug/ -lserver
else:unix: LIBS += -L$$OUT_PWD/../lib -lserver

INCLUDEPATH += $$PWD/../server
DEPENDPATH += $$PWD/../server

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/release/libserver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/debug/libserver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/release/server.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/debug/server.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib/libserver.a
