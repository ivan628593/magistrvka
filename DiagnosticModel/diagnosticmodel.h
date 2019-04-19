#ifndef DIAGNOSTICMODEL_H
#define DIAGNOSTICMODEL_H

#include <QtWidgets>
#include <QMenu>
#include <QStandardItemModel>
#include <QSqlRelationalTableModel>
#include "config_diagnosticmodel.h"


class __EXPORT_DIAGNOSTICMODEL DiagnosticModel: public QObject
{
    Q_OBJECT

public:

    explicit DiagnosticModel(QObject *parent = 0);

    QStandardItemModel* getParamList(int);
    QStandardItemModel* getStateList(int);
    QStandardItemModel* getSubSystemList(int);

    void addModelMatrix(int id_sys);
    void delModelMatrix(int id_sys);
    void delModelStateRow(int id_state);
    void addCheckingDB(int, int, QString, int, double, double, double, double);
    void addResultCheckingDB(int, int, QString, double, double, double, int);
    void addNewSystem(int,QString);
    bool getCheckresult(int id_sys);

    void deleteTableName(QString,QString,int);
    void fillComboboxSubsystem(QComboBox *box, int id_system);

    int getIdParametres(int);
    int getIdSub(int);

};

#endif
