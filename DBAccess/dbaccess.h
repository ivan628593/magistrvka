#ifndef DBACCESS_H
#define DBACCESS_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <Qtsql/QSqlRecord>
#include <QMap>
#include <QVariant>
#include "config_dbaccess.h"


class __EXPORT_DBACCESS DBAccess : public QObject
{
    Q_OBJECT
public:
    explicit DBAccess(QObject *parent = 0);
    //SQLite
    bool createConnection(QString dbDriver, QString dbFilePath);
    bool closeConnection();
    bool testConnection();
    bool isConnected();
    QString getErrorMessage();
    bool setPragmaFK();

    static int generateUnique();
    bool getNameR();
signals:

public slots:

private:

    QSqlDatabase db;
    QString errorMessage;
};

#endif // DBACCESS_H
