QT += core

TEMPLATE = lib

TARGET = repsettings

DESTDIR = ../build

#INCLUDEPATH += . \
			   
DEFINES += __USE_DLL_REPSETTINGS

#Include file(s)
include(dbrepsettings.pri)
