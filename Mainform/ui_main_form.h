/********************************************************************************
** Form generated from reading UI file 'main_form.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_FORM_H
#define UI_MAIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_form
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *main_form)
    {
        if (main_form->objectName().isEmpty())
            main_form->setObjectName(QStringLiteral("main_form"));
        main_form->resize(1271, 749);
        main_form->setMinimumSize(QSize(800, 590));
        main_form->setAutoFillBackground(true);
        main_form->setAnimated(true);
        main_form->setDocumentMode(false);
        main_form->setTabShape(QTabWidget::Rounded);
        main_form->setDockNestingEnabled(true);
        centralwidget = new QWidget(main_form);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        main_form->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(main_form);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setLayoutDirection(Qt::LeftToRight);
        statusbar->setSizeGripEnabled(true);
        main_form->setStatusBar(statusbar);
        menuBar = new QMenuBar(main_form);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1271, 21));
        main_form->setMenuBar(menuBar);
        toolBar = new QToolBar(main_form);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        main_form->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(main_form);

        QMetaObject::connectSlotsByName(main_form);
    } // setupUi

    void retranslateUi(QMainWindow *main_form)
    {
        main_form->setWindowTitle(QApplication::translate("main_form", "\320\222\320\232\320\220", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("main_form", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_form: public Ui_main_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_FORM_H
