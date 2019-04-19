TEMPLATE = subdirs

CONFIG += ordered

QT   += sql gui widgets

# Directories
SUBDIRS += \
        DBAccess \
        DBRepSettings \
        DBConnSettingsDialog \
        DiagnosticModel\
        DiagnosticSetting\
        Mainform


#INSTALLS += transl
#TRANSLATIONS = calculate_ru.ts
