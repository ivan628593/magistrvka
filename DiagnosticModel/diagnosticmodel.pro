TEMPLATE = lib
TARGET = diagnosticmodel
DESTDIR = ../build

QT += sql widgets

#INCLUDEPATH +=  . \
  #               ../DiagnosticSetting
    #            ../DBAccess \
     #           ../DBRepSettings


#DEPENDPATH  +=  ../DiagnosticSetting
   #             ../DBAccess \
    #            ../DBRepSettings


#LIBS += -L../build -ldiagnosticsetting


DEFINES += __USE_DLL_DIAGNOSTICMODEL

#DEFINES += BUILD_DLL

include(diagnosticmodel.pri)


