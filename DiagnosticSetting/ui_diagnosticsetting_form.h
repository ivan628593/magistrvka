/********************************************************************************
** Form generated from reading UI file 'diagnosticsetting_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSTICSETTING_FORM_H
#define UI_DIAGNOSTICSETTING_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiagnosticSetting_form
{
public:
    QGridLayout *gridLayout_6;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout_24;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTreeView *systemtreeView;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QTableView *tableViewParam;
    QFrame *line_2;
    QToolButton *toolButtonAddParam;
    QFrame *line_3;
    QToolButton *toolButtonDelParam;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QFrame *line_5;
    QLabel *label_2;
    QLabel *label_nameSystem;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_21;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_6;
    QGridLayout *gridLayout_23;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *DiagnosticSetting_form)
    {
        if (DiagnosticSetting_form->objectName().isEmpty())
            DiagnosticSetting_form->setObjectName(QLatin1String("DiagnosticSetting_form"));
        DiagnosticSetting_form->resize(1280, 823);
        gridLayout_6 = new QGridLayout(DiagnosticSetting_form);
        gridLayout_6->setObjectName(QLatin1String("gridLayout_6"));
        splitter = new QSplitter(DiagnosticSetting_form);
        splitter->setObjectName(QLatin1String("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QLatin1String("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_24 = new QGridLayout(frame);
        gridLayout_24->setObjectName(QLatin1String("gridLayout_24"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QLatin1String("gridLayout_10"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QLatin1String("gridLayout_4"));
        label = new QLabel(frame);
        label->setObjectName(QLatin1String("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_4, 0, 0, 1, 1);

        systemtreeView = new QTreeView(frame);
        systemtreeView->setObjectName(QLatin1String("systemtreeView"));
        systemtreeView->setFont(font);
        systemtreeView->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);"));
        systemtreeView->setFrameShape(QFrame::Box);
        systemtreeView->setFrameShadow(QFrame::Plain);
        systemtreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        systemtreeView->setDragEnabled(false);
        systemtreeView->setDragDropMode(QAbstractItemView::NoDragDrop);
        systemtreeView->setAlternatingRowColors(false);
        systemtreeView->setSelectionMode(QAbstractItemView::ContiguousSelection);
        systemtreeView->setSelectionBehavior(QAbstractItemView::SelectRows);
        systemtreeView->setRootIsDecorated(true);
        systemtreeView->header()->setVisible(false);

        gridLayout_10->addWidget(systemtreeView, 1, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_10, 0, 0, 1, 1);

        splitter->addWidget(frame);

        gridLayout_6->addWidget(splitter, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QLatin1String("gridLayout_5"));
        groupBox_2 = new QGroupBox(DiagnosticSetting_form);
        groupBox_2->setObjectName(QLatin1String("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QLatin1String("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QLatin1String("gridLayout_2"));
        tableViewParam = new QTableView(groupBox_2);
        tableViewParam->setObjectName(QLatin1String("tableViewParam"));
        tableViewParam->setFrameShape(QFrame::Box);
        tableViewParam->setFrameShadow(QFrame::Plain);
        tableViewParam->setEditTriggers(QAbstractItemView::DoubleClicked);
        tableViewParam->setTabKeyNavigation(false);
        tableViewParam->setProperty("showDropIndicator", QVariant(false));
        tableViewParam->setDragDropOverwriteMode(false);
        tableViewParam->setAlternatingRowColors(true);
        tableViewParam->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableViewParam->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewParam->setTextElideMode(Qt::ElideMiddle);
        tableViewParam->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableViewParam->setGridStyle(Qt::SolidLine);
        tableViewParam->setWordWrap(false);
        tableViewParam->setCornerButtonEnabled(false);
        tableViewParam->horizontalHeader()->setHighlightSections(false);
        tableViewParam->horizontalHeader()->setMinimumSectionSize(9);
        tableViewParam->horizontalHeader()->setStretchLastSection(false);
        tableViewParam->verticalHeader()->setVisible(false);
        tableViewParam->verticalHeader()->setDefaultSectionSize(20);
        tableViewParam->verticalHeader()->setHighlightSections(false);
        tableViewParam->verticalHeader()->setMinimumSectionSize(20);
        tableViewParam->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(tableViewParam, 2, 1, 4, 1);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QLatin1String("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 1, 0, 1, 2);

        toolButtonAddParam = new QToolButton(groupBox_2);
        toolButtonAddParam->setObjectName(QLatin1String("toolButtonAddParam"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButtonAddParam->sizePolicy().hasHeightForWidth());
        toolButtonAddParam->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QLatin1String(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonAddParam->setIcon(icon);
        toolButtonAddParam->setIconSize(QSize(32, 32));
        toolButtonAddParam->setAutoRaise(true);

        gridLayout_2->addWidget(toolButtonAddParam, 2, 0, 1, 1);

        line_3 = new QFrame(groupBox_2);
        line_3->setObjectName(QLatin1String("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 3, 0, 1, 1);

        toolButtonDelParam = new QToolButton(groupBox_2);
        toolButtonDelParam->setObjectName(QLatin1String("toolButtonDelParam"));
        sizePolicy1.setHeightForWidth(toolButtonDelParam->sizePolicy().hasHeightForWidth());
        toolButtonDelParam->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QLatin1String(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonDelParam->setIcon(icon1);
        toolButtonDelParam->setIconSize(QSize(32, 32));
        toolButtonDelParam->setAutoRaise(true);

        gridLayout_2->addWidget(toolButtonDelParam, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QLatin1String("horizontalLayout"));
        line_5 = new QFrame(groupBox_2);
        line_5->setObjectName(QLatin1String("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QLatin1String("label_2"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        label_nameSystem = new QLabel(groupBox_2);
        label_nameSystem->setObjectName(QLatin1String("label_nameSystem"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_nameSystem->setFont(font2);
        label_nameSystem->setTextFormat(Qt::AutoText);
        label_nameSystem->setWordWrap(true);

        horizontalLayout->addWidget(label_nameSystem);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line = new QFrame(groupBox_2);
        line->setObjectName(QLatin1String("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(DiagnosticSetting_form);
        groupBox_9->setObjectName(QLatin1String("groupBox_9"));
        gridLayout = new QGridLayout(groupBox_9);
        gridLayout->setObjectName(QLatin1String("gridLayout"));
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QLatin1String("gridLayout_21"));

        gridLayout->addLayout(gridLayout_21, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QLatin1String("horizontalLayout_2"));
        frame_6 = new QFrame(groupBox_9);
        frame_6->setObjectName(QLatin1String("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Sunken);
        gridLayout_23 = new QGridLayout(frame_6);
        gridLayout_23->setObjectName(QLatin1String("gridLayout_23"));
        label_3 = new QLabel(frame_6);
        label_3->setObjectName(QLatin1String("label_3"));
        QFont font3;
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_3->setStyleSheet(QLatin1String("color: rgb(56, 177, 19);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_23->addWidget(label_3, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(frame_6);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_9, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(528, 2, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);


        retranslateUi(DiagnosticSetting_form);

        QMetaObject::connectSlotsByName(DiagnosticSetting_form);
    } // setupUi

    void retranslateUi(QWidget *DiagnosticSetting_form)
    {
        DiagnosticSetting_form->setWindowTitle(QApplication::translate("DiagnosticSetting_form", "Form", nullptr));
#ifndef QT_NO_TOOLTIP
        DiagnosticSetting_form->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("DiagnosticSetting_form", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", nullptr));
        groupBox_2->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        toolButtonAddParam->setToolTip(QApplication::translate("DiagnosticSetting_form", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonAddParam->setText(QApplication::translate("DiagnosticSetting_form", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonDelParam->setToolTip(QApplication::translate("DiagnosticSetting_form", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonDelParam->setText(QApplication::translate("DiagnosticSetting_form", "...", nullptr));
        label_2->setText(QApplication::translate("DiagnosticSetting_form", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\270\321\201\321\202\320\265\320\274\321\213:", nullptr));
        label_nameSystem->setText(QString());
        groupBox_9->setTitle(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DiagnosticSetting_form: public Ui_DiagnosticSetting_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICSETTING_FORM_H
