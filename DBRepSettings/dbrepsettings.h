/***********************************************************************
 * Module:  repositorysettings.h
 * Author:  Администратор
 * Modified: 17 мая 2016 г. 14:25:56
 * Purpose: Declaration of the class RepositorySettings
 ***********************************************************************/

#ifndef DBREPSETTINGS_H
#define DBREPSETTINGS_H

#include <QSettings>
#include "config_dbrepsettings.h"

class __EXPORT_REPSETTINGS DBRepSettings : public QSettings
{
public:
    DBRepSettings();
    void setIdDbDriver(int idDbDriver);
    void setDbName(QString dbName);
    void setUserName(QString userName);
    void setPassword(QString password);
    void setHost(QString host);
    void setStoragePath(QString path);
    int getIdDbDriver(void);
    QString getDbName(void);
    QString getUserName(void);
    QString getPassword(void);
    QString getHost(void);
    int repType();
    QString getStoragePath();

    static enum {POSTGRESQL = 1, SQLITE = 0} dbDriver;
private:
    int repType_;
};

#endif // DBREPSETTINGS_H
