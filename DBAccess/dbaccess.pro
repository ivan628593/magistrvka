TEMPLATE = lib
TARGET = dbaccess
DESTDIR = ../build

QT += core sql

INCLUDEPATH += . \

DEFINES += __USE_DLL_DBACCESS

#Include file(s)
include(dbaccess.pri)
