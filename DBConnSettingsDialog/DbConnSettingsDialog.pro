QT += core widgets sql

TEMPLATE = lib

TARGET = dbconnsettingsdialog

DESTDIR = ../build

DEPENDPATH += ../DBRepSettings \
              ../DBAccess \
              ../DiagnosticSetting \


INCLUDEPATH += ../DBRepSettings \
               ../DBAccess \
               ../DiagnosticSetting \


LIBS += -L../build -lrepsettings -ldbaccess

DEFINES += __USE_DLL_DBCONNSETTINGSDIALOG

#Include file(s)
include(dbconnsettingsdialog.pri)




