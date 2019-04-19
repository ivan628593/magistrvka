TEMPLATE = lib
TARGET = diagnosticsetting
DESTDIR = ../build

QT += sql widgets gui

INCLUDEPATH +=  ../DiagnosticModel \
                ../DBAccess \
                ../DBRepSettings \


DEPENDPATH  +=  ../DBAccess \
                ../DBRepSettings \
                ../DiagnosticModel

LIBS += -L../build  -ldbaccess -lrepsettings -ldiagnosticmodel

DEFINES += __USE_DLL_DIAGNOSTICSETTING

#DEFINES += BUILD_DLL

include(diagnosticsetting.pri)



