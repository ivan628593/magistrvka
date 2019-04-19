#include <QtWidgets>
#include <QtGui>
#include <QApplication>
#include "mainform.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  QApplication::setStyle(QStyleFactory::create("Windows"));

//    QFile styleFile("default.css");
//        styleFile.open(QFile::ReadOnly) ;
//        QString styleSheet = QLatin1String(styleFile.readAll());
//        qApp->setStyleSheet(styleSheet);

  //  QApplication::setPalette(QApplication::style()->standardPalette());
/*    QTranslator translator;
    translator.load("_ru.qm",".");
    a.installTranslator(&translator)*/;

    Mainform w;
   // w.setBackgroundRole(QPalette::Shadow);
    w.showMaximized();
    return a.exec();
}

