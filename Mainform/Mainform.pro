TEMPLATE        = app
TARGET          = kisvka

DESTDIR         = ../build

QT              += widgets gui sql network

DEPENDPATH += ../DBAccess \
              ../DBRepSettings \
              ../DiagnosticModel \
              ../DiagnosticSetting \
              ../DBConnSettingsDialog

include(mainform.pri)


LIBS += -L../build -ldbaccess -lrepsettings  -ldiagnosticsetting -ldiagnosticmodel   -ldbconnsettingsdialog
DEFINES += BUILD_DLL

win32 {

INCLUDEPATH += . \
        ../DBAccess \
        ../DBRepSettings \
        ../DiagnosticModel \
        ../DiagnosticSetting \
        ../DBConnSettingsDialog
}

RESOURCES += \
    resourse_.qrc


